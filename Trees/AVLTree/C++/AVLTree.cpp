
#include "AVLTree.h"
#include <vector>
#include <iostream>

int main()
{
    std::cout << "AVL Tree" << std::endl;

    {
        auto avlTreeTest = [] (const std::vector<int>& values)
            {
                AVLTree<int> tree;
                std::cout << "Inserting: ";
                for (int value : values)
                {
                    std::cout << value << " ";
                    tree.Insert(value);
                }
                std::cout << std::endl;

                tree.DepthFirstInOrderTraversal();
                std::cout << "Tree is " << (tree.IsHeightBalanced() ? "height balanced" : 
                    "not height balanced") << std::endl;
                std::cout << "Depth: " << tree.Depth() << std::endl;
                std::cout << std::endl;
            };

        avlTreeTest({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
        avlTreeTest({3, 9, 20, 15, 5});
        avlTreeTest({3, 9, 7, 15, 20});
        avlTreeTest({20, 19, 18, 16, 8});
        avlTreeTest({20, 20, 19, 18, 16, 8});
    }

    return 0;
}