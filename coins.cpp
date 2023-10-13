#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A)
{
    int countHeads = 0;
    int countTails = 0;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == 0)
        {
            countHeads++;
        }
        else
        {
            countTails++;
        }
    }

    return min(countHeads, countTails);
}

int main()
{
    vector<int> A = {1, 0, 0, 1, 0, 0};
    int result = solution(A);
    cout << "Minimum number of coin flips: " << result << endl;

    return 0;
}
