#include <iostream>
#include <string>

bool solution(const std::string &S)
{
    bool foundB = false;

    for (char c : S)
    {
        if (c == 'a')
        {
            if (foundB)
            {
                return false; // 'a' after 'b', return false
            }
        }
        else if (c == 'b')
        {
            foundB = true;
        }
    }

    return true;
}

int main()
{
    // Test cases
    std::cout << solution("aabbb") << std::endl; // true
    std::cout << solution("ba") << std::endl;    // false
    std::cout << solution("aaa") << std::endl;   // true
    std::cout << solution("b") << std::endl;     // true
    std::cout << solution("abba") << std::endl;  // false

    return 0;
}
