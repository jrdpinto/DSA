#include "HashTable.h"

// Interview question - Find first non-repeating character in a string
// Implement a function called firstNonRepeatingChar() that finds and returns the first non-repeating
// character in a given string.
//
// Input:
// The function takes a constant reference to a string input_string.
//
// Output:
// The function should return a character which is the first non-repeating character in the input string.
// If no non-repeating character is found, the function should return a null character ('\0').
//
// Constraints:
// The input string may contain any printable ASCII characters.
//
// Examples:
// Consider the following input string:
//     input_string: "programming"
//
// After calling firstNonRepeatingChar(input_string), the result should be:
//     'p'
char FirstNonRepeatingChar(const std::string& inputString)
{
    char nonRecurringCharacter = '\0';
    std::unordered_map<char,int> charCounts;

    for(char c : inputString)
    {
        auto it = charCounts.find(c);
        if (it == charCounts.end())
        {
            charCounts.insert(std::pair<char,int>(c, 1));
        }
        else
        {
            ++(*it).second;
        }
    }

    for(char c : inputString)
    {
        auto it = charCounts.find(c);
        if ((*it).second == 1)
        {
            nonRecurringCharacter = (*it).first;
            break;
        }
    }

    return nonRecurringCharacter;
}

int main()
{
    {
        HashTable<std::string, int> test{{"blah", 1}, {"apples", 100}, {"Nori", 1}, {"ZZ", 999}};
        test.Set("APWOEIHO208310170", -99);
        test.Set("ZZ", -99);
        test.PrintTable();

        std::cout << std::endl;
        std::cout << "Testing indexing function" << std::endl;
        std::cout << "Value at ZZ: " << test["ZZ"] << std::endl;
        std::cout << "Value at asdf: " << test["asdf"] << std::endl;
    }

    {
        std::cout << "Interview question - First non repeating character in a string." << std::endl;
        std::cout << "First non-repeating character in 'programming' - " << FirstNonRepeatingChar("programming")
         << std::endl;
        std::cout << "First non-repeating character in 'aaaabbbdddddf' - " << FirstNonRepeatingChar("aaaabbbdddddf")
         << std::endl;
        std::cout << "First non-repeating character in 'aaaaaaaa' - " << FirstNonRepeatingChar("aaaaaaaa")
         << std::endl;
    }

    return 0;
}