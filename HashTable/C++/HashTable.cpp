#include "HashTable.h"
#include <unordered_map>
#include <algorithm>

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

// Implement a function called groupAnagrams() that groups a list of strings based on their anagram equivalence.
// Input:
// The function takes a constant reference to a vector of strings strings.
// 
// Output:
// The function should return a vector of vectors of strings, where each inner vector contains a group of
// anagram-equivalent strings. The order of the groups and the strings within the groups does not matter.
// 
// Constraints:
//     The input strings may contain any printable ASCII characters.
//     The length of each string in the input vector may range from 1 to 100.
// 
// Examples:
// Consider the following input vector:
//     strings: {"eat", "tea", "tan", "ate", "nat", "bat"}
// 
// After calling groupAnagrams(strings), the result could be (order of groups and strings within groups does not matter):
//     {
//         {"eat", "tea", "ate"},
//         {"tan", "nat"},
//         {"bat"}
//     }
//
std::vector<std::vector<std::string>> GroupAnagrams(const std::vector<std::string>& strings)
{
    std::vector<std::vector<std::string>> result;
    std::unordered_map<std::string, std::vector<std::string>> anagramMap;

    for(const std::string& str : strings)
    {
        std::string sortedStr = str;
        std::sort(sortedStr.begin(), sortedStr.end());
        auto it = anagramMap.find(sortedStr);
        if (it == anagramMap.end())
        {
            anagramMap.insert(std::pair<std::string, std::vector<std::string>>(sortedStr, {str}));
        }
        else
        {
            (*it).second.push_back(str);
        }
    }

    for (auto& anagramPair : anagramMap)
    {
        result.push_back(anagramPair.second);
    }

    return result;
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

    {
        std::cout << "Interview question - Group anagrams." << std::endl;
        std::vector<std::string> strings{"eat", "tea", "tan", "ate", "nat", "bat"};
        std::vector<std::vector<std::string>> result = GroupAnagrams(strings);
        std::cout << "Result:" << std::endl;
        for(const auto& group : result)
        {
            std::cout << "{";
            for(const auto& str : group)
            {
                std::cout << str << ", ";
            }
            std::cout << "}" << std::endl;
        }
    }

    return 0;
}