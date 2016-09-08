#include <vector>
#include <memory>
#include "RoundRobinTask.h"

#ifndef CPPROUNDROBIN_ROUNDROBIN_H
#define CPPROUNDROBIN_ROUNDROBIN_H

namespace CppRoundRobin {
    class RoundRobin {
    public:

        RoundRobin(int schedulerPeriod);

        bool AddTask(std::shared_ptr<RoundRobinTask> task);

        bool Run(void);

        void TimerFired(void);

        void SetPeriod(int period) { schedulerPeriod = period; }

        int GetPeriod(void) const { return schedulerPeriod; }

    private:
        bool isTimerFired;

        int schedulerPeriod;

        class RoundRobinTaskHooks {
        public:

            RoundRobinTaskHooks(std::shared_ptr<RoundRobinTask> task);

            int Counter(void) const { return counter; }

            void ResetCounter(void) { counter = 0; }

            void IncrementCounter(void) { counter++; }

            void RunTask(void) const { task.get()->Task(); }

            int TaskPeriod(void) const { return task.get()->Period(); }

        private:
            int counter;

            std::shared_ptr<RoundRobinTask> task;
        };

        std::vector<RoundRobinTaskHooks> Tasks;
    };
}

#endif //CPPROUNDROBIN_ROUNDROBIN_H
