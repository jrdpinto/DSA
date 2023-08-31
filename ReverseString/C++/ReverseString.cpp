// Source: The Coding Interview Bootcamp: Algorithms + Data Structures (Udemy)
// Given a string, return a new string with the reversed order of characters.
// 
// Examples:
// 
//     reverse('apple') === 'leppa'
//     reverse('hello') === 'olleh'
//     reverse('Greetings!') === '!sgniteerG'
// 
// You should put your implementation into the reverse function that was defined for you below. You don't need to call reverse yourself.
// Example of what your completed code should look like:
// 
//     function reverse (str) {
//       // Code to implement the reverse function
//     }

#include <iostream>
#include <utility>

void ReverseWithPointers(char* string)
{
    if (string == nullptr)
    {
        return;
    }

    size_t length = strlen(string);
    char* start = &string[0];
    char* end = &string[length-1];

    while (start < end)
    {
        std::swap(*start, *end);

        ++start;
        --end;
    }
}

void Reverse(char* string)
{
    if (string == nullptr)
    {
        return;
    }

    size_t length = strlen(string);

    for (size_t i = 0, indexToSwap = length - 1; i < indexToSwap; ++i, --indexToSwap)
    {
        std::swap(string[i], string[indexToSwap]);
    }
}

int main()
{
    char buffer[128];

    std::cout << "Reverse String" << std::endl;

    std::cout << "Enter a string to reverse" << std::endl;

    std::cin >> buffer;

    std::cout << "Entered string: " << buffer << std::endl;
    ReverseWithPointers(buffer);
    std::cout << "Reversed string: " << buffer << std::endl;

    return 0;
}