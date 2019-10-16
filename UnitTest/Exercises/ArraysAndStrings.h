#pragma once
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <assert.h>

namespace CTCI
{
    bool IsUnique(const char* s)
    {
		std::unordered_set<char> look;
		const size_t length = strlen(s);

		for (size_t i = 0; length - 1 > i; ++i)
		{
			if (look.find(s[i]) != look.end())
			{
				return false;
			}
			else
			{
				look.insert(s[i]);
			}
		}
		return true;
    }

	bool CheckPermutation(const char* a, const char* b)
	{
		const size_t aLength = strlen(a);
		const size_t bLength = strlen(b);

		if (aLength != bLength)
			return false;

		std::unordered_map<char, int> look;

		for(size_t i = 0; i < aLength; i++)
		{
			++look[a[i]];
			--look[b[i]];
		}

		for (auto& entry : look)
		{
			if (entry.second != 0)
				return false;
		}

		return true;
	}

	void Urlify(char* s, int len)
	{
		if (!s) return;

		auto swap = [](int a, int b, char* s)
		{
			s[a] ^= s[b];
			s[b] ^= s[a];
			s[a] ^= s[b];
		};
		auto loopSwap = [&swap](int start, int end, char* s)
		{
			for (int i = end; i > start+1; i -= 2)
			{
				swap(i - 2, i, s);
				swap(i - 1, i + 1, s);
			}
		};
		
		int end = len;
		size_t totalStrLen = strlen(s);
		for (int i = 0; end < totalStrLen; ++i)
		{
			if (s[i] == ' ')
			{
				loopSwap(i, end, s);
				s[i] = '%';
				s[i + 1] = '2';
				s[i + 2] = '0';

				i += 2;
				end += 2;
			}
		}
	}

	bool IsPalindrome(const char* s)
	{
		if (!s) return false;

		const size_t len = strlen(s);
		std::unordered_set<char> look;
		look.reserve(len);

		for (size_t i = 0; i < len; ++i)
		{
			if (look.find(s[i]) != look.end())
			{
				look.erase(s[i]);
			}
			else
			{
				look.insert(s[i]);
			}
		}

		const bool isOddLen = ((len & 1) == 1);

		if (isOddLen && look.size() == 1) 
			return true;
		if (!isOddLen && look.size() == 0)
			return true;

		return false;
	}

	bool OneAway(const char* A, const char* B)
	{
		assert(A); assert(B);
		const int aLen = static_cast<int>(strlen(A));
		const int bLen = static_cast<int>(strlen(B));

		if (abs(aLen - bLen) >= 2)
			return false;

		std::unordered_set<char> look;

		auto proccessString = [&look](const char* str, int stringLength)
		{
			for (size_t i = 0; i < stringLength; ++i)
			{
				const auto key = str[i];
				if (look.contains(key))
				{
					look.erase(key);
				}
				else
				{
					look.insert(key);
				}
			}
		};

		proccessString(A, aLen);
		proccessString(B, bLen);
		return look.size() <= 1;
	}

	std::string Compress(const std::string& in)
	{
		if (in.size() == 0)
		{
			return in;
		}

		std::stringstream cmpIn;
		size_t count = 1;
		char letter = in[0];

		for (size_t i = 1; i < in.size(); ++i)
		{
			if (in[i] == letter)
			{
				++count;
				continue;
			}

			cmpIn << letter << count;

			count = 1;
			letter = in[i];
		}
		
		cmpIn << letter << count;

		std::string cmpInString(std::move(cmpIn.str()));
		return cmpInString.size() < in.size() ? cmpInString : in;
	}
}