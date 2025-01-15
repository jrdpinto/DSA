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
            if (parenthesesStack.size() > 0 && parenthesesStack.top() == '(')
            {
                parenthesesStack.pop();
            }
            else
            {
                parenthesesStack.push(')');
            }
        }
    }

    return parenthesesStack.size() == 0;
}

int main()
{
    std::cout << "Balanced parentheses" << std::endl;

    {
        std::cout << "Running balanced parentheses tests" << std::endl;

        auto testCase = [](std::string_view testString) {
            std::cout << "Testing string - " << testString << " Output: " << 
                (IsBalancedParentheses(testString) ? "Balanced" : "Imbalanced") << std::endl;
        };
        testCase("()");
        testCase("(");
        testCase(")");
        testCase(")(");
        testCase("(abc(deeewf))");
        testCase("(abc(deeewf)");
        testCase(")(abc(deeewf))");
        testCase("(abc(deeewf))()");
        testCase("(abc(deeewf)))");

        std::cout << std::endl;
    }

    return 0;
}