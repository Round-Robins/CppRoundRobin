
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
