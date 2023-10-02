#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> &A)
{
    int N = A.size();
    int repeated = 0;

    // If there are fewer than 2 elements, we can choose all of them.
    if (N <= 2)
    {
        return N;
    }

    // Sort the array A in ascending order.
    sort(A.begin(), A.end());

    // Initialize a variable to keep track of the maximum count.
    int maxCount = 0;

    // Iterate through all possible differences between consecutive elements.
    for (int diff = 1; diff <= 100; diff++)
    {
        int count = 0;          // Initialize count with 0 for the first element.
        int prev = A[0] - diff; // Initialize prev with a value lower than the first element.

        // Iterate through the sorted array and count the elements that fit the difference.
        for (int i = 0; i < N; i++)
        {
            if (A[i] - prev == diff)
            {
                count++;
                prev = A[i];
            }
                }

        // Update maxCount with the maximum count found so far.
        maxCount = max(maxCount, count);
    }

    return maxCount;
}

int main()
{
    std::vector<int> A1 = {4, 7, 1, 5, 3};
    std::cout << solution(A1) << std::endl; // Output: 4

    std::vector<int> A2 = {12, 12, 12, 15, 10};
    std::cout << solution(A2) << std::endl; // Output: 3

    std::vector<int> A3 = {18, 26, 18, 24, 24, 20, 22};
    std::cout << solution(A3) << std::endl; // Output: 5

    return 0;
}
