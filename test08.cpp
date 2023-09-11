#include <vector>

int solution(std::vector<int> &A)
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
