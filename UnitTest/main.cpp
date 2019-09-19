#include "stdafx.h"
#include "CppUnitTest.h"
#include "Exercises/ArraysAndStrings.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Excercises
{		
	TEST_CLASS(ArraysAndStrings)
	{
	public:

		TEST_METHOD(IsUnique)
		{
			Assert::IsFalse(CTCI::IsUnique("!@#$1234Q!W@E#E$R"), L"Not unique.", LINE_INFO());
			Assert::IsTrue(CTCI::IsUnique("1234Q!W@E$R"), L"Not unique.", LINE_INFO());
		}
	};
}