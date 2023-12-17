#include <stack>

using namespace std;

template <typename T>
class QueueUsingTwoStacks 
{
private:
    stack<T> stack1, stack2;

public:
    int Front() 
    {
        while (!stack1.empty()) 
        {
            stack2.push(stack1.top());
            stack1.pop();
        }

        if (stack2.empty()) 
        {
            throw std::underflow_error("Front() called on empty queue");
        }

        return stack2.top();
    }

    bool IsEmpty() 
    {
        return stack1.empty() && stack2.empty();
    }

    void Print()
    {
        if (stack1.empty() && stack2.empty())
        {
            return;
        }

        std::stringstream ss;
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }

        while (!stack2.empty())
        {
            T temp = stack2.top();
            ss << temp;
            stack1.push(temp);
            stack2.pop();

            if (!stack2.empty())
            {
                ss << ", ";
            }
        }

        std::cout << "Values: " << ss.str() << std::endl;
    }

    // Interview questions - Queue Using Stacks: Enqueue
    // In a typical queue, the enqueue operation is used to add an item to the end of the queue. In this
    // problem, you are required to implement the enqueue method, but there's a twist. The underlying
    // data structure is not a typical array or linked list; instead, you are using two stacks 
    // (stack1 and stack2) to simulate the behavior of a queue.
    // 
    // Background:
    // A stack is a Last-In-First-Out (LIFO) data structure. A queue, on the other hand, is a
    // First-In-First-Out (FIFO) data structure. The challenge here is to use the properties of
    // two stacks to simulate the behavior of a queue. Specifically, you will be working with the
    // enqueue operation, which should add items to the end of the simulated queue.
    // 
    // You're provided with a partial implementation of the QueueUsingTwoStacks class. Here's what you have:
    //     A front method that retrieves the front element of the queue without removing it.
    //     An isEmpty method that checks if the queue is empty.
    //     A partially implemented enqueue method.
    // 
    // The two stacks are represented by stack1 and stack2.
    // 
    // Task:
    // Complete the enqueue method of the QueueUsingTwoStacks class.
    // 
    // Constraints:
    //     The enqueue operation should have a time complexity of O(1). This means you can only use
    //     constant-time operations in its implementation.
    //     You can only use standard stack operations: push, pop, top, and empty.
    //     You should not use any other data structures or helper methods.

    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This method adds a new value to the end of the    |
    //   |   queue (enqueue) using 'stack1'.                   |
    //   | - Return type: void                                 |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Use 'stack1' to enqueue a new value.              |
    //   | - Simply push the new value onto 'stack1'.          |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    void Enqueue(T value)
    {
        while (!stack2.empty()) 
        {
            stack1.push(stack2.top());
            stack2.pop();
        }

        stack1.push(value);
    }

    template <typename U, typename... Args> 
    void Enqueue(U first, Args... args)
    {
        Enqueue(first);
        Enqueue(args...);
    }

    // Interview questions: Queue Using Stacks Dequeue
    // 
    // In the realm of data structures, a queue represents a First-In-First-Out (FIFO) mechanism, 
    // where the dequeue operation is used to remove the front-most item. Your task is to 
    // implement this dequeue operation, but not with a standard queue structure. The challenge
    // is to implement this operation using two stacks (stack1 and stack2) to simulate the
    // behavior of a queue.
    // 
    // Background:
    // You're provided with the QueueUsingTwoStacks class that uses two stacks (stack1 and stack2)
    // to simulate the operations of a queue. The class contains:
    //
    //     A front method that returns the front-most item of the queue without removing it.
    //     An isEmpty method that checks if the queue is empty.
    //     An enqueue method that adds an item to the end of the queue.
    //     A partially implemented dequeue method that you need to perfect.
    // 
    // Task:
    // Your mission is to perfect the dequeue method of the QueueUsingTwoStacks class, ensuring
    // that it adheres to the behavior of a typical queue's dequeue operation.
    // 
    // Constraints:    // 
    //     You should strive for optimal time complexity.
    //     Only standard stack operations (push, pop, top, and empty) are allowed.
    //     No additional data structures or helper methods should be used.
    // 
    // Tips:
    //     Reflect on the unique LIFO property of a stack and how using two of them can simulate
    //     the FIFO nature of a queue.
    //     Examine the front method carefully. It provides a clue on how to retrieve (and remove)
    //     the front-most item using the two stacks. For dequeue, focus on how to effectively
    //     remove the front-most item. Remember, in our setup, stack1 mainly deals with the
    //     enqueue operation, and stack2 handles the dequeue and front operations. If stack2 is
    //     empty and a dequeue operation is requested, the items from stack1 must be transferred
    //     to stack2 in a manner that the front-most item in the queue becomes accessible at the
    //     top of stack2.

    void Dequeue()
    {
        if (IsEmpty())
        {
            return;
        }

        while (!stack1.empty()) 
        {
            stack2.push(stack1.top());
            stack1.pop();
        }

        stack2.pop();
    }
};