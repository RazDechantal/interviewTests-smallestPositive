#include <iostream>
#include <array>

using namespace std;

int solution(int *A)
{
    std::string s = "+";
    bool isPositive = true;

    int size = sizeof(A) - sizeof(A[0]);
    for (int i = 0; i < size; i++)
    {
        if (A[i] == 0)
            return 0;
    }

    for (int i = 0; i < size; i++)
    {
        if (A[i] < 0)
        {
            if (isPositive)
                isPositive = false;
            else
                isPositive = true;
        }
    }
    if (isPositive)
        return 1;

    return -1;
}

int main()
{
    int A[] = {0, -2, -3, -5};
    cout << solution(A) << endl;
    return 0;
}