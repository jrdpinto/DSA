
#include "RedBlackTree.h"
#include <iostream>
#include <vector>

int main()
{
    std::cout << "RedBlack Tree" << std::endl;

    {
        auto redBlackTreeTest = [] (const std::vector<int>& list) 
            {
                RedBlackTree<int> tree;
                std::cout << "Creating tree: { ";
                for (int value : list)
                {
                    std::cout << value << " ";
                    tree.Insert(value);
                }
                std::cout << "}" << std::endl;

                tree.DepthFirstInOrderTraversal();
                std::cout << "Height balanced: " << (tree.IsHeightBalanced() ? "True" : "False") << std::endl;
                std::cout << "Depth: " << tree.Depth() << std::endl;
                std::cout << std::endl;
            };

        redBlackTreeTest({3, 9, 20, 15, 7});
        redBlackTreeTest({10, 6, 14, 5, 8, 11, 18});
        redBlackTreeTest({1, 2, 2, 3, 3, 4, 4});
        redBlackTreeTest({20, 19, 18, 16, 8});
        redBlackTreeTest({1, 2, 3, 4, 5, 6, 7, 8});
    }

    return 0;
}