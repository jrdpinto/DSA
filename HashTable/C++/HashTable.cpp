#include "HashTable.h"

int main()
{
    {
        HashTable<std::string, int> test{{"blah", 1}};
        test.PrintTable();
    }

    return 0;
}