#include "HashTable.h"

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

    return 0;
}