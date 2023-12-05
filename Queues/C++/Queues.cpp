#include "Queues.h"

int main()
{
    {
        Queue<int> testQueue;

        std::cout << "Testing 'Enqueue()'" << std::endl;
        testQueue.Enqueue(1);
        testQueue.Enqueue(2);
        testQueue.Enqueue(3);
        testQueue.Print();
        std::cout << "Emptying queue" << std::endl;
        testQueue.Clear();
        std::cout << "Length: " << testQueue.GetLength() << std::endl;
        std::cout << std::endl;

        std::cout << "Testing variadic 'Enqueue()'" << std::endl;
        testQueue.Enqueue(4, 5, 6, 7);
        testQueue.Print();
        std::cout << std::endl;

        std::cout << "Testing 'Dequeue()'" << std::endl;
        while (testQueue.GetLength() > 0)
        {
            int value = testQueue.Dequeue();
            testQueue.Print();
            std::cout << "Value removed: " << value << std::endl;
        }
    }

    return 0;
}