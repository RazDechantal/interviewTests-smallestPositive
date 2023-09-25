#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>

using namespace std;

std::vector<std::string> splitString(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens;
    std::istringstream ss(s);
    std::string token;
    while (std::getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

bool isShipSunk(const std::string &ship, const std::unordered_set<std::string> &hitCells)
{
    std::vector<std::string> shipCells = splitString(ship, ' ');
    for (const string &s : hitCells)
    {
        cout << "hit: " << s << endl;
    }

    cout << "----------------" << endl;
    for (const string &s : shipCells)
    {
        cout << "cell: " << s << endl;
    }

    for (const std::string &cell : shipCells)
    {

        // cout << "Cell: " << cell << endl;
        if (hitCells.find(cell) == hitCells.end())
        {
            return false; // At least one cell of the ship is not hit, so it's not sunk.
        }
    }

    return true; // All cells of the ship are hit, so it's sunk.
}

std::string solution(int N, const std::string &S, const std::string &T)
{
    std::unordered_set<std::string> hitCells;
    std::vector<std::string> shipDescriptions = splitString(S, ',');
    std::vector<std::string> hitPositions = splitString(T, ' ');

    // for (string s : shipDescriptions)
    // {
    //     cout << "ship: " << s << endl;
    //     /* code */
    // }

    for (const std::string &hitPosition : hitPositions)
    {
        hitCells.insert(hitPosition);
    }

    int sunkShips = 0;
    int hitNotSunkShips = 0;

    for (const std::string &shipDescription : shipDescriptions)
    {
        if (isShipSunk(shipDescription, hitCells))
        {
            sunkShips++;
        }
        else
        {
            hitNotSunkShips++;
        }
    }

    return std::to_string(sunkShips) + "," + std::to_string(hitNotSunkShips);
}

int main()
{
    int N = 4;
    std::string S = "1B 2C,2D 4D";
    std::string T = "2B 2D 3D 4D 4A";

    // std::string result = solution(N, S, T);
    // std::cout << result << std::endl; // Should print "1,1"

    N = 3;
    S = "1A 1B,2C 2C";
    T = "1B";
    string result = solution(N, S, T);
    std::cout << result << std::endl; // Should print "0,1"

    // N = 12;
    // S = "1A 2A,12A 12A";
    // T = "12A";
    // result = solution(N, S, T);
    // std::cout << result << std::endl; // Should print "1,0"

    return 0;
}
