/**
 * int solution(vector<int> &A);
that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.
For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.
Given A = [1, 2, 3], the function should return 4.
Given A = [−1, −3], the function should return 1.
Write an efficient algorithm for the following assumptions:
N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].

*/
#include <vector>
#include <iostream>

int smallestPositiveInt(std::vector<int> &A)
{
    int n = A.size();

    for (int i = 0; i < n; ++i)
    {
        while (A[i] > 0 && A[i] <= n && A[i] != A[A[i] - 1])
        {
            // Swap A[i] with A[A[i] - 1]
            std::swap(A[i], A[A[i] - 1]);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (A[i] != i + 1)
        {
            return i + 1;
        }
    }

    // If all positive integers from 1 to n are in the array, return n + 1
    return n + 1;
}

int main()
{
    std::vector<int> A = {1, 3, 6, 4, 1, 2};
    std::vector<int> B = {1, 2, 3};
    std::vector<int> C = {-1, -3};
    std::cout << "The smallest positive nuber in A:  " << smallestPositiveInt(A) << std::endl;
    std::cout << "The smallest positive nuber in B:  " << smallestPositiveInt(B) << std::endl;
    std::cout << "The smallest positive nuber in C:  " << smallestPositiveInt(C) << std::endl;

    return 0;
}
