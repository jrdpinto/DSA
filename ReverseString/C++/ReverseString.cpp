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

#include "ReverseString.h"

void Reverse(char* string)
{
	char swap;
	size_t length = strlen(string);

	if (length > 0)
	{

	}
}

int main()
{
	char buffer[128];

	std::cout << "Reverse String" << std::endl;

	std::cout << "Enter a string to reverse" << std::endl;

	std::cin >> buffer;

	std::cout << "Entered string: " << buffer << " Reversed string: " << std::endl;

	return 0;
}