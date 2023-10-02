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
        if (c != 0)
        {
            cout << c << " - ";
        }

        /* code */
    }
    cout << endl;

    cout << "Upper:  ";
    for (int c : upperFreq)
    {
        if (c != 0)
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

    int total = 0;
    // Iterate through the string
    for (int i = 0; i < lowerFreq.size(); i++)
    {
        if (lowerFreq[i] != 0 && upperFreq[i] != 0)
        {
            cout << "lower = " << lowerFreq[i] << endl;
            cout << "lower = " << upperFreq[i] << endl;
            total += (int)lowerFreq[i];
            total += (int)upperFreq[i];
            cout << "total = " << total << endl;
        }
    }

    // cout << "total: " << total;

    // If minLength remains greater than the initial value, there was a balanced fragment
    return total;
}

int main()
{
    std::string S1 = "azABaabza";
    std::string S2 = "TacoCat";
    std::string S3 = "AcZCbaBz";
    std::string S4 = "abcdefghijklmnopqrstuvwxyz";

    std::cout << balancedString(S1) << std::endl; // Should print 5
    // std::cout << balancedString(S2) << std::endl; // Should print -1
    //  std::cout << balancedString(S3) << std::endl; // Should print 8
    //  std::cout << balancedString(S4) << std::endl; // Should print -1

    return 0;
}
