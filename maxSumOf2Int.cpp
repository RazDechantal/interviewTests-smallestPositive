#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<int> findLargestTwo(const std::vector<int> &nums)
{
    std::vector<int> largestTwo(2, -1);

    for (int num : nums)
    {
        if (num > largestTwo[0])
        {
            largestTwo[1] = largestTwo[0];
            largestTwo[0] = num;
        }
        else if (num > largestTwo[1])
        {
            largestTwo[1] = num;
        }
    }

    return largestTwo;
}

int solution(std::vector<int> &A)
{
    std::unordered_map<int, std::vector<int>> digitGroups;

    // Group integers by their first and last digits
    for (int num : A)
    {
        int firstDigit = num;
        while (firstDigit >= 10)
        {
            firstDigit /= 10;
        }
        int lastDigit = num % 10;
        int digitPair = firstDigit * 10 + lastDigit;
        digitGroups[digitPair].push_back(num);
    }

    int maxSum = -1;

    // Calculate the maximum sum for each digit group
    for (const auto &entry : digitGroups)
    {
        const std::vector<int> &group = entry.second;

        if (group.size() >= 2)
        {
            std::vector<int> largestTwo = findLargestTwo(group);
            int sum = largestTwo[0] + largestTwo[1];
            maxSum = std::max(maxSum, sum);
        }
    }

    return maxSum;
}

int main()
{
    std::vector<int> A1 = {130, 191, 200, 10};
    std::cout << solution(A1) << std::endl; // Output: 140

    std::vector<int> A2 = {405, 45, 300, 300};
    std::cout << solution(A2) << std::endl; // Output: 600

    std::vector<int> A3 = {50, 222, 49, 52, 25};
    std::cout << solution(A3) << std::endl; // Output: -1

    std::vector<int> A4 = {30, 909, 3190, 99, 3990, 9009};
    std::cout << solution(A4) << std::endl; // Output: 9918

    return 0;
}
