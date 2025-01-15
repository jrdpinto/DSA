#include <iostream>
#include <stack>
#include <string>

// Interview Question - Parentheses Balance
// Implement a function called isBalancedParentheses() that checks if the input string contains balanced parentheses.
// 
// Input:
// The function takes a constant reference to a string parentheses.
// 
// Output:
// The function should return a boolean value indicating whether the input string contains balanced parentheses or not.
// 
// Constraints:
// The input string may contain any printable ASCII characters, but the function should only consider the opening and
// closing parentheses '(' and ')' for determining balance.
// 
// Examples:
// Consider the following input string:
//     parentheses: "()"

// After calling isBalancedParentheses(parentheses), the result should be:
//     true
// 
// Consider the following input string:
//     parentheses: "(()))"
// 
// After calling isBalancedParentheses(parentheses), the result should be:
//     false
// 
// Consider the following input string:
//     parentheses: ")("
// 
// After calling isBalancedParentheses(parentheses), the result should be:
//     false

bool IsBalancedParentheses(const std::string_view parentheses) 
{
    std::stack<char> parenthesesStack;

    for (int i = 0; i < parentheses.size(); ++i)
    {
        if (parentheses[i] == '(')
        {
            parenthesesStack.push('(');
        }
        else if (parentheses[i] == ')')
        {
            if (parenthesesStack.empty())
            {
                // Exit early if the top of the stack is an open bracket
                return false;
            }
            parenthesesStack.pop();
        }
    }

    return parenthesesStack.empty();
}

// Interview question - Valid parentheses
// Source: Leet Code https://leetcode.com/problems/valid-parentheses/description/
//
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
//     Open brackets must be closed by the same type of brackets.
//     Open brackets must be closed in the correct order.
//     Every close bracket has a corresponding open bracket of the same type.
// 
// Example 1:
// Input: s = "()"
// Output: true
// 
// Example 2:
// Input: s = "()[]{}"
// Output: true
// 
// Example 3:
// Input: s = "(]"
// Output: false
// 
// Example 4:
// Input: s = "([])"
// Output: true
// 
// Constraints:
//     1 <= s.length <= 104
//     s consists of parentheses only '()[]{}'.

inline bool isOpenBracket(char c)
{
    return c == '(' || c == '[' || c == '{';
}

inline bool isMatchingBracket(char a, char b)
{
    bool isMatching = false;
    
    switch (a)
    {
        case '{':
        {
            isMatching = b == '}';
            break;
        }
        case '(':
        {
            isMatching = b == ')';
            break;
        }
        case '[':
        {
            isMatching = b == ']';
            break;
        }
    }

    return isMatching;
}

bool AreParenthesesValid(std::string_view parentheses)
{
    std::stack<char> parenthesesStack;

    if (parentheses.size() & 1)
    {
        // If the string size is odd, parentheses are imbalanced
        return false;
    }

    for (char c : parentheses)
    {
        if (isOpenBracket(c))
        {
            parenthesesStack.push(c);
        }
        else
        {
            if (parenthesesStack.empty())
            {
                return false;
            }
            else if (isMatchingBracket(parenthesesStack.top(), c))
            {
                parenthesesStack.pop();
            }
            else
            {
                parenthesesStack.push(c);
            }
        }
    }

    return parenthesesStack.empty();
}


int main()
{
    std::cout << "Balanced parentheses" << std::endl;

    {
        std::cout << "Running balanced parentheses tests" << std::endl;

        auto testCase = [](std::string_view testString, bool expectedOutput) {
            bool output = IsBalancedParentheses(testString);
            std::cout << "Testing string - " << testString << " Output: " << 
                (output ? "Balanced" : "Imbalanced") << 
                (expectedOutput != output ? "   FAILED" : "" ) << std::endl;
        };
        testCase("()", true);
        testCase("(", false);
        testCase(")", false);
        testCase(")(", false);
        testCase("(abc(deeewf))", true);
        testCase("(abc(deeewf)", false);
        testCase(")(abc(deeewf))", false);
        testCase("(abc(deeewf))()", true);
        testCase("(abc(deeewf)))", false);

        std::cout << std::endl;
    }

    {
        std::cout << "Running valid parentheses tests" << std::endl;

        auto testCase = [](std::string_view testString, bool expectedOutput) {
            bool output = AreParenthesesValid(testString);
            std::cout << "Testing string - " << testString << " Output: " << 
                (output ? "Balanced" : "Imbalanced") << 
                (expectedOutput != output ? "   FAILED" : "" ) << std::endl;
        };
        testCase("()", true);
        testCase("(", false);
        testCase(")", false);
        testCase(")(", false);
        testCase("(())", true);
        testCase("({)", false);
        testCase(")([])}", false);
        testCase("({})([])", true);
        testCase("[()]}", false);

        std::cout << std::endl;
    }

    return 0;
}