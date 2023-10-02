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

pair<string, int> findLargestSubstringWithMixedCase(const string &str)
{
    string largestMixedCaseSubstring;
    int largestLength = 0;
    int len = str.length();

    string currentSubstring;
    string stringShortest;
    vector<string> listPatterns;

    for (int i = 0; i < len; ++i)
    {
        char letter = str[i];
        char response = '\0';

        for (int j = 0; j < len; j++)
        {
            if (i != j)
            {
                // cout << "For i = " << i << " and For index: " << index << " S[i] = " << S[i] << "  letter is : " << letter << endl;

                if (isupper(letter))
                {
                    if (tolower(letter) == str[j])
                    {
                        response = letter;
                        break;
                        // cout << "Response upper: " << response << endl;
                    }
                }
                else
                {
                    if (toupper(letter) == str[j])
                    {
                        response = letter;
                        break;
                        // cout << "Response lower: " << response << endl;
                    }
                }
            }
        }

        if (response != '\0')
        {
            currentSubstring += response;
        }
        else
        {
            if (!currentSubstring.empty() && currentSubstring.length() > 1)
            {
                listPatterns.push_back(currentSubstring);
            }
            currentSubstring = "";
        }
    }

    std::cout << "string: " << currentSubstring << " with Length: " << currentSubstring.length() << " was added!" << std::endl;

    if (!currentSubstring.empty() && currentSubstring.length() > 1 && listPatterns.empty())
    {
        listPatterns.push_back(currentSubstring);
    }

    if (!listPatterns.empty())
    {
        stringShortest = *std::max_element(listPatterns.begin(), listPatterns.end());
    }

    if (listPatterns.size() >= 1)
    {
        std::cout << "shortest: " << stringShortest << " Length: " << stringShortest.length() << std::endl;
        return make_pair(stringShortest, stringShortest.length());
        /* code */
    }

    // if (stringShortest.length() > largestLength)
    // {
    //     largestMixedCaseSubstring = stringShortest;
    //     largestLength = stringShortest.length();
    // }

    return make_pair("", -1);
}

int main()
{
    pair<string, int> result = findLargestSubstringWithMixedCase("abcdefghijklmnopqrstuvwxyz");

    string largestMixedCaseSubstring = result.first;
    int largestLength = result.second;

    if (largestLength > 0)
    {
        cout << "Largest mixed case substring: " << largestMixedCaseSubstring << endl;
        cout << "Length of largest mixed case substring: " << largestLength << endl;
    }
    else
    {
        cout << "No mixed case substring found." << endl;
    }

    return 0;
}
