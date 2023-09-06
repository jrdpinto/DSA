#include "LinkedList.h"

using namespace std;

int main()
{
    {
        LinkedList<int> testList{1, 2, 3, 4, 5};
        testList.printList();
        testList.prepend(0);
        testList.printList();

        LinkedList<char> testList2{'h', 'e', 'l', 'l', 'o'};
        testList2.printList();

        int numElements = testList2.GetLength();
        for (int i = 0; i < numElements; ++i)
        {
            std::cout << "Deleting last element" << std::endl;
            testList2.deleteLast();
            testList2.printList();
        }
    }

    return 0;
}
