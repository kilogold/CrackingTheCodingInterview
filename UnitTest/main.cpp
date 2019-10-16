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

		TEST_METHOD(Urlify)
		{
			{
				const char* t0 = "Hello%20World";
				char* t1 = new char[14];
				strcpy(t1, "Hello World  ");
				CTCI::Urlify(t1, 11);
				Assert::AreEqual(t0, t1, "Not equal");
				delete[] t1;
			}
			{
				const char* t0 = "This%20is%20a%20more%20complex%20%20%20sentence.";
				char* t1 = new char[49];
				strcpy(t1, "This is a more complex   sentence.              ");
				CTCI::Urlify(t1, 34);
				Assert::AreEqual(t0, t1, "Not equal");
				delete[] t1;
			}
		}

		TEST_METHOD(IsPalindrome)
		{
			Assert::IsTrue(CTCI::IsPalindrome("RACECAR"), L"Is a palindrome");
			Assert::IsFalse(CTCI::IsPalindrome("MIKELSEN"), L"Is not a palindrome");
		}

		TEST_METHOD(OneAway)
		{
			Assert::IsTrue(CTCI::OneAway("Hello", "Hello"));
			Assert::IsFalse(CTCI::OneAway("Hello", "Facey"));
			
			Assert::IsFalse(CTCI::OneAway("", "Facey"));
			Assert::IsTrue(CTCI::OneAway("Hello", "Hello!"));
			Assert::IsFalse(CTCI::OneAway("Hello", "Hello!!"));
		}

		TEST_METHOD(Compress)
		{
			Assert::AreEqual(std::string("a3"), CTCI::Compress("aaa"));
			Assert::AreEqual(std::string("a3b1c10d1"), CTCI::Compress("aaabccccccccccd"));
			Assert::AreEqual(std::string("abc"), CTCI::Compress("abc"));
		}
	};
}