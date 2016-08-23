#pragma once
#include "RoundRobinTask.h"

using namespace CppRoundRobin;

class EmptyRoundRobinTask :
    public RoundRobinTask
{
public:
    EmptyRoundRobinTask(int period);
    ~EmptyRoundRobinTask();

    void Task(){}
};

