#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> &A)
{
    int N = A.size();

    // If there are fewer than 2 elements, we can choose all of them.
    if (N <= 2)
    {
        return N;
    }
    bool equalElement = false;

    // Sort the array A in ascending order.
    sort(A.begin(), A.end());

    // Initialize a variable to keep track of the maximum count.
    int maxCount = 0;

    // Iterate through all elements in the array.
    for (int i = 0; i < N; i++)
    {
        int count = 1; // Initialize count with 1 for the current element.

        // Iterate through the remaining elements to count the same values.
        for (int j = i + 1; j < N; j++)
        {
            if (A[j] == A[j + 1])
            {
                equalElement = true;
                /* code */
            }

            if (A[j] == A[i])
            {
                count++;
            }
            else if (A[j] - A[i] == (j - i) * (A[i + 1] - A[i]))
            {
                count++;
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
