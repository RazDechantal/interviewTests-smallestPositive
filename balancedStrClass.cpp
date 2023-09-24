#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int DoSolution(std::string S)
    {
        std::string stringShortest = "";
        std::vector<std::string> listPatterns;

        for (int i = 0; i < S.length(); i++)
        {
            char letter = S[i];
            char response = isBalanced(letter, i, S, isupper(letter));

            if (response != '\0')
            {
                cout << "Response: " << response << endl;
                stringShortest += response;
                cout << "stringShortest: " << stringShortest << endl;
            }
            else
            {
                if (!stringShortest.empty() && stringShortest.length() > 1)
                {
                    listPatterns.push_back(stringShortest);
                    cout << "listPatterns: " << listPatterns[i] << endl;
                }
                stringShortest = "";
            }
        }

        if (!stringShortest.empty() && stringShortest.length() > 1 && listPatterns.empty())
        {
            listPatterns.push_back(stringShortest);
        }

        if (!listPatterns.empty())
        {
            stringShortest = *std::max_element(listPatterns.begin(), listPatterns.end());
        }

        return listPatterns.size() >= 1 ? stringShortest.length() : -1;
    }

    char isBalanced(char letter, int index, std::string S, bool isUpper)
    {
        char response = '\0';

        for (int i = 0; i < S.length(); i++)
        {
            if (index != i)
            {
                cout << "For i = " << i << " and For index: " << index << " S[i] = " << S[i] << "  letter is : " << letter << endl;

                if (isUpper)
                {
                    if (tolower(letter) == S[i])
                    {
                        response = letter;
                        cout << "Response upper: " << response << endl;
                    }
                }
                else
                {
                    if (toupper(letter) == S[i])
                    {
                        response = letter;
                        cout << "Response lower: " << response << endl;
                    }
                }
            }
        }

        return response;
    }
};

int main()
{
    std::cout << "Hello World!" << std::endl;
    Solution solution;

    std::string S1 = "azABaabza";
    std::string S2 = "TacoCat";
    std::string S3 = "AcZCbaBz";
    std::string S4 = "abcdefghijklmnopqrstuvwxyz";

    // int res = solution.DoSolution("azABaabza");
    int res = solution.DoSolution(S1);
    std::cout << "Result: " << res << std::endl;
    // res = solution.dosolution(s2);
    // std::cout << "result: " << res << std::endl;
    // res = solution.dosolution(s3);
    // std::cout << "result: " << res << std::endl;
    // res = solution.dosolution(s4);

    return 0;
}
