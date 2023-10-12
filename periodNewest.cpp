#include <iostream>
#include <string>
#include <array>
#include <cmath>

using namespace std;

int minimumBitsNeeded(int num)
{
    if (num == 0)
    {
        return 1; // Special case: 0 can be represented with 1 bit.
    }
    else
    {
        return static_cast<int>(std::ceil(std::log2(std::abs(num) + 1)));
    }
}

int solution(int n)
{
    /*

    */
    int d[minimumBitsNeeded(n)];
    int l = 0;
    /*
    The solution function takes an integer n as input. Inside the function,
    it converts n into its binary representation and stores the binary digits
    in the array d. It calculates the binary representation by repeatedly
    dividing n by 2 and storing the remainder in d, effectively building the
    binary representation from the least significant bit to the most significant bit.
    */

    while (n > 0)
    {
        d[l] = n % 2;
        cout << "d[" << l << "] = " << d[l] << ", ";
        n /= 2;
        l++;
    }

    cout << "[ ";
    for (auto i : d)
    {
        cout << i << ",";
    }
    cout << " ]" << endl;

    // If the binary representation has fewer than 2 digits, it means there is no
    // binary period, so the function returns -1
    if (l < 2)
        return -1;
    for (int p = 1; p < 1 + l; ++p)
    {
        bool ok = true;
        for (int i = 0; i < l - p; ++i)
        {
            cout << " d[" << i << "] = " << d[i] << " and d[" << i << " + " << p << "] = " << d[i + p];
            if (d[i] != d[i + p])
            {
                cout << " are not equal" << endl;
                ok = false;
                break;
            }
            cout << " are equal" << endl;
        }
        if (ok)
        {
            return p;
        }
    }
    return -1;
}

int main()
{
    // Test cases
    // int testCases[] = {955, 6, 328, 1, 17};
    int testCases[] = {99};
    for (auto i : testCases)
    {
        int result = solution(i);
        if (result == -1)
        {
            std::cout << "No binary period for " << i << std::endl;
        }
        else
        {
            std::cout << "Binary period of " << i << " is " << result << std::endl;
        }
    }

    return 0;
}
