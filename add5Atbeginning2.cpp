/*
Write a function called solution that, given an integer N, returns the value obtained by
inserting one '5' digit at the left side of the integer N.
Examples:
1. Given N = 268, the function should return 5268
2. Given N = 670, the function should return 5670
3. Given N = 0, the function should return 50
4. Given N = −999, the function should return −5999
*/
#include <iostream>
#include <string>

int add5Atbeginning(int N)
{
    // Convert N to a string
    std::string N_str = std::to_string(N);
    bool isnegative = false;

    // Find the position to insert '5' to maximize the value
    int insert_pos = 0;
    char max_digit = '5';

    if (N_str[0] == '-')
    {
        N_str.erase(0, 1);
        isnegative = true;
        /* code */
    }

    // Insert '5' at the determined position
    N_str.insert(insert_pos, "5");
    if (isnegative)
    {
        N_str.insert(insert_pos, "-");
    }

    // Convert the modified string back to an integer
    return std::stoi(N_str);
}

int main()
{
    int N1 = 268;
    int N2 = 670;
    int N3 = 0;
    int N4 = -999;

    std::cout << add5Atbeginning(N1) << std::endl; // Should print 5268
    std::cout << add5Atbeginning(N2) << std::endl; // Should print 5670
    std::cout << add5Atbeginning(N3) << std::endl; // Should print 50
    std::cout << add5Atbeginning(N4) << std::endl; // Should print -5999

    return 0;
}
