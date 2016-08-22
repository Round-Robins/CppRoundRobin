#ifndef CPPROUNDROBIN_ROUNDROBINTASK_H_
#define CPPROUNDROBIN_ROUNDROBINTASK_H_

namespace CppRoundRobin
{
    class RoundRobinTask
    {
    public:
        RoundRobinTask(int period);
        ~RoundRobinTask();

        virtual void Task() = 0;

        int Period() { return period; }
         
    private:
        int period;
    };
}

#endif
