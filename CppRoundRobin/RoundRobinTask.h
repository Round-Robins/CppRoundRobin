
namespace CppRoundRobin
{
	class RoundRobinTask
	{
	public:
		RoundRobinTask();
		~RoundRobinTask();

		virtual void Task() = 0;
	};
}
