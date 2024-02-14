#include "BinaryTree.h"

using namespace std;

int main()
{
    {
        int unsortedNumbers[] = { 0, 1, 3, 453, 233, 43, 123, 423 ,23, 102, 43, 42, 65, 4455, 20 };

        BinaryTree<int> testTree;
        for (int i = 0; i < sizeof(unsortedNumbers) / sizeof(int); ++i)
        {
            int number = unsortedNumbers[i];
            bool success = testTree.Insert(number);
            std::cout << "Value: " << number << " " << (success ? "inserted" : "not inserted") << std::endl;
        }

        auto containsTest = [&](int value) {
            std::cout << "Contains " << value << ": "<< (testTree.Contains(value) ? "True" : "False") << std::endl;
        }; 

        std::cout << std::endl;
        containsTest(-100);
        containsTest(0);
        containsTest(123);
        containsTest(121);
        containsTest(2);
        std::cout << std::endl;
    }

    {
        BinaryTree<int> testTree{10, 6, 14, 5, 8, 11, 18};
        testTree.BreadthFirstSearch();
    }

    return 0;
}