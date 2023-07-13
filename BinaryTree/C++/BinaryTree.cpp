#include "BinaryTree.h"

using namespace std;

int unsortedNumbers[] = { 0, 1, 3, 453, 233, 43, 123, 423 ,23, 102, 43, 42, 65, 4455, 20 };

int main()
{
	BinaryTreeNode<int> rootNode(0);
	for (int i = 0; i < sizeof(unsortedNumbers) / sizeof(int); ++i)
	{
		rootNode.Add(unsortedNumbers[i]);
	}

	return 0;
}
