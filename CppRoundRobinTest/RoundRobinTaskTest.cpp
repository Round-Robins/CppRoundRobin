#include "stdafx.h"
#include "CppUnitTest.h"
#include <RoundRobinTask.h>
#include "EmptyRoundRobinTask.h"

using namespace CppRoundRobin;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CppRoundRobinTest
{		
	TEST_CLASS(RoundRobinTaskTests)
	{
	public:
		
		TEST_METHOD(DerivedClassPeriod)
		{
            EmptyRoundRobinTask task(50);

            Assert::AreEqual(task.Period(), 50);
        }

	};
}