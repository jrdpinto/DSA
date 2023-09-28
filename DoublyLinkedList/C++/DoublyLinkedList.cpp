#include "DoublyLinkedList.h"

int main()
{
    {
        DoublyLinkedList<int> testList{1, 2, 3, 4, 5};
        testList.PrintList();
        
        std::cout << "Appending 6, 7, 8" << std::endl;
        testList.Append(6);
        testList.Append(7);
        testList.Append(8);
        testList.PrintList();

        std::cout << "Appending 9, 10, 11" << std::endl;
        testList.Append(9, 10, 11);
        testList.PrintList();

        std::cout << "Prepending -1" << std::endl;
        testList.Prepend(-1);
        testList.PrintList();

        std::cout << "Prepending -2, -3, -4" << std::endl;
        testList.Prepend(-2, -3, -4);
        testList.PrintList();

        std::cout << "Deleting elements in reverse" << std::endl;
        while (testList.GetLength() > 0)
        {
            testList.DeleteLast();
            testList.PrintList();
        }

        std::cout << std::endl;
    }

    {
        DoublyLinkedList<int> testList{1, 2, 3, 4, 5};
        testList.PrintList();

        std::cout << "Deleting elements from the front" << std::endl;
        while (testList.GetLength() > 0)
        {
            testList.DeleteFirst();
            testList.PrintList();
        }
    }

    return 0;
}