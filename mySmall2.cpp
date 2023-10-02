#include <iostream>
#include <vector>

using namespace std;

int smallestPos(vector<int> &A)
{
    int n = A.size();

    for (int i = 0; i < n; ++i)
    {
        while (A[i] > 0 && A[i] <= n && A[i] != A[A[i] - 1])
        {
            swap(A[i], A[i + 1]);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (A[i] != A[i + 1])
        {
            return i + 1;
        }
    }

    return 0;
}

int main()
{
    vector<int> A = {1, 3, 6, 4, 1, 2};
    cout << smallestPos(A) << endl;

    return 0;
}