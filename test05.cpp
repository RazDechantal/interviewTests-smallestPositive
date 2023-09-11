/*
Write a function   that, given strings and  and integer , returns a string composed of the first two letters from each of name and surname followed by age.
. For example, given  name = "John" , surname = "Firelord" and age = 8, the function should return JoFi8
*/

#include <iostream>
#include <string>

std::string generateString(std::string name, std::string surname, int age)
{
    // Ensure that name and surname have at least 2 characters
    if (name.length() < 2 || surname.length() < 2)
    {
        return ""; // Return an empty string for invalid input
    }

    // Extract the first two characters from name and surname
    std::string firstTwoName = name.substr(0, 2);
    std::string firstTwoSurname = surname.substr(0, 2);

    // Convert age to a string
    std::string ageStr = std::to_string(age);

    // Concatenate the extracted characters and age
    return firstTwoName + firstTwoSurname + ageStr;
}

int main()
{
    std::string name = "John";
    std::string surname = "Firelord";
    int age = 8;

    std::string result = generateString(name, surname, age);
    std::cout << result << std::endl; // Should print "JoFi8"

    return 0;
}
