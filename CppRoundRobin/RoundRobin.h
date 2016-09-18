#pragma once
#include <vector>
#include <memory>
#include "RoundRobinTask.h"
#include <windows.h>

namespace CppRoundRobin {
	class RoundRobin {
	public:

		RoundRobin(int schedulerPeriod);

		bool AddTask(std::shared_ptr<RoundRobinTask> task);

		void Run();

		void TimerFired(void);

		void SetPeriod(int period) { schedulerPeriod = period; }

		int GetPeriod(void) const { return schedulerPeriod; }

	private:
		bool isTimerFired;

		int schedulerPeriod;

	protected:
		class RoundRobinTimer
		{
		public:
			RoundRobinTimer();
			~RoundRobinTimer();

			void Start(RoundRobin* robin);

			void End();

		private:

			HANDLE hTimer;
			HANDLE hTimerQueue;
		};

		RoundRobinTimer taskTimer;

		class RoundRobinTaskHooks {
		public:

			RoundRobinTaskHooks(std::shared_ptr<RoundRobinTask> task);

			int Counter(void) const { return counter; }

			void ResetCounter(void) { counter = 0; }

			void IncrementCounter(void) { ++counter; }

			void RunTask(void) const { task.get()->Task(); }

			int TaskPeriod(void) const { return task.get()->Period(); }

		private:
			int counter;

			std::shared_ptr<RoundRobinTask> task;
		};

		std::vector<RoundRobinTaskHooks> Tasks;
	};
}
