//
// Created by lucas on 8/17/2016.
//

#include "RoundRobin.h"

using namespace CppRoundRobin;

bool RoundRobin::AddTask(std::shared_ptr<RoundRobinTask> task)
{
    Tasks.push_back(RoundRobinTaskHooks(task));
    return true;
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
    return true;
}

void RoundRobin::TimerFired(void)
{
    this->isTimerFired = true;
}

void RoundRobin::SetPeriod(int period)
{
    schedulerPeriod = period;
}


RoundRobin::RoundRobinTaskHooks::RoundRobinTaskHooks(std::shared_ptr<RoundRobinTask> task)
{
    this->task = task;
}
