#include <iostream>
#include <string>

int stringToInt(const std::string &s)
{
    int result = 0;

    for (char c : s)
    {
        if (c < '0' || c > '9')
        {
            std::cerr << "Error: Invalid input string" << std::endl;
            return -1; // Return -1 to indicate an error
        }
        result = result * 10 + (c - '0');
    }

    return result;
}

int main()
{
    std::string s = "1111";
    std::string s2 = "555555";

    int result = stringToInt(s);
    int result2 = stringToInt(s2);

    std::cout << "String: " << s << ", Integer value: " << result << std::endl;
    std::cout << "String: " << s2 << ", Integer value: " << result2 << std::endl;

    return 0;
}
