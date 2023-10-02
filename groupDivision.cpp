#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

int groupDivision(vector<int> levels, int maxSpread)
{
    int n = levels.size();
    sort(levels.begin(), levels.end()); // Sort the skill levels in ascending order
    int groups = 1;                     // Initialize the number of groups

    // Initialize the index of the first student in the current group
    int groupStartIndex = 0;

    for (int i = 1; i < n; i++)
    {
        // Check if the skill level of the current student is within maxSpread of the first student in the current group
        if (levels[i] - levels[groupStartIndex] <= maxSpread)
        {
            continue; // Add the current student to the current group
        }
        else
        {
            groups++;            // Start a new group
            groupStartIndex = i; // Update the index of the first student in the new group
        }
    }

    return groups;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string levels_count_temp = "1, 4, 7, 3, 4";
    // getline(cin, levels_count_temp);

    int levels_count = stoi(ltrim(rtrim(levels_count_temp)));

    vector<int> levels(levels_count);

    for (int i = 0; i < levels_count; i++)
    {
        string levels_item_temp;
        getline(cin, levels_item_temp);

        int levels_item = stoi(ltrim(rtrim(levels_item_temp)));

        levels[i] = levels_item;
    }

    string maxSpread_temp = "2";
    // getline(cin, maxSpread_temp);

    int maxSpread = stoi(ltrim(rtrim(maxSpread_temp)));

    int result = groupDivision(levels, maxSpread);

    cout << result << endl;
    fout << result << "\n";

    fout.close();

    return 0;
}
