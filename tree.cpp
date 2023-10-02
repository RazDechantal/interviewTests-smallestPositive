#include <bits/stdc++.h>

using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>

using namespace std;

/*
 * Complete the 'sExpression' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING nodes as parameter.
 */

// Node structure to represent the tree

struct TreeNode
{
    char val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(char c) : val(c), left(nullptr), right(nullptr) {}
};

// Helper function to build the tree from input pairs
TreeNode *buildTree(const vector<pair<char, char>> &pairs)
{
    unordered_map<char, TreeNode *> nodes;
    for (const auto &pair : pairs)
    {
        char parent = pair.first;
        char child = pair.second;

        if (!nodes.count(parent))
        {
            nodes[parent] = new TreeNode(parent);
        }
        if (!nodes.count(child))
        {
            nodes[child] = new TreeNode(child);
        }

        if (!nodes[parent]->left)
        {
            nodes[parent]->left = nodes[child];
        }
        else
        {
            nodes[parent]->right = nodes[child];
        }
    }

    // Find the root
    unordered_set<char> childNodes;
    for (const auto &pair : pairs)
    {
        childNodes.insert(pair.second);
    }
    char root;
    for (const auto &pair : pairs)
    {
        if (!childNodes.count(pair.first))
        {
            root = pair.first;
            break;
        }
    }

    return nodes[root];
}

// Helper function to build the S-expression recursively
string buildSExpression(TreeNode *node)
{
    if (!node)
    {
        return "";
    }

    string left = buildSExpression(node->left);
    string right = buildSExpression(node->right);

    if (!left.empty() && !right.empty())
    {
        return "(" + string(1, node->val) + left + right + ")";
    }

    return string(1, node->val) + left + right;
}

string sExpression(const string &nodes)
{
    istringstream iss(nodes);
    vector<pair<char, char>> pairs;
    unordered_set<char> allNodes;

    char openParen, parent, comma, child, closeParen;

    while (iss >> openParen >> parent >> comma >> child >> closeParen)
    {
        if (openParen == '(' && comma == ',' && closeParen == ')' && isalpha(parent) && isalpha(child))
        {
            if (allNodes.count(parent) || allNodes.count(child))
            {
                return "E3"; // E3: Cycle present
            }
            if (find(pairs.begin(), pairs.end(), make_pair(parent, child)) != pairs.end())
            {
                return "E2"; // E2: Duplicate edges
            }
            pairs.emplace_back(parent, child);
            allNodes.insert(parent);
            allNodes.insert(child);
        }
        else
        {
            return "E5"; // E5: Any other error
        }
    }

    TreeNode *root = buildTree(pairs);

    if (!root)
    {
        return "E4"; // E4: Multiple roots
    }

    return buildSExpression(root);
}

int main()
{
    ofstream fout("amir.txt");

    string nodes = "(B,D) (D,E) (A,B) (C,F) (E,G) (A,C)";
    // getline(cin, nodes);

    string result = sExpression(nodes);

    fout << result << "\n";

    fout.close();

    return 0;
}
