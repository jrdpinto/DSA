#include "LinkedList.h"

using namespace std;

int main()
{
    {
        LinkedList<int> testList{1, 2, 3, 4, 5};
        testList.printList();

        LinkedList<char> testList2{'h', 'e', 'l', 'l', 'o'};
        testList2.printList();
    }

    return 0;
}
