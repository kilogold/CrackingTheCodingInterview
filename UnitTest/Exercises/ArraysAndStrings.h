#pragma once
#include <unordered_set>
#include <unordered_map>

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
}