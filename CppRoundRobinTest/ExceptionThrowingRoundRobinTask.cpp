#include "stdafx.h"
#include "ExceptionThrowingRoundRobinTask.h"

using namespace CppRoundRobin;

ExceptionThrowingRoundRobinTask::ExceptionThrowingRoundRobinTask(int period) : RoundRobinTask(period)
{
}

ExceptionThrowingRoundRobinTask::~ExceptionThrowingRoundRobinTask()
{
}

void ExceptionThrowingRoundRobinTask::Task()
{
    throw 30;
}