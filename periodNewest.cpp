#include <iostream>
#include <string>

int solution(int n)
{
    int d[30];
    int l = 0;
    while (n > 0)
    {
        d[l] = n % 2;
        n /= 2;
        l++;
    }
    if (l < 2)
        return -1;
    for (int p = 1; p < 1 + l; ++p)
    {
        bool ok = true;
        for (int i = 0; i < l - p; ++i)
        {
            if (d[i] != d[i + p])
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            return p;
        }
    }
    return -1;
}

int main()
{
    // Test cases
    int testCases[] = {955, 6, 328, 1, 17};
    for (int i = 0; i < 5; ++i)
    {
        int result = solution(testCases[i]);
        if (result == -1)
        {
            std::cout << "No binary period for " << testCases[i] << std::endl;
        }
        else
        {
            std::cout << "Binary period of " << testCases[i] << " is " << result << std::endl;
        }
    }

    return 0;
}
