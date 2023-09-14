/*
A string is called balanced when every letter occurring in the string, appears both in upper- and lowercase. For example, the string "CATattac" is balanced ('a', 'c' and 't' occur in both cases), but "Madam" is not ('d' and 'a' appear only in lowercase). Note that the number of occurrences does not matter.
Write a function int solution(string &s);
that, given a string S of length N, returns the length of the shortest balanced fragment of S. If S does not contain any balanced fragments, the function should return -1.
Examples:
1. Given S = "azABaabza", the function should return 5. The shortest balanced fragment of S is "ABaab".
2. Given S = "TacoCat", the function should return -1. There is no balanced fragment.
3. Given S = "AcZCbaBz", the function should return 8. The shortest balanced fragment is the whole string.
4. Given S = "abcdefghijklmnopqrstuvwxyz", the function should return -1.

Assume that:
N is an integer within the range [1,200]
string S consists only of letters ('a'−'z' and/or 'A'−'Z').
In your solution, focus on "correctness". The performance of your solution will not be the focus of the assessment.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int balancedString(std::string &S)
{
    // Initialize frequency arrays for lowercase and uppercase letters
    std::vector<int> lowerFreq(26, 0);
    std::vector<int> upperFreq(26, 0);

    // Count the total number of letters in both cases
    int totalCount = 0;

    for (char ch : S)
    {
        if (islower(ch))
        {
            lowerFreq[ch - 'a']++;
        }
        else if (isupper(ch))
        {
            upperFreq[ch - 'A']++;
        }
        totalCount++;
    }

    // Initialize the answer to the total length of the string
    int minLength = totalCount;

    // Initialize left and right pointers for the sliding window
    int left = 0;
    int right = 0;

    while (right < totalCount)
    {
        char rightChar = S[right];

        // Expand the window by moving the right pointer
        if (islower(rightChar))
        {
            lowerFreq[rightChar - 'a']--;
        }
        else if (isupper(rightChar))
        {
            upperFreq[rightChar - 'A']--;
        }

        // Check if the window contains all letters in both cases
        bool isBalanced = true;

        for (int i = 0; i < 26; ++i)
        {
            if (lowerFreq[i] > 0 || upperFreq[i] > 0)
            {
                isBalanced = false;
                break;
            }
        }

        if (isBalanced)
        {
            // If the window is balanced, update the minimum length
            minLength = std::min(minLength, right - left + 1);

            // Try to shrink the window by moving the left pointer
            char leftChar = S[left];

            if (islower(leftChar))
            {
                lowerFreq[leftChar - 'a']++;
            }
            else if (isupper(leftChar))
            {
                upperFreq[leftChar - 'A']++;
            }

            left++;
        }

        right++;
    }

    // If minLength remains equal to the total length, there was no balanced fragment found
    return (minLength == totalCount) ? -1 : minLength;
}

int main()
{
    std::string S1 = "azABaabza";
    std::string S2 = "TacoCat";
    std::string S3 = "AcZCbaBz";
    std::string S4 = "abcdefghijklmnopqrstuvwxyz";

    std::cout << balancedString(S1) << std::endl; // Should print 5
    std::cout << balancedString(S2) << std::endl; // Should print -1
    std::cout << balancedString(S3) << std::endl; // Should print 8
    std::cout << balancedString(S4) << std::endl; // Should print -1

    return 0;
}
