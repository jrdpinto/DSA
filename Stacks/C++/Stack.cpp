#include "Stack.h"
#include <string>

// Interview Question - Reverse string
// Implement a function called reverseString() that reverses the input string using a stack data structure.
// 
// Input:
// The function takes a constant reference to a string str.
// 
// Output:
// The function should return a new string that is the reverse of the input string str.
// 
// Constraints:
// The input string may contain any printable ASCII characters.
// 
// Examples:
// Consider the following input string:
//     str: "hello"
// 
// After calling reverseString(str), the result should be:
// 
//     "olleh"
std::string ReverseString(std::string& inputString)
{
    std::string reversedString;

    Stack<char> charStack;
    for (int i = 0; i < inputString.size(); ++i)
    {
        charStack.Push(inputString[i]);
    }

    while (charStack.GetHeight() > 0)
    {
        reversedString += charStack.Pop();
    }

    return reversedString;
}

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

bool IsBalancedParentheses(const std::string& parentheses) 
{
    Stack<char> parenthesesStack;

    for (int i = 0; i < parentheses.size(); ++i)
    {
        if (parentheses[i] == '(')
        {
            parenthesesStack.Push('(');
        }
        else if (parentheses[i] == ')')
        {
            if (parenthesesStack.GetHeight() > 0 && parenthesesStack.Peek() == '(')
            {
                parenthesesStack.Pop();
            }
            else
            {
                parenthesesStack.Push(')');
            }
        }
    }

    return parenthesesStack.GetHeight() == 0;
}

// Interview Question - Sort Stack 
// 
// Implement a function called sortStack() that sorts a given stack of integers in ascending order using an
// additional stack.
// Input:
// The function takes a reference to a stack of integers inputStack, with an arbitrary size.
// 
// Output:
// The function should not return any value, but it should modify the input stack in-place such that the
// elements are sorted in ascending order, with the smallest element at the top.
// 
// Constraints:
// The input stack may contain positive or negative integers. The function must use only one additional
// stack for sorting purposes, and no other data structures are allowed.
// 
// Examples:
// Consider the following input stack:
//     inputStack:
//     5
//     2
//     7
//     1
// 
// After calling sortStack(inputStack), the input stack should be:
//     inputStack:
//     1
//     2
//     5
//     7

void SortStack(Stack<int>& inputStack)
{
    Stack<int> additionalStack;

    while (inputStack.GetHeight() > 0)
    {
        int temp = inputStack.Pop();
        if (additionalStack.GetHeight() == 0 || additionalStack.Peek() <= temp)
        {
            additionalStack.Push(temp);
        }
        else
        {
            while (additionalStack.GetHeight() > 0 && additionalStack.Peek() > temp)
            {
                inputStack.Push(additionalStack.Pop());
            }

            additionalStack.Push(temp);
        }
    }

    while (additionalStack.GetHeight() > 0)
    {
        inputStack.Push(additionalStack.Pop());
    }
}

int main()
{
    {
        std::cout << "Creating int stack" << std::endl;
        Stack<int> testStack{4,3,2,1};
        testStack.Print();

        std::cout << "Pushing values on to the stack" << std::endl;
        testStack.Push(0);
        testStack.Print();

        testStack.Push(-1);
        testStack.Print();

        std::cout << "Popping all elements" << std::endl;
        testStack.Print();
        while (testStack.GetHeight() > 0)
        {
            int poppedValue = testStack.Pop();
            std::cout << "Popped value: " << poppedValue << std::endl;
            testStack.Print();
        }
    }

    {
        std::cout << "Reverse string test" << std::endl;
        std::string inputString("Hello!");
        std::cout << "Input string " << inputString.c_str() << std::endl;
        std::cout << "Output: " << ReverseString(inputString).c_str() << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "Running balanced parentheses tests" << std::endl;

        auto testCase = [](const char* testString) {
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

    {
        std::cout << "Testing stack sort" << std::endl;

        auto testCase = [](Stack<int>& unsortedStack) {
            unsortedStack.Print();
            SortStack(unsortedStack);
            std::cout << "Output - " << std::endl;
            unsortedStack.Print();
            std::cout << std::endl;
        };

        testCase(Stack<int>{1, 7, 2, 5});
        testCase(Stack<int>{1,2,3});
        testCase(Stack<int>{});
        testCase(Stack<int>{-1, 3890,22, -18117, 2});
    }

    return 0;
}