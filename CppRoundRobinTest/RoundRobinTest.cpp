#include "stdafx.h"
#include "CppUnitTest.h"
#include <RoundRobin.h>
#include "ExceptionThrowingRoundRobinTask.h"

using namespace CppRoundRobin;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CppRoundRobinTest
{
    TEST_CLASS(RoundRobinTests)
    {
    public:

        TEST_METHOD(GetPeriod)
        {
            RoundRobin robin(1);

            Assert::AreEqual(robin.GetPeriod(), 1);
        }

        TEST_METHOD(SetPeriod)
        {
            RoundRobin robin(5);
            robin.SetPeriod(6);

            Assert::AreEqual(robin.GetPeriod(), 6);
        }

        TEST_METHOD(RunSingleTask)
        {
            RoundRobin robin(1);

            std::shared_ptr<RoundRobinTask> task(new ExceptionThrowingRoundRobinTask(1));
            robin.AddTask(task);

            try
            {
                robin.TimerFired(); // force fire the timer
                robin.Run();
            }
            catch (int e)
            {
                Assert::AreEqual(30, e);
            }
        }
    };
}