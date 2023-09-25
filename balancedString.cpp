/*
A string is called balanced when every letter occurring in the string, appears both in upper- and lowercase. For example, the string "CATattac"
 is balanced ('a', 'c' and 't' occur in both cases), but "Madam" is not ('d' and 'a' appear only in lowercase). Note that the number of
 occurrences does not matter.
Write a function int solution(string &s);
that, given a string S of length N, returns the length of the shortest balanced fragment of S. If S does not contain any balanced fragments,
the function should return -1.
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

using namespace std;

int balancedString(std::string &S)
{
    // Initialize frequency arrays for lowercase and uppercase letters
    std::vector<int> lowerFreq(26, 0); // Frequency array for lowercase letters
    std::vector<int> upperFreq(26, 0); // Frequency array for uppercase letters
    int totalCount = 0;                // Total count of letters in both cases

    // Initialize the lowercase and uppercase frequency arrays
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

    cout << "Lower:  ";
    for (int c : lowerFreq)
    {
        if (c != '0')
        {
            cout << c << " - ";
        }

        /* code */
    }
    cout << endl;

    cout << "Upper:  ";
    for (int c : upperFreq)
    {
        if (c != '0')
        {
            cout << c << " - ";
        }

        /* code */
    }
    cout << endl;

    // Initialize pointers for the sliding window
    int left = 0;
    int right = 0;

    // Initialize the answer to a large value
    int minLength = totalCount + 1;

    // Iterate through the string
    while (right < S.length())
    {
        char rightChar = S[right];

        // Expand the window by moving the right pointer
        if (islower(rightChar))
        {
            cout << "lower, right char is: " << rightChar << " lowerFreq[rightChar - 'a'] --->" << lowerFreq[(int)rightChar - (int)'a'] << " rightChar is: " << (int)rightChar << " 'a' is: " << (int)'a' << endl;
            lowerFreq[rightChar - 'a']--;
            cout << "lower, right char is: " << rightChar << " lowerFreq[rightChar - 'a'] --->" << lowerFreq[(int)rightChar - (int)'a'] << " rightChar is: " << (int)rightChar << " 'a' is: " << (int)'a' << endl;
        }
        else if (isupper(rightChar))
        {
            cout << "Upper, right char: " << rightChar << " lowerFreq[rightChar - 'A'] --->" << upperFreq[rightChar - 'A'] << " rightChar is: " << (int)rightChar << " 'A' is: " << (int)'A' << endl;
            upperFreq[rightChar - 'A']--;
            cout << "Upper, right char: " << rightChar << " lowerFreq[rightChar - 'A'] --->" << upperFreq[rightChar - 'A'] << " rightChar is: " << (int)rightChar << " 'A' is: " << (int)'A' << endl;
        }
        cout << " ---------------------------" << endl;

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

        // If the window is balanced, update the minimum length
        if (isBalanced)
        {
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

    // If minLength remains greater than the initial value, there was a balanced fragment
    return (minLength > totalCount) ? -1 : minLength;
}

int main()
{
    std::string S1 = "azABaabza";
    std::string S2 = "TacoCat";
    std::string S3 = "AcZCbaBz";
    std::string S4 = "abcdefghijklmnopqrstuvwxyz";

    std::cout << balancedString(S1) << std::endl; // Should print 5
    // std::cout << balancedString(S2) << std::endl; // Should print -1
    // std::cout << balancedString(S3) << std::endl; // Should print 8
    // std::cout << balancedString(S4) << std::endl; // Should print -1

    return 0;
}
