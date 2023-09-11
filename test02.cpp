/*
Integer V lies strictly  between integers U and W if U < V < W or if U > V > W.
A non-empty array A consisting of N integers is given. A pair of indices (P, Q), where 0 ≤ P < Q < N, is said to have adjacent values  if no value in the array lies strictly between values A[P] and A[Q], and in addition A[P] ≠ A[Q].

For example, in array A such that:
  A[0] = 0
  A[1] = 3
  A[2] = 3
  A[3] = 7
  A[4] = 5
  A[5] = 3
  A[6] = 11
  A[7] = 1
the following pairs of indices have adjacent values:
  (0, 7),   (1, 4),   (1, 7),
  (2, 4),   (2, 7),   (3, 4),
  (3, 6),   (4, 5),   (5, 7).
For example, indices 4 and 5 have adjacent values because the values A[4] = 5 and A[5] = 3 are different, and there is no value in array A that lies strictly between them. The only such value could be the number 4, which is not present in the array.

Given two indices P and Q, their distance  is defined as abs(P−Q), where abs(X) = X for X ≥ 0, and abs(X) = −X for X < 0. For example, the distance between indices 4 and 5 is 1 because abs(4 − 5) = (5 − 4) = 1.

Write a function:
int solution(vector<int> &A)
that, given a non-empty array A consisting of N integers, returns the minimum distance between indices of this array that have adjacent values. The function should return −1 if no adjacent indices exist.
For example, given array A such that:
  A[0] = 1
  A[1] = 4
  A[2] = 7
  A[3] = 3
  A[4] = 3
  A[5] = 5
the function should return 2 because:
- indices 1 and 3 are adjacent because A[1] ≠ A[3] and the array does not contain any value that lies strictly between A[1] = 4 and A[3] = 3;
-  the distance between these indices is abs(1 − 3) = 2;
- no other pair of adjacent indices that has a smaller distance exists.

Write an  algorithm for the following assumptions:
- N is an integer within the range [1, 40000]
- each element of array A is an integer within the range [−2,147,483,648, 2,147,483,647]
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <algorithm>

int solution(std::vector<int> &A)
{
    std::unordered_map<int, std::vector<int>> valueIndices; // Maps values to their indices
    int minDistance = std::numeric_limits<int>::max();      // Initialize to a large value

    for (int i = 0; i < A.size(); ++i)
    {
        if (valueIndices.find(A[i]) != valueIndices.end())
        {
            // If this value has been seen before, update the minimum distance
            const std::vector<int> &indices = valueIndices[A[i]];
            for (int j = 0; j < indices.size(); ++j)
            {
                int distance = i - indices[j];
                if (distance < minDistance)
                {
                    minDistance = distance;
                }
            }
        }
        valueIndices[A[i]].push_back(i); // Update the list of indices for the current value
    }

    return (minDistance == std::numeric_limits<int>::max()) ? -1 : minDistance;
}

int main()
{
    std::vector<int> A = {1, 4, 7, 3, 3, 5};
    int result = solution(A);
    std::cout << "Minimum distance between adjacent indices with distinct values: " << result << std::endl; // Should print 2

    return 0;
}
