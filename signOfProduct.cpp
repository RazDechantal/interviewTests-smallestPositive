/*
Write a function that, given an array A of N integers (between −100 and 100), returns the sign (−1, 0, 1) of the product of all the numbers in the array multiplied together. Assume that N is between 1 and 1000.  For example, given A = [1, −2, −3, 5], the function should return 1 (the multiplication equals 30).
 Given A = [1, 2, 3, −5] your function should return −1 (the multiplication equals −30).
 Given A = [1, 2, 0, −5] your function should return 0 (the multiplication equals 0).
*/

#include <vector>

int signOfProduct(std::vector<int> &A)
{
    int product = 1;
    bool hasZero = false;

    for (int num : A)
    {
        if (num == 0)
        {
            hasZero = true;
        }
        else
        {
            product *= num;
        }
    }

    if (product == 0)
    {
        return 0;
    }
    else if (product > 0)
    {
        return 1;
    }
    else
    {
        // If product < 0 and there was at least one non-zero element, return -1
        return hasZero ? 0 : -1;
    }
}
