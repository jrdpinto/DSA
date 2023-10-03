#include "DoublyLinkedList.h"

int main()
{
    {
        DoublyLinkedList<int> testList{1, 2, 3, 4, 5};
        testList.Print();
        
        std::cout << "Appending 6, 7, 8" << std::endl;
        testList.Append(6);
        testList.Append(7);
        testList.Append(8);
        testList.Print();

        std::cout << "Appending 9, 10, 11" << std::endl;
        testList.Append(9, 10, 11);
        testList.Print();

        std::cout << "Prepending -1" << std::endl;
        testList.Prepend(-1);
        testList.Print();

        std::cout << "Prepending -2, -3, -4" << std::endl;
        testList.Prepend(-2, -3, -4);
        testList.Print();

        std::cout << "Setting '1' to 0" << std::endl;
        testList.Set(4, 0);
        testList.Print();

        std::cout << "Deleting elements in reverse" << std::endl;
        while (testList.GetLength() > 0)
        {
            testList.DeleteLast();
            testList.Print();
        }

        std::cout << std::endl;
    }

    {
        DoublyLinkedList<int> testList{1, 2, 3, 4, 5};
        testList.Print();

        std::cout << "Deleting elements from the front" << std::endl;
        while (testList.GetLength() > 0)
        {
            testList.DeleteFirst();
            testList.Print();
        }

        std::cout << std::endl;
    }

    {
        DoublyLinkedList<int> testList{1, 2, 3, 4, 5};
        testList.Print();

        std::cout << "Deleting random elements" << std::endl;
        while (testList.GetLength() > 0)
        {
            int randomIndex = rand() % testList.GetLength();
            std::cout << "Deleting index: " << randomIndex << std::endl;
            testList.Delete(randomIndex);
            testList.Print();
        }

        std::cout << std::endl;
    }

    {
        std::cout << "Running node retrieval test" << std::endl;

        DoublyLinkedList<int> testList{1, 2, 3, 4, 5};
        testList.Print();

        auto retrievalTest = [&](int targetIndex, int expectedValue) 
        {
            std::cout << "Retrieving node " << targetIndex << std::endl;

            DoublyLinkedList<int>::Node* node = testList.GetNode(targetIndex);
            if (node)
            {
                std::cout << "Retrieved " << (node->value == expectedValue ? "correct" : "incorrect") 
                    << " node with value : " << node->value << std::endl;
            }
            else
            {
                std::cout << "Node not retrieved" << std::endl;
            }
        };

        retrievalTest(-1, -1);
        retrievalTest(5, -1);
        retrievalTest(4, 5);
        retrievalTest(3, 4);
        retrievalTest(2, 3);
        retrievalTest(1, 2);
        retrievalTest(0, 1);

        std::cout << std::endl;
    }

    {
        std::cout << "Insertion test" << std::endl;

        DoublyLinkedList<int> testList;
        testList.Print();

        std::cout << "Inserting at head" << std::endl;
        testList.Insert(0, 0);
        testList.Print();

        std::cout << "Inserting at head" << std::endl;
        testList.Insert(0, -1);
        testList.Print();

        std::cout << "Inserting at tail" << std::endl;
        testList.Insert(1, 2);
        testList.Print();

        std::cout << "Inserting after tail" << std::endl;
        testList.Insert(testList.GetLength(), 3);
        testList.Print();

        std::cout << std::endl;
    }

    {
        std::cout << "Swap test" << std::endl;
        DoublyLinkedList<int> testList{1,2};
        testList.Print();

        testList.SwapFirstLast();
        testList.Print();

        testList.Append(3, 4, 5);
        testList.Print();
        testList.SwapFirstLast();
        testList.Print();

        testList.Clear();
        testList.SwapFirstLast();

        std::cout << std::endl;
    }

    {
        std::cout << "Node reversal" << std::endl;
        DoublyLinkedList<int> testList{1,2,3};
        testList.Print();

        std::cout << "Reversing list" << std::endl;
        testList.Reverse();
        testList.Print();

        std::cout << std::endl;
    }

    {
        auto palindromeTest = [](DoublyLinkedList<int>& list)
        {
            list.Print();
            std::cout << "List " << (list.IsPalindrome() ? "is " : "is not ") << "a palindrome" << std::endl;
            std::cout << std::endl;
        };

        std::cout << "Palindrome test" << std::endl;
        palindromeTest(DoublyLinkedList<int>{1});
        palindromeTest(DoublyLinkedList<int>{1,1});
        palindromeTest(DoublyLinkedList<int>{1,2,1});
        palindromeTest(DoublyLinkedList<int>{1,2,3});
        palindromeTest(DoublyLinkedList<int>{1,2,3,2,1});
        palindromeTest(DoublyLinkedList<int>{0,0,0});
        palindromeTest(DoublyLinkedList<int>());
    }

    {
        std::cout << "Swapping pairs test" << std::endl;
        auto swapPairsTest = [](DoublyLinkedList<int>& list)
        {
            list.Print();
            std::cout << "Swapping pairs" << std::endl;
            list.SwapPairs();
            list.Print();
        };

        swapPairsTest(DoublyLinkedList<int>{1, 2, 3, 4, 5});
        swapPairsTest(DoublyLinkedList<int>{1, 2, 3, 4});
        swapPairsTest(DoublyLinkedList<int>{1, 2});
    }

    return 0;
}