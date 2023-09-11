/*
John plays a game of battleships with his friend Sonia. The game is played on a square map of N rows, numbered from 1 to N. Each row contains N cells, labeled with consecutive English upper-case letters ('A', 'B', 'C', etc.). Each cell is identified by a string composed of its row number followed by its column number: for example, "9C" denotes the third cell in the 9th row, and "15D" denotes the fourth cell in the 15th row.
John marks the positions of all his ships on the map (which is not shown to Sonia). Ships are defined by rectangles with a maximum area of 4 cells. Sonia picks map cells to hit some ships. A ship is considered to be hit if at least one of its constituent cells is hit. If all of a ship's cells are hit, the ship is sunk.
The goal is to count the number of sunk ships and the number of ships that have been hit but not sunk.

In this example, one ship has been sunk and the other has been hit but not sunk.

We have the following coordinates where ships are situated.
Columns = [A,B,C,D]
Rows = [1,2,3,4]
The slots which are crossed makes the data set as such:
The coordinates of the ship in a 4*4 matrix or data set
A = {(1,A),(1,B),(1,C),(1,4),
         (2,A),(2,B),(2,C),(2,D),
         (3,A),(3,B),(3,C),(3,D),
         (4,A),(4,B),(4,C),(4,D)
}

We have two ships
Ship1 is hit at (2,B) but not sunk
Ship 2 is hit at (2,D), (3D), (4,D) and sunk

The positions of ships are given as a string S, containing pairs of positions separated with spaces, describing respectively the top-left and bottom-right corner cells of each ship. Ships' descriptions are separated with commas. The positions of hits are given as a string T, containing positions describing the map cells that were hit, separated with spaces. For the map in the example shown above, S = "1B 2C,2D 4D" and T = "2B 2D 3D 4D 4A". Ships in S and hits in T may appear in any order.

write a function
string solution(int N, string &s, string &T)
that, given the size of the map N and two strings S, T that describe the positions of ships and hits respectively, returns a string with two numbers: the count of sunken ships and the count of ships that have been hit but not sunk, separated with a comma.
Examples:
1. Given N = 4, S = "1B 2C,2D 4D" and T = "2B 2D 3D 4D 4A", your function should return "1,1", as explained above
2. Given N = 3, S = "1A 1B,2C 2C" and T = "1B", your function should return "0,1". One ship was hit but not sunk. Note that the ship in cell 2C was not hit nor sunk, therefore it is not included in the result.

3. Given N = 12, S = "1A 2A,12A 12A" and T = "12A", your function should return "1,0". One ship was sunk.

Assume that:
- N is an integer within the range [1, 26]
- string S contains the descriptions of rectangular ships of area not greater than 4 cells;
- there can be at most one ship located on any map cell (ships do not overlap);
- each map cell can appear in string T at most once;
- string S and string T contains only valid positions given in specified format.

In your solution, focus on correctness . The performance of your solution will not be the focus of the assessment.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <map>

std::string solution(int N, std::string &S, std::string &T)
{
    std::map<std::string, int> ships;
    std::vector<std::string> hits;

    // Split ship positions
    std::istringstream ss(S);
    std::string shipPos;
    while (std::getline(ss, shipPos, ','))
    {
        ships[shipPos] = 0; // Initialize ships as not hit
    }

    // Split hit positions
    std::istringstream ts(T);
    std::string hitPos;
    while (std::getline(ts, hitPos, ' '))
    {
        hits.push_back(hitPos);
    }

    int sunkShips = 0;
    int hitShips = 0;

    // Check hits
    for (auto &hit : hits)
    {
        if (ships.find(hit) != ships.end())
        {
            ships[hit] = 1; // Mark as hit
        }
    }

    for (auto &ship : ships)
    {
        if (ship.second == 0)
        {
            bool allHit = true;
            for (int row = ship.first[0] - '1'; row <= ship.first[1] - '1'; ++row)
            {
                for (int col = ship.first[2] - 'A'; col <= ship.first[3] - 'A'; ++col)
                {
                    std::string pos = std::to_string(row + 1) + char('A' + col);
                    if (ships.find(pos) == ships.end() || ships[pos] == 0)
                    {
                        allHit = false;
                        break;
                    }
                }
                if (!allHit)
                {
                    break;
                }
            }

            if (allHit)
            {
                sunkShips++;
            }
            else
            {
                hitShips++;
            }
        }
    }

    return std::to_string(sunkShips) + "," + std::to_string(hitShips);
}

int main()
{
    int N = 4;
    std::string S = "1B 2C,2D 4D";
    std::string T = "2B 2D 3D 4D 4A";
    std::string result = solution(N, S, T);
    std::cout << result << std::endl; // Should print "1,1"

    N = 3;
    S = "1A 1B,2C 2C";
    T = "1B";
    result = solution(N, S, T);
    std::cout << result << std::endl; // Should print "0,1"

    N = 12;
    S = "1A 2A,12A 12A";
    T = "12A";
    result = solution(N, S, T);
    std::cout << result << std::endl; // Should print "1,0"

    return 0;
}
