#include "LinkedList.h"

using namespace std;

int main()
{
    {
        LinkedList<int> testList{1, 2, 3, 4, 5};
        testList.PrintList();

        std::cout << "Prepending with 0" << std::endl;
        testList.Prepend(0);
        testList.PrintList();

        std::cout << "Reverse" << std::endl;
        testList.Reverse();
        testList.PrintList();

        std::cout << "Deleting last" << std::endl;
        testList.DeleteLast();
        testList.PrintList();

        std::cout << "Deleting 2" << std::endl;
        testList.DeleteNode(2);
        testList.PrintList();

        int numElements = testList.GetLength();
        for (int i = 0; i < numElements; ++i)
        {
            std::cout << "Deleting first element" << std::endl;
            testList.DeleteFirst();
            testList.PrintList();
        }

        LinkedList<char> testList2{'h', 'e', 'l', 'l', 'o'};
        testList2.PrintList();

        std::cout << "Inserting character" << std::endl;
        testList2.Insert(testList2.GetLength() - 1, 'o');
        testList2.PrintList();
        testList2.Insert(0, ' ');
        testList2.PrintList();
        testList2.Insert(0, 'y');
        testList2.PrintList();
        testList2.Insert(0, 'h');
        testList2.PrintList();
        testList2.Insert(0, 'W');
        testList2.PrintList();

        numElements = testList2.GetLength();
        for (int i = 0; i < numElements; ++i)
        {
            std::cout << "Deleting first element" << std::endl;
            testList2.DeleteNode(0);
            testList2.PrintList();
        }
    }

    return 0;
}
