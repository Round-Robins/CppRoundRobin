#include "RoundRobin.h"

using namespace CppRoundRobin;

RoundRobin::RoundRobin(int schedulerPeriod)
{
    this->schedulerPeriod = schedulerPeriod;
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

bool RoundRobin::Run(void) {
    // Never plan to leave this loop unless there is a problem
    for (;;) {
        if (isTimerFired) {
            isTimerFired = false;
            for each (RoundRobinTaskHooks task in Tasks)
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
    return false;
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