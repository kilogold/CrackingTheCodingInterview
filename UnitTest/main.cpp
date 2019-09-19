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
			Assert::IsTrue(CTCI::IsUnique("1234Q!W@E$R"), L"Is unique.", LINE_INFO());
		}

		TEST_METHOD(CheckPermutation)
		{
			Assert::IsFalse(CTCI::CheckPermutation("!@#$1234Q!W@E#E$R", "!!!!!"), L"Not a permutation.", LINE_INFO());
			Assert::IsFalse(CTCI::CheckPermutation("trap", "help"), L"Not a permutation.", LINE_INFO());
			Assert::IsTrue(CTCI::CheckPermutation("listen", "silent"), L"Is a permutation.", LINE_INFO());
		}
	};
}