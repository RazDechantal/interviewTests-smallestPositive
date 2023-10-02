#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'numPaths' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY warehouse as parameter.
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

const int MOD = 1000000007;

int numPaths(vector<vector<int>> &warehouse)
{
    int n = warehouse.size();
    int m = warehouse[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = (warehouse[0][0] == 1) ? 1 : 0;

    for (int j = 1; j < m; j++)
    {
        if (warehouse[0][j] == 1)
        {
            dp[0][j] = dp[0][j - 1];
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (warehouse[i][0] == 1)
        {
            dp[i][0] = dp[i - 1][0];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (warehouse[i][j] == 1)
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    return dp[n - 1][m - 1];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string warehouse_rows_temp = " [1, 1, 0, 1], [1, 1, 1, 1]";
    // getline(cin, warehouse_rows_temp);

    int warehouse_rows = stoi(ltrim(rtrim(warehouse_rows_temp)));

    string warehouse_columns_temp;
    getline(cin, warehouse_columns_temp);

    int warehouse_columns = stoi(ltrim(rtrim(warehouse_columns_temp)));

    vector<vector<int>> warehouse(warehouse_rows);

    for (int i = 0; i < warehouse_rows; i++)
    {
        warehouse[i].resize(warehouse_columns);

        string warehouse_row_temp_temp;
        getline(cin, warehouse_row_temp_temp);

        vector<string> warehouse_row_temp = split(rtrim(warehouse_row_temp_temp));

        for (int j = 0; j < warehouse_columns; j++)
        {
            int warehouse_row_item = stoi(warehouse_row_temp[j]);

            warehouse[i][j] = warehouse_row_item;
        }
    }

    int result = numPaths(warehouse);

    fout << result << "\n";

    fout.close();

    return 0;
}

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

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}