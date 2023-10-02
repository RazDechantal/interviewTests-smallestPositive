/*
Write a function solution that returns a string of length N consisting of alternating characters: "+"
and "-", starting with a "+" character. You can assume N is between 1 and 100.
*/
#include <string>
#include <iostream>

using namespace std;

std::string alternatingChar(int N)
{
    if (N <= 0)
    {
        return "length = 0"; // Return an empty string for invalid input
    }

    std::string result;
    result.reserve(N); // Reserve space for N characters to avoid reallocation

    char currentChar = '+';

    for (int i = 0; i < N; ++i)
    {
        result.push_back(currentChar);
        // Toggle between '+' and '-'
        currentChar = (currentChar == '+') ? '-' : '+';
    }

    return result;
}

int main()
{
    std::string res;

    for (int i = 0; i < 10; i++)
    {
        res = alternatingChar(i);
        cout << res << endl;
    }

    return 0;
}
