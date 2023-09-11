#include <iostream>

#include <vector>

int smallestPositive(std::vector<int> &A)
{
    int n = A.size();
    std::cout << "___________________________" << std::endl;
    std::cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        std::cout << A[i] << " ";
        /* code */
    }
    std::cout << "] " << std::endl;

    for (int i = 0; i < n; ++i)
    {
        while (A[i] > 0 && A[i] <= n && A[i] != A[A[i] - 1])
        {
            // Swap A[i] with A[A[i] - 1]
            std::cout << " i: " << i << " n: " << n << "  Before: " << A[i] << "   Before A[i]- 1: " << A[i] - 1 << std::endl;
            std::swap(A[i], A[A[i] - 1]);
            std::cout << " i: " << i << " n: " << n << "  After: " << A[i] << "   After A[i]- 1: " << A[i] - 1 << std::endl;
        }
    }
    std::cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        std::cout << A[i] << " ";
        /* code */
    }

    std::cout << "] " << std::endl;
    std::cout << "___________________________" << std::endl;

    for (int i = 0; i < n; ++i)
    {
        if (A[i] != i + 1)
        {
            std::cout << "In return i: " << i << " i+1: " << i + 1 << std::endl;
            return i + 1;
        }
    }

    // If all positive integers from 1 to n are in the array, return n + 1
    return n + 1;
}

int main()
{

    std::vector<int> A = {10, 6, 8, 5, 4, 0, 2};
    std::cout << smallestPositive(A) << std::endl;

    A = {10, 30, 90, 5, 50, 110, 20};
    std::cout << smallestPositive(A) << std::endl;

    A = {1, 2, 3};
    std::cout << smallestPositive(A) << std::endl;

    A = {10, 6, 8, 5, 4, 0, 2};
    std::cout << smallestPositive(A) << std::endl;

    A = {7, 8, 3, 1};
    std::cout << smallestPositive(A) << std::endl;
    return 0;
}