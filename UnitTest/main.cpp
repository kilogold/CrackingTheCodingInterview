#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\ArraysAndStrings\IsUnique.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest__ArraysAndStrings)
	{
	public:
		
		TEST_METHOD(ArraysAndStrings_IsUnique)
		{
        Assert::IsFalse(CTCI::IsUnique("!@#$1234Q!W@E#E$R"), L"Not unique.", LINE_INFO());
        Assert::IsTrue(CTCI::IsUnique("1234Q!W@E$R"), L"Not unique.", LINE_INFO());
    }
    TEST_METHOD(ArraysAndStrings_IsUnique_Recursive)
    {
        Assert::IsTrue(CTCI::IsUnique_Recursive("E$R"), L"Not unique.", LINE_INFO());
        Assert::IsFalse(CTCI::IsUnique_Recursive("!@#$1234Q!W@E#E$R"), L"Not unique.", LINE_INFO());
    }
	};
}