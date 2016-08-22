//
// Created by lucas on 8/17/2016.
//

#include "RoundRobin.h"

using namespace CppRoundRobin;

bool CppRoundRobin::RoundRobin::AddTask(std::shared_ptr<RoundRobinTask> task)
{
	Tasks.push_back(task);
	return true;
}


bool RoundRobin::Run(void) {

	for (;;) {
		for each (std::shared_ptr<RoundRobinTask> task in Tasks)
		{
			task.get()->Task();
		}
	}
    return true;
}
