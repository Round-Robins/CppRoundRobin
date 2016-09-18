#include "RoundRobin.h"

using namespace CppRoundRobin;

RoundRobin::RoundRobin(int schedulerPeriod)
{
	this->schedulerPeriod = schedulerPeriod;
	isTimerFired = false;
}

bool RoundRobin::AddTask(std::shared_ptr<RoundRobinTask> task)
{
	if (task.get()->Period() >= schedulerPeriod)
	{
		Tasks.push_back(RoundRobinTaskHooks(task));
		return true;
	}

	return false;
}

void RoundRobin::Run(void) {
	taskTimer.Start(this);
	// Never plan to leave this loop unless there is a problem
	try {
		for (;;) {
			if (isTimerFired) {
				isTimerFired = false;
				for (auto &task : Tasks)
				{
					task.IncrementCounter();

					if (task.Counter() >= task.TaskPeriod() / schedulerPeriod) {
						task.ResetCounter();
						task.RunTask();
					}
				}
			}
			else {
				// This is considered the idle task, haven't decided how to handle this yet for user implementation
			}
		}
	}
	catch (...) {
		taskTimer.End();
		throw;
	}
}

void RoundRobin::TimerFired(void)
{
	this->isTimerFired = true;
}

RoundRobin::RoundRobinTaskHooks::RoundRobinTaskHooks(std::shared_ptr<RoundRobinTask> task)
{
	this->task = task;
	counter = static_cast<int>(0);
}

RoundRobin::RoundRobinTimer::RoundRobinTimer()
{
	hTimerQueue = nullptr;
	hTimer = nullptr;
}

RoundRobin::RoundRobinTimer::~RoundRobinTimer()
{
}

void CALLBACK TimerRoutine(PVOID lpParam, BOOLEAN TimerOrWaitFired)
{
	RoundRobin* robin = static_cast<RoundRobin*>(lpParam);

	robin->TimerFired();
}

void RoundRobin::RoundRobinTimer::Start(RoundRobin* robin)
{
	hTimerQueue = CreateTimerQueue();
	CreateTimerQueueTimer(&hTimer, hTimerQueue, (WAITORTIMERCALLBACK)TimerRoutine, robin, robin->GetPeriod(), robin->GetPeriod(), 0);
}

void RoundRobin::RoundRobinTimer::End()
{
	DeleteTimerQueue(hTimerQueue);
}