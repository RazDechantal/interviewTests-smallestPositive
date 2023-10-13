#include <iostream>
#include <string>

using namespace std;

string solution(int T)
{
    if (T < 0)
    {
        return "Wrong input";
    }

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
    int example3 = 33333;

    string result1 = solution(example1);
    string result2 = solution(example2);
    string result3 = solution(example3);
    string result4 = solution(-1);

    cout << "Example 1: " << result1 << endl;
    cout << "Example 2: " << result2 << endl;
    cout << "Example 3: " << result3 << endl;
    cout << "Example 4: " << result4 << endl;

    return 0;
}
