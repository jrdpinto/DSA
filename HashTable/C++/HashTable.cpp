#include "HashTable.h"
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <vector>

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

// Implement a function called groupAnagrams() that groups a list of strings based on their
// anagram equivalence.
// Input:
// The function takes a constant reference to a vector of strings strings.
// 
// Output:
// The function should return a vector of vectors of strings, where each inner vector contains
// a group of anagram-equivalent strings. The order of the groups and the strings within the 
// groups does not matter.
// 
// Constraints:
//     The input strings may contain any printable ASCII characters.
//     The length of each string in the input vector may range from 1 to 100.
// 
// Examples:
// Consider the following input vector:
//     strings: {"eat", "tea", "tan", "ate", "nat", "bat"}
// 
// After calling groupAnagrams(strings), the result could be (order of groups and strings within
// groups does not matter):
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

// Implement a function called twoSum() that finds two numbers in a given vector of integers that 
// add up to a specific target number. If there are two pairs of numbers that sum to the target
// it is assumed that you're looking for the first pair of numbers that sum to the target, based
// on their position in the array (an example is given below).
// 
// Input:
// The function takes the following inputs:
//     A constant reference to a vector of integers nums.
//     An integer target.
// 
// Output:
// The function should return a vector of two integers representing the indices of the two numbers
// in the input vector nums that add up to the target value. If no such pair exists, the function
// should return an empty vector.
// 
// Constraints:
//     Each input would have exactly one solution.
//     The same element in the input vector should not be used twice.
// 
// Example:
// Consider the following input vector and target:
//     nums: {1, 3, 4, 2, 5};
//     target: 6;
// 
// There are two combinations that add up to 6 which are:
//     {2, 3} and {0, 4}
// 
// After calling twoSum(nums, target), the result should be the first pair of numbers that sum to the target:
//     {2, 3}
std::vector<int> TwoSum(std::vector<int>& nums, int target)
{
    std::unordered_map<int, int> numToIndex;
	std::vector<int> result;

    for (int i = 0; i < nums.size(); ++i)
    {
        int num = nums[i];
        int complement = target - num;

        auto it = numToIndex.find(target-num);
        if (it != numToIndex.end())
        {
            result.push_back(numToIndex[complement]);
            result.push_back(i);
            break;
        }
        else
        {
            numToIndex[num] = i;
        }
    }
	
	return result;
}

// Implement a function called subarraySum() that finds a continuous subarray within a given vector
// of integers that adds up to a specific target number.
// 
// Input:
// The function takes the following inputs:
//     A constant reference to a vector of integers nums.
//     An integer target.
// 
// Output:
// The function should return a vector of two integers representing the start and end indices
// (inclusive) of the continuous subarray in the input vector nums that adds up to the target value.
// If no such subarray exists, the function should return an empty vector.
// 
// Examples:
// Consider the following input vector and target:
//     nums: {1, 2, 3, 4, 5}
//     target: 9
// 
// After calling subarraySum(nums, target), the result should be:
//     {1, 3}

std::vector<int> SubarraySum(std::vector<int>& nums, int target)
{
    std::vector<int> result;
    std::unordered_map<int,int> cumulativeSumMap{std::pair<int, int>(0, -1)};

    int cumulativeSum = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        cumulativeSum += nums[i];
        auto it = cumulativeSumMap.find(cumulativeSum - target);
        if (it != cumulativeSumMap.end())
        {
            result.push_back((*it).second + 1);
            result.push_back(i);
            break;
        }
        else
        {
            cumulativeSumMap[cumulativeSum] = i;
        }
    }

    return result;
}

// Write a function called findPairs.
// 
// This function takes two lists of numbers and a target number.
// 
// It then finds pairs of numbers where one number is from the first list and the other is from the
// second list, and their sum equals the target number. The function returns these pairs.
// 
// What Do We Mean by "Pairs"? 
// Pairs are sets of two numbers. For example, if we have 4 in one list and 6 in another, and our
// target number is 10, then (4, 6) is a pair that adds up to 10.
// 
// Input
//     A list of numbers stored in a vector called arr1.
//     Another list of numbers stored in a vector called arr2.
//     A target number called target.
// 
// Output
// A list of pairs that add up to the target number. Each pair contains one number from arr1 and one
// number from arr2.
// 
// Example
// Input Lists and Target
//     First List: [1, 2, 3]
//     Second List: [4, 5, 6]
//     Target: 8
// 
// Output Pairs
// [(2, 6), (3, 5)]

std::vector<std::vector<int>> FindPairs(const std::vector<int>& arr1, const std::vector<int>& arr2,
 int target)
{
    std::vector<std::vector<int>> result;
    std::unordered_set<int> numMap;

    for (int num : arr1)
    {
        numMap.insert(num);
    }

    for (int num : arr2)
    {
        int complement = target - num;

        auto it = numMap.find(complement);
        if (it != numMap.end())
        {
            result.push_back({(*it), num});
        }
    }

    return result;
}

// Write a function called longestConsecutiveSequence.
// 
// This function takes a list of numbers as input and finds the length of the longest sequence of
// numbers that can be arranged in order.
// 
// For example, if the list is [2, 1, 6, 9, 4, 3], the longest sequence in order is [1, 2, 3, 4],
// and the length is 4.
// 
// What Do We Mean by "Sequence in Order"?
// 
// A sequence in order is a group of numbers that follow each other without any gaps. For example,
// 1, 2, 3, 4 is a sequence in order because they follow each other. 1, 3, 4 is not a sequence in
// order because there is a gap; 2 is missing.
// 
// What Do You Need to Do?
//     Receive a List: The function takes a list of numbers as input.
//     Look at Each Number: The function examines each number in the list.
//     Find Starting Points: The function identifies good starting points for sequences.
//     Check for Next Numbers: For each starting point, the function checks if the next number in
//     the sequence is in the list.
//     Count Length: It keeps track of how long each sequence is.
//     Find Longest: The function identifies which sequence is the longest.
//     Return Length: Finally, the function returns the length of the longest sequence.
// 
// Input
// A list of numbers stored in a vector called nums.
// 
// Output
// The length of the longest sequence of numbers that can be arranged in order.
// 
// Example:
// Input List
// [2, 1, 6, 9, 4, 3]
// 
// Output Length
// 4

int LongestConsecutiveSequence(const std::vector<int>& nums) 
{
    int longestSequence = 0;
    std::unordered_set<int> numSet(nums.begin(), nums.end());

    for (int num : numSet)
    {
        if (numSet.find(num - 1) == numSet.end())
        {
            int currentNum = num;
            int currentSequence = 1;

            while (numSet.find(currentNum + 1) != numSet.end())
            {
                ++currentSequence;
                ++currentNum;
            }

            longestSequence = std::max(currentSequence, longestSequence);
        }
    }

    return longestSequence;
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
        std::cout << std::endl;
    }

    {
        std::cout << "Interview question - First non repeating character in a string." << std::endl;
        std::cout << "First non-repeating character in 'programming' - " << FirstNonRepeatingChar("programming")
         << std::endl;
        std::cout << "First non-repeating character in 'aaaabbbdddddf' - " << FirstNonRepeatingChar("aaaabbbdddddf")
         << std::endl;
        std::cout << "First non-repeating character in 'aaaaaaaa' - " << FirstNonRepeatingChar("aaaaaaaa")
         << std::endl;
        std::cout << std::endl;
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
        std::cout << std::endl;
    }

    {
        std::cout << "Interview question - TwoSum." << std::endl;
        std::vector<int> inputList{1, 3, 4, 2, 5};
        std::vector<int> result = TwoSum(inputList, 6);
        std::cout << "{1, 3, 4, 2, 5} Result:" << std::endl;
        std::string output;
        for (int num : result)
        {
            output.append(std::to_string(num));
            output.append(" ");
        }
        std::cout << output.c_str() << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "Interview question - SubarraySum." << std::endl;
        std::vector<int> inputList{1, 3, 4, 2, 5};
        std::vector<int> result = SubarraySum(inputList, 9);
        std::cout << "{1, 3, 4, 2, 5} Result:" << std::endl;
        std::string output;
        for (int num : result)
        {
            output.append(std::to_string(num));
            output.append(" ");
        }
        std::cout << output.c_str() << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "Interview question - Find pairs" << std::endl;
        std::vector<int> inputList{1, 2, 3};
        std::vector<int> inputList2{4, 5, 6};
        auto result = FindPairs(inputList, inputList2, 8);
        std::cout << "{1, 2, 3} {4, 5, 6} Target - 8 Result:" << std::endl;
        std::string output;
        for (std::vector<int>& pair : result)
        {
            for (int num : pair)
            {
                output.append(std::to_string(num));
                output.append(" ");
            }
            output.append("| ");
        }
        std::cout << output.c_str() << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "Interview question - Longest consecutive sequence" << std::endl;

        auto testLongestConsecutiveSequence = [](const std::vector<int>& inputList)
        {
            int result = LongestConsecutiveSequence(inputList);

            std::string contents;
            for (int num : inputList)
            {
                contents.append(std::to_string(num));
                contents.append(" ");
            }

            std::cout << "Input = { " << contents.c_str() << "}" << std::endl;
            std::cout << "Result: " << result << std::endl;
        };

        testLongestConsecutiveSequence(std::vector<int>{2,1,6,9,4,3});
        testLongestConsecutiveSequence(std::vector<int>{});
        testLongestConsecutiveSequence(std::vector<int>{1});
        testLongestConsecutiveSequence(std::vector<int>{2,2,2,2,2,2,2});
        testLongestConsecutiveSequence(std::vector<int>{1, -1, 3, 7, 2, 12, 11, -100, 8, 9});
        
        std::cout << std::endl;
    }

    return 0;
}