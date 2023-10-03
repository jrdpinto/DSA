#include "Stack.h"

int main()
{
    {
        std::cout << "Creating int stack" << std::endl;
        Stack<int> testStack{4,3,2,1};
        testStack.Print();

        std::cout << "Pushing values on to the stack" << std::endl;
        testStack.Push(0);
        testStack.Print();

        testStack.Push(-1);
        testStack.Print();

        std::cout << "Popping all elements" << std::endl;
        testStack.Print();
        while (testStack.GetHeight() > 0)
        {
            int poppedValue = testStack.Pop();
            std::cout << "Popped value: " << poppedValue << std::endl;
            testStack.Print();
        }
    }

    return 0;
}