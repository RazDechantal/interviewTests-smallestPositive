#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char isBalanced(char letter, int index, std::string S, bool isUpper)
{
    char response = '\0';

    for (int i = 0; i < S.length(); i++)
    {
        if (index != i)
        {
            // cout << "For i = " << i << " and For index: " << index << " S[i] = " << S[i] << "  letter is : " << letter << endl;

            if (isUpper)
            {
                if (tolower(letter) == S[i])
                {
                    response = letter;
                    // cout << "Response upper: " << response << endl;
                }
            }
            else
            {
                if (toupper(letter) == S[i])
                {
                    response = letter;
                    // cout << "Response lower: " << response << endl;
                }
            }
        }
    }

    return response;
}

int balancedString(std::string S)
{
    std::string stringShortest = "";
    std::vector<std::string> listPatterns;

    for (int i = 0; i < S.length(); i++)
    {
        char letter = S[i];
        char response = isBalanced(letter, i, S, isupper(letter));

        if (response != '\0')
        {
            // cout << "Response: " << response << endl;
            stringShortest += response;
            // cout << "stringShortest: " << stringShortest << endl;
        }
        else
        {
            if (!stringShortest.empty() && stringShortest.length() > 1)
            {
                listPatterns.push_back(stringShortest);
                // cout << "listPatterns: " << i << listPatterns[i] << endl;
            }
            stringShortest = "";
        }
    }
    std::cout << "string: " << stringShortest << " with Length: " << stringShortest.length() << " was added!" << std::endl;

    if (!stringShortest.empty() && stringShortest.length() > 1 && listPatterns.empty())
    {
        listPatterns.push_back(stringShortest);
    }

    if (!listPatterns.empty())
    {
        stringShortest = *std::max_element(listPatterns.begin(), listPatterns.end());
    }

    // for (string s : listPatterns)
    // {
    //     cout << "s: " << S << endl;
    // }
    // cout << "Size: " << listPatterns.size() << endl;
    cout << "shortest: " << stringShortest << endl;

    return listPatterns.size() >= 1 ? stringShortest.length() : -1;
}

int main()
{
    std::string S1 = "azABaabza";
    std::string S2 = "TacoCat";
    std::string S3 = "AcZCbaBz";
    std::string S4 = "abcdefghijklmnopqrstuvwxyz";

    std::cout << "Result: " << balancedString(S1) << std::endl;
    // std::cout << "Result: " << balancedString(S2) << std::endl;
    // std::cout << "Result: " << balancedString(S3) << std::endl;
    // std::cout << "Result: " << balancedString(S4) << std::endl;

    return 0;
}
