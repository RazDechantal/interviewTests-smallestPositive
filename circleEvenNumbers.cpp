/*
Task description
You are given N numbers on a circle, described by an array A. Find the maximum number of neighbouring pairs whose sums are even. One element can belong to only one pair.

Write a function:

class Solution { public int solution(int[] A); }

that, given an array A consisting of N integers, returns the maximum number of neighbouring pairs whose sums are even.

Examples:

1. Given A = [4, 2, 5, 8, 7, 3, 7], the function should return 2. We can create two pairs with even sums: (A[0], A[1]) and (A[4], A[5]). Another way to choose two pairs is: (A[0], A[1]) and (A[5], A[6]).

2. Given A = [14, 21, 16, 35, 22], the function should return 1. There is only one qualifying pair: (A[0], A[4]).

3. Given A = [5, 5, 5, 5, 5, 5], the function should return 3. We can create three pairs: (A[0], A[5]), (A[1], A[2]) and (A[3], A[4]).

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [0..1,000,000,000].
*/
#include <iostream>
#include <vector>

int maxEvenSumPairs(std::vector<int> &A)
{
    int count = 0;
    int n = A.size();

    for (int i = 0; i < n; i++)
    {
        if ((A[i] + A[(i + 1) % n]) % 2 == 0)
        {
            count++;
            i++; // Skip the next element
        }
    }

    return count;
}

int main()
{
    std::vector<int> A1 = {4, 2, 5, 8, 7, 3, 7};
    std::vector<int> A2 = {14, 21, 16, 35, 22};
    std::vector<int> A3 = {5, 5, 5, 5, 5, 5};
    std::vector<int> A4 = {14, 21, 16, 35, 22};

    int result1 = maxEvenSumPairs(A1);
    int result2 = maxEvenSumPairs(A2);
    int result3 = maxEvenSumPairs(A3);
    int result4 = maxEvenSumPairs(A4);

    std::cout << "Result 1: " << result1 << std::endl; // Should print 2
    std::cout << "Result 2: " << result2 << std::endl; // Should print 1
    std::cout << "Result 3: " << result3 << std::endl; // Should print 3
    std::cout << "Result 4: " << result4 << std::endl; // Should print 3

    return 0;
}
