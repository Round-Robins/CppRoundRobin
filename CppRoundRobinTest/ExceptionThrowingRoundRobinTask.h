#pragma once
#include "RoundRobinTask.h"

using namespace CppRoundRobin;

class ExceptionThrowingRoundRobinTask :
    public RoundRobinTask
{
public:
    ExceptionThrowingRoundRobinTask(int period);
    ~ExceptionThrowingRoundRobinTask();

    void Task() override;
};
