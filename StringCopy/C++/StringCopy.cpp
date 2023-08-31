// Source: https://www.computerenhance.com/p/microsoft-intern-interview-question-ab7

#include <iostream>

void StringCopy(char* from, char* to)
{
    // The assignment expression returns the value that was assigned. When
    // this value is '\0', the expression evaluations to false, which
    // terminates the loop.
    for (int i = 0; to[i] = from[i]; ++i);
}

// Assuming both strings are properly null - terminated
void StringCopy_BoundsCheck(char* from, char* to)
{
    for (int i = 0; from[i] != '\0'; ++i)
    {
        if (to[i] != '\0')
        {
            to[i] = from[i];
        }
        else
        {
            std::cout << "Error: Destination is smaller than source" << std::endl;
            break;
        }
    }
}

void StringMemCopy(char* from, char* to, size_t destinationSize)
{
    size_t sourceSize = strlen(from);
    size_t numCharsToCopy = std::min(sourceSize, destinationSize-1);

    memcpy(to, from, numCharsToCopy);

    if (destinationSize < sourceSize)
    {
        to[destinationSize - 1] = '\0';
    }
}

void PrintStrings(char* from, char* to)
{
    std::cout << "Original: " << from << std::endl;
    std::cout << "Destination: " << to << std::endl;
}

int main()
{
    char* original = "Test";
    char* second = "Second Test";
    char destination[5] = "";

    PrintStrings(original, destination);
    StringCopy(original, destination);
    PrintStrings(original, destination);

    StringCopy_BoundsCheck(second, destination);
    PrintStrings(second, destination);

    StringMemCopy(second, destination, sizeof(destination));

    return 0;
}