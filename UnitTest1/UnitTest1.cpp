#include "pch.h"
#include "CppUnitTest.h"
#include "../5.4.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int y;
			y = S4(2, 1, 1, 1);
			Assert::AreEqual(y, 3);
		}
	};
}
