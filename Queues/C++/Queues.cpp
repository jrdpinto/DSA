#include "Queues.h"
#include "QueueUsingStacks.h"

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

        std::cout << std::endl;
    }

    {
        std::cout << "Testing queue with stacks" << std::endl;
        QueueUsingTwoStacks<int> test;
        test.Enqueue(1);
        test.Enqueue(2, 3, 4, 5, 6);
        test.Print();
        std::cout << std::endl;

        std::cout << "Testing dequeue" << std::endl;
        test.Dequeue();
        test.Print();
        std::cout << std::endl;
    }

    {
        std::cout << "Enqueuing values of 1 and 2, then dequeuing, then enqueuing values of 3 and 4, then dequeuing again:\n";
        QueueUsingTwoStacks<int> test;
        test.Enqueue(1);
        test.Enqueue(2);
        test.Dequeue();
        test.Enqueue(3);
        test.Enqueue(4);
        test.Dequeue();

        int frontValue = test.Front();
        std::cout << "Front value: " << frontValue << std::endl;
        test.Dequeue();
        frontValue = test.Front();
        std::cout << "Front value: " << frontValue << std::endl;
        test.Dequeue();
    }

    return 0;
}