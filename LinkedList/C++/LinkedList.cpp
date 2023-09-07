#include "LinkedList.h"

using namespace std;

int main()
{
    {
        LinkedList<int> testList{1, 2, 3, 4, 5};
        testList.printList();

        std::cout << "Prepending with 0" << std::endl;
        testList.prepend(0);
        testList.printList();

        std::cout << "Deleting last" << std::endl;
        testList.deleteLast();
        testList.printList();

        std::cout << "Deleting 2" << std::endl;
        testList.deleteNode(2);
        testList.printList();

        int numElements = testList.GetLength();
        for (int i = 0; i < numElements; ++i)
        {
            std::cout << "Deleting first element" << std::endl;
            testList.deleteFirst();
            testList.printList();
        }

        LinkedList<char> testList2{'h', 'e', 'l', 'l', 'o'};
        testList2.printList();

        numElements = testList2.GetLength();
        for (int i = 0; i < numElements; ++i)
        {
            std::cout << "Deleting last element" << std::endl;
            testList2.deleteLast();
            testList2.printList();
        }
    }

    return 0;
}
