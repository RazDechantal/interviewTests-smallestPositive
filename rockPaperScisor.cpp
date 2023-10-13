#include <iostream>
#include <string>

using namespace std;

int solution(string &G)
{
    int len = G.size();
    int max_score = 0;

    for (char gesture : "RPS")
    {
        int score = 0;
        for (int i = 0; i < len; i++)
        {
            if (gesture == G[i])
            {
                score += 1; // One score for Tie
            }
            else if ((gesture == 'R' && G[i] == 'S') || (gesture == 'S' && G[i] == 'P') || (gesture == 'P' && G[i] == 'R'))
            {
                score += 2; // Two scores for Win
            }
        }
        max_score = max(max_score, score);
    }

    return max_score;
}

int main()
{
    string example1 = "RSPRS";
    string example2 = "SRR";
    string example3 = "PRPRRPP";
    string example4 = "PPPPRRSSSSS";
    string example5 = "PSR";

    int result1 = solution(example1);
    int result2 = solution(example2);
    int result3 = solution(example3);
    int result4 = solution(example4);
    int result5 = solution(example5);

    cout << "Example 1: " << result1 << " points\n";
    cout << "Example 2: " << result2 << " points\n";
    cout << "Example 3: " << result3 << " points\n";
    cout << "Example 4: " << result4 << " points\n";
    cout << "Example 5: " << result5 << " points\n";

    return 0;
}
