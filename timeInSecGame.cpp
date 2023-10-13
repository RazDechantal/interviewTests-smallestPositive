#include <iostream>
#include <string>

using namespace std;

string solution(int T)
{
    int hours = T / 3600;
    int minutes = (T % 3600) / 60;
    int seconds = T % 60;

    string result = to_string(hours) + "h" + to_string(minutes) + "m" + to_string(seconds) + "s";
    return result;
}

int main()
{
    int example1 = 7500;
    int example2 = 83643;

    string result1 = solution(example1);
    string result2 = solution(example2);

    cout << "Example 1: " << result1 << endl;
    cout << "Example 2: " << result2 << endl;

    return 0;
}
