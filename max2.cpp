#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(vector<int> &A)
{
    int maxCount = 0;

    // Sort the array in ascending order
    sort(A.begin(), A.end());

    // Iterate through the array to find the maximum number of integers that can be chosen
    for (int i = 0; i < A.size(); i++)
    {
        unordered_map<int, int> freqMap;
        int currentCount = 1;
        int diff = A[i];
        freqMap[A[i]] = 1;

        for (int j = i + 1; j < A.size(); j++)
        {
            if (A[j] - A[j - 1] == diff)
            {
                currentCount++;
                freqMap[A[j]] = 1;
            }
            else if (freqMap[A[j]] == 0)
            {
                break;
            }
        }

        maxCount = max(maxCount, currentCount);
    }

    return maxCount;
}

int main()
{
    vector<int> A1 = {4, 7, 1, 5, 3};
    vector<int> A2 = {12, 12, 12, 15, 10};
    vector<int> A3 = {18, 26, 18, 24, 24, 20, 22};

    cout << "Result 1: " << solution(A1) << endl; // Output should be 4
    cout << "Result 2: " << solution(A2) << endl; // Output should be 3
    cout << "Result 3: " << solution(A3) << endl; // Output should be 5

    return 0;
}
