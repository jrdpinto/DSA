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
    }

    return 0;
}