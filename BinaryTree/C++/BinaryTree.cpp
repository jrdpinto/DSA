#include "BinaryTree.h"

using namespace std;

int main()
{
    int unsortedNumbers[] = { 0, 1, 3, 453, 233, 43, 123, 423 ,23, 102, 43, 42, 65, 4455, 20 };

    BinaryTreeNode<int> rootNode;
    for (int i = 0; i < sizeof(unsortedNumbers) / sizeof(int); ++i)
    {
        int number = unsortedNumbers[i];
        bool success = rootNode.Insert(number);
        std::cout << "Value: " << number << " " << (success ? "inserted" : "not inserted") << std::endl;
    }

    return 0;
}
