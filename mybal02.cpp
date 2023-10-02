#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool isBalanced(unordered_map<char, int> &freq)
{
    for (char c = 'a'; c <= 'z'; ++c)
    {
        if (freq[c] > 0 && freq[toupper(c)] == 0)
        {
            return false;
        }
    }
    return true;
}

int balancedString(string &s)
{
    int n = s.length();
    int minLength = n + 1;

    for (int i = 0; i < n; ++i)
    {
        unordered_map<char, int> freq;
        for (int j = i; j < n; ++j)
        {
            char curr_char = s[j];
            if (isalpha(curr_char))
            {
                freq[curr_char]++;
                if (isBalanced(freq))
                {
                    minLength = min(minLength, j - i + 1);
                    break; // Reset the freq map and move to the next i.
                }
            }
        }
    }

    return minLength == n + 1 ? -1 : minLength;
}

int main()
{
    string s1 = "azABaabza";
    string s2 = "TacoCat";
    string s3 = "AcZCbaBz";
    string s4 = "abcdefghijklmnopqrstuvwxyz";

    cout << balancedString(s1) << endl; // Should print 5
    cout << balancedString(s2) << endl; // Should print -1
    cout << balancedString(s3) << endl; // Should print 8
    cout << balancedString(s4) << endl; // Should print -1

    return 0;
}
