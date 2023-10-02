#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

bool parseInputs(string, map<char, vector<char>> &, map<char, int> &, char &);
void lexiSExpressionPrint(map<char, vector<char>>, char);

string sExpression(const string &nodes)
{
    char root;
    map<char, vector<char>> adjList;
    map<char, int> numParents;

    if (!parseInputs(nodes, adjList, numParents, root))
    {
        return "E5";
    }

    string result;
    lexiSExpressionPrint(adjList, root);
    return result;
}

bool parseInputs(string input, map<char, vector<char>> &adjList, map<char, int> &numParents, char &root)
{
    char parent;
    int index = 0;
    bool E5Error = false;

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] != '(' && input[i] != ')' && input[i] != ',' && input[i] != ' ')
        {
            index++;
            if (index % 2 == 1)
            {
                if (i - 1 >= 0 && input[i - 1] != '(')
                {
                    return false;
                }
                else if (i + 1 < input.length() && input[i + 1] != ',')
                {
                    return false;
                }
                parent = input[i];
            }
            else
            {
                if (i - 1 >= 0 && input[i - 1] != ',')
                {
                    return false;
                }
                else if (i + 1 < input.length() && input[i + 1] != ')')
                {
                    return false;
                }

                for (int j = 0; j < adjList[parent].size(); j++)
                {
                    if (adjList[parent][j] == input[i])
                    {
                        return false;
                    }
                }

                if (adjList[parent].size() == 2)
                {
                    return false;
                }

                numParents[input[i]]++;
                numParents[parent];
                if (numParents[input[i]] == 2)
                {
                    E5Error = true;
                }

                adjList[parent].push_back(input[i]);
                index = 0;
            }
        }
        else if (i - 1 <= 0 && input[i] == ' ')
        {
            if (input[i] == ' ')
            {
                return false;
            }
        }
    }

    int numRoots = 0;
    for (auto kv : numParents)
    {
        if (kv.second == 0)
        {
            root = kv.first;
            numRoots++;
            if (numRoots == 2)
            {
                return false;
            }
        }
    }

    if (E5Error == true)
    {
        return false;
    }

    return true;
}

void lexiSExpressionPrint(map<char, vector<char>> adjList, char current)
{
    cout << "(" << current;
    int numChild = adjList[current].size();
    if (numChild == 1)
    {
        lexiSExpressionPrint(adjList, adjList[current][0]);
    }
    else if (numChild == 2)
    {
        if (adjList[current][0] < adjList[current][1])
        {
            lexiSExpressionPrint(adjList, adjList[current][0]);
            lexiSExpressionPrint(adjList, adjList[current][1]);
        }
        else
        {
            lexiSExpressionPrint(adjList, adjList[current][1]);
            lexiSExpressionPrint(adjList, adjList[current][0]);
        }
    }
    cout << ")";
}

int main()
{
    ofstream fout("tree3.txt");

    string nodes = "(B,D) (D,E) (A,B) (C,F) (E,G) (A,C)";

    // string nodes = "(A,B) (A,C) (B,D) (D,C)";
    //  getline(cin, nodes);

    string result = sExpression(nodes);

    cout << result << endl;

    nodes = "(A,B) (A,C) (B,D) (D,C)";
    result = sExpression(nodes);

    cout << result << endl;

    fout << result << "\n";

    fout.close();

    return 0;
}
