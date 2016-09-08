#ifndef CPPROUNDROBIN_ROUNDROBINTASK_H_
#define CPPROUNDROBIN_ROUNDROBINTASK_H_

namespace CppRoundRobin
{
    class RoundRobinTask
    {
    public:
        RoundRobinTask(int period);
        virtual ~RoundRobinTask();

        virtual void Task() = 0;

        int Period() const { return period; }

    private:
        int period;
    };
}

#endif
