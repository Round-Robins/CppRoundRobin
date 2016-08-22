
#include <vector>
#include <memory>
#include "RoundRobinTask.h"

#ifndef CPPROUNDROBIN_ROUNDROBIN_H
#define CPPROUNDROBIN_ROUNDROBIN_H

namespace CppRoundRobin {

    class RoundRobin {

    public:

        RoundRobin(bool offsetTasks);

        bool AddTask(std::shared_ptr<RoundRobinTask> task);

        bool Run(void);

        void TimerFired(void);

        void SetPeriod(int period);

    private:
        bool isTimerFired;

        int schedulerPeriod;

        bool offsetTasks;

        class RoundRobinTaskHooks {
        public:

            RoundRobinTaskHooks(std::shared_ptr<RoundRobinTask> task);

            int Counter(void) { return counter; }

            void ResetCounter(void) { counter = 0; }

            void IncrementCounter(void) { counter++; }

            void RunTask(void) { task.get()->Task(); }

            int TaskPeriod(void) { return task.get()->Period(); }

        private:
            int counter;

            std::shared_ptr<RoundRobinTask> task;
        };

        std::vector<RoundRobinTaskHooks> Tasks;
    };
}

#endif //CPPROUNDROBIN_ROUNDROBIN_H
