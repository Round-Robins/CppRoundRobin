#pragma once
#include "RoundRobinTask.h"

using namespace CppRoundRobin;

class NotifyCallRoundRobinTask :
    public RoundRobinTask
{
public:
    NotifyCallRoundRobinTask(int period);
    ~NotifyCallRoundRobinTask();

    void Task() override;
};
