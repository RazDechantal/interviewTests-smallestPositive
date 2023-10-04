#include <iostream>
#include <vector>

using namespace std;

int solution(std::vector<int> &A)
{
    // This variable will be used to store the binary representation of the maximum subset that satisfies the condition.
    int result = 0;
    //  This variable will store the count of elements in the maximum subset.
    int maxSubsetSize = 0;

    /*
     * code snippet is used to find the maximum subset of elements in an array A such that
     * each element in the subset shares at least one common set bit at the same position
     * when represented in binary.
     */
    for (int i = 31; i >= 0; i--)
    { // Check each bit from left to right
        // the number of elements in A that have the current bit (at position i) set to 1
        int count = 0;

        for (int num : A)
        {
            // cout << "For number: " << num << " at bit: " << i;
            //  the code checks if the current element num has the bit at position i set to 1.
            //  This is done using the bitwise AND operation with (1 << i) (which is a bitmask
            //  with only the bit at position i set to 1).
            if ((num & (1 << i)) > 0)
            {
                // cout << " the bit value was: " << (num & (1 << i));
                count++;
            }
            // cout << endl;
        }

        if (count >= 1) // if there is at least one!
        {
            // If there are at least 2 numbers with the bit set to 1, update the result
            //  setting the bit at position i to 1 using the bitwise OR operation
            result |= (1 << i);
            maxSubsetSize = count;
        }
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
