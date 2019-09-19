#pragma once
#include <unordered_set>

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
}