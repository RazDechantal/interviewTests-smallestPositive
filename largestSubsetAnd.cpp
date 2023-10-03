#include <iostream>
#include <vector>

int solution(std::vector<int> &A)
{
    int result = 0;
    int maxSubsetSize = 0;

    for (int i = 31; i >= 0; i--)
    { // Check each bit from left to right
        int count = 0;

        for (int num : A)
        {
            if ((num & (1 << i)) > 0)
            {
                count++;
            }
        }

        if (count >= 2)
        {
            // If there are at least 2 numbers with the bit set to 1, update the result
            result |= (1 << i);
            maxSubsetSize = count;
        }
    }

    int myresult = 0;

    for (int num : A)
    {
        myresult |= num; // Compute the bitwise OR of all elements in the array
    }

    if (maxSubsetSize == 0 && myresult > 0)
    {
        maxSubsetSize = 1;
    }

    return maxSubsetSize;
}

int main()
{
    // Test cases
    std::vector<int> A1 = {13, 7, 2, 8, 3};
    std::vector<int> A2 = {1, 2, 4, 8};
    std::vector<int> A3 = {16, 16};

    std::cout << solution(A1) << std::endl; // 3
    std::cout << solution(A2) << std::endl; // 1
    std::cout << solution(A3) << std::endl; // 2

    return 0;
}
