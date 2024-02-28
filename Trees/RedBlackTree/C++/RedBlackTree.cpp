
#include "RedBlackTree.h"
#include <vector>

int main()
{
    std::cout << "AVL Tree" << std::endl;

    {
        auto avlTreeTest = [] (std::vector<int>& values)
            {
                RedBlackTree<int> tree;
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