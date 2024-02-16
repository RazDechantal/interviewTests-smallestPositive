#include <iostream>
#include <string>

int encodePositiveNum(std::string &S)
{
    int result = 0;
    int n = S.length();
    std::cout << "The size of the string is:" << n << std::endl;

    // Convert binary string to decimal integer
    int decimalValue = 0;
    for (int i = 0; i < n; i++)
    {
        decimalValue = decimalValue * 2 + (S[i] - '0');
        // std::cout << "X is :" << S[i] - '0' << "Decimal is:" << decimalValue << std::endl;
    }

    while (decimalValue > 0)
    {
        if (decimalValue % 2 == 0)
        {
            decimalValue /= 2;
        }
        else
        {
            decimalValue -= 1;
        }
        result++;
    }

    return result;
}

int main()
{
    std::string S1 = "011100";
    std::string S2 = "111";
    std::string S3 = "1111010101111";
    // std::string S4(100, '1'); // A string consisting of "1" repeated 400,000 times

    int result1 = encodePositiveNum(S1);
    int result2 = encodePositiveNum(S2);
    int result3 = encodePositiveNum(S3);
    // int result4 = encodePositiveNum(S4);

    std::cout << "Result 1: " << result1 << std::endl; // Should print 7
    std::cout << "Result 2: " << result2 << std::endl; // Should print 5
    std::cout << "Result 3: " << result3 << std::endl; // Should print 22
    // std::cout << "Result 4: " << result4 << std::endl; // Should print 799999

    return 0;
}
