//
// Created by lucas on 8/17/2016.
//

#include <vector>
#include <memory>
#include "RoundRobinTask.h"

#ifndef CPPROUNDROBIN_ROUNDROBIN_H
#define CPPROUNDROBIN_ROUNDROBIN_H

namespace CppRoundRobin {

    class RoundRobin {

    public:
        bool AddTask(std::shared_ptr<RoundRobinTask> task);

        bool Run(void);


    private:
        std::vector<std::shared_ptr<RoundRobinTask>> Tasks;
    };
}

#endif //CPPROUNDROBIN_ROUNDROBIN_H
