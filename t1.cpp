#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int balancedString(string &s)
{
    int n = s.length();

    // Create a frequency map to keep track of the counts of each character (case insensitive).
    unordered_map<char, int> freq;

    // Initialize the frequency map with lowercase letters.
    for (char c = 'a'; c <= 'z'; ++c)
    {
        freq[c] = 0;
    }

    int unique_chars = 0;   // Count of unique characters (case insensitive).
    int left = 0;           // Left pointer of the sliding window.
    int min_length = n + 1; // Initialize the minimum length to a value greater than the length of the input string.

    for (int right = 0; right < n; ++right)
    {
        char curr_char = tolower(s[right]);

        // Update the frequency map and unique_chars count.
        if (freq[curr_char] == 0)
        {
            unique_chars++;
        }
        freq[curr_char]++;

        // If all lowercase letters are present at least once in the current window, try to minimize the window size.
        while (unique_chars == 26)
        {
            min_length = min(min_length, right - left + 1);

            char left_char = tolower(s[left]);

            // Decrease the count of the left character in the frequency map.
            freq[left_char]--;

            // If the count becomes zero, reduce the unique_chars count.
            if (freq[left_char] == 0)
            {
                unique_chars--;
            }

            // Move the left pointer to the right to shrink the window.
            left++;
        }
    }

    // If min_length is still greater than n, no balanced fragment was found.
    if (min_length > n)
    {
        return -1;
    }

    return min_length;
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
