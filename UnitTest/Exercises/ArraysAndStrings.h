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
}