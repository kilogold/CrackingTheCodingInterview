#pragma once
#include <string>
#include <functional>

namespace CTCI
{
    bool IsUnique(const char* string)
    {
       size_t length = strlen(string) + 1;

       for (size_t letterIdx = 0, subLetterIdx = 0; subLetterIdx < length; letterIdx++)
       {
           if (letterIdx == subLetterIdx)
           {
               continue;
           }

           if (letterIdx == length)
           {
               letterIdx = 0;
               ++subLetterIdx;
           }

           if (string[letterIdx] == string[subLetterIdx])
           {
               return false;
           }
       }
       return true;
    }

    bool IsUnique_RecursiveHelper(int& indexA, int& indexB, const char* string)
    {
        int length = strlen(string) + 1;

        // Base cases:
        if (indexA >= length)
        {
            return true; // Reached end without finding duplicate.
        }
        else if (indexB >= length)
        {
            indexB = 0;
            indexA++;
        }

        // Recursive case:
        {
            // If we're evaluating the same index, skip to the next recursion.
            if (indexA == indexB || string[indexA] != string[indexB])
            {
                return IsUnique_RecursiveHelper(indexA, ++indexB, string);
            }

            return false;
        }
    }

    bool IsUnique_Recursive(const char* string)
    {
        int indexA = 0;
        int indexB = 0;
        return IsUnique_RecursiveHelper(indexA, indexB, string);
    }
}