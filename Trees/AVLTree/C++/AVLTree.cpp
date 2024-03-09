
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

                std::cout << "Tree is " << (tree.IsHeightBalanced() ? "height balanced" : 
                    "not height balanced") << std::endl;
            };

        avlTreeTest(std::vector<int>{3, 9, 20, 15, 7});
        avlTreeTest(std::vector<int>{3, 9, 7, 15, 20});
        avlTreeTest(std::vector<int>{20, 19, 18, 16, 8});
        avlTreeTest(std::vector<int>{20, 20, 19, 18, 16, 8});
    }

    return 0;
}