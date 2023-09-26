/*
Write a function called solution that, given an integer N, returns the maximum possible
value obtained by inserting one '5' digit inside the decimal representation of integer N.
Examples:
1. Given N = 268, the function should return 5268
2. Given N = 670, the function should return 6750
3. Given N = 0, the function should return 50
4. Given N = −999, the function should return −5999
*/
#include <iostream>
#include <string>

using namespace std;

int add5Atbeginning(int N)
{
    // Convert N to a string
    std::string N_str = std::to_string(N);
    // cout << N_str << endl;

    // Find the position to insert '5' to maximize the value
    int insert_pos = 0;
    char max_digit = '5';

    if (N >= 0)
    {
        while (insert_pos < N_str.length() && N_str[insert_pos] >= max_digit)
        {
            //  cout << insert_pos << " - checked for " << N_str[insert_pos] << " for: " << N << endl;
            //  cout << insert_pos << "-\t" << N_str[insert_pos];
            insert_pos++;
        }
        // cout << endl;
    }
    else
    {
        // If N is negative, skip the negative sign and insert '5' after it
        insert_pos = 1;
        while (insert_pos < N_str.length() && N_str[insert_pos] <= max_digit)
        {
            insert_pos++;
        }
    }

    // Insert '5' at the determined position
    N_str.insert(insert_pos, "5");

    // Convert the modified string back to an integer
    return std::stoi(N_str);
}

int main()
{
    int N1 = 268;
    int N2 = 670;
    int N3 = 0;
    int N4 = -999;
    int N6 = 2147483647;

    std::cout << add5Atbeginning(N1) << std::endl; // Should print 5268
    std::cout << add5Atbeginning(N2) << std::endl; // Should print 6750
    std::cout << add5Atbeginning(N3) << std::endl; // Should print 50
    std::cout << add5Atbeginning(N4) << std::endl; // Should print -5999
    // std::cout << add5Atbeginning(N6) << std::endl; // Should print 52147483647

    return 0;
}
