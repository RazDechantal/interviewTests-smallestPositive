#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(std::vector<int> arr)
{
    int maxAdjacentValue = -2;
    std::vector<int> sortedArr = arr;
    std::sort(sortedArr.begin(), sortedArr.end());

    for (int i : sortedArr)
    {
        cout << i << " - ";
        /* code */
    }

    cout << endl;
    for (int i = 0; i < sortedArr.size() - 1; i++)
    {
        int diff = std::abs(sortedArr[i + 1] - sortedArr[i]);
        maxAdjacentValue = std::max(diff, maxAdjacentValue);
        cout << "-" << diff;
    }
    cout << endl;

    return maxAdjacentValue;
}

int main()
{
    // std::vector<int> arr = {1, 4, 7, 3, 3, 5};
    std::vector<int> arr = {0, 3, 3, 7, 5, 3, 11, 1};

    int result = solution(arr);
    std::cout << "Maximum adjacent difference: " << result << std::endl;
    return 0;
}
