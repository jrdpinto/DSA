#include "BinaryTree.h"
#include <functional>

using namespace std;

int main()
{
    {
        int unsortedNumbers[] = { 0, 1, 3, 453, 233, 43, 123, 423 ,23, 102, 43, 42, 65, 4455, 20 };

        BinaryTree<int> testTree;
        for (int i = 0; i < sizeof(unsortedNumbers) / sizeof(int); ++i)
        {
            int number = unsortedNumbers[i];
            bool success = testTree.Insert(number);
            std::cout << "Value: " << number << " " << (success ? "inserted" : "not inserted") << std::endl;
        }

        auto containsTest = [&](int value) {
            std::cout << "Contains " << value << ": "<< (testTree.Contains(value) ? "True" : "False") << std::endl;
        }; 

        std::cout << std::endl;
        containsTest(-100);
        containsTest(0);
        containsTest(123);
        containsTest(121);
        containsTest(2);
        std::cout << std::endl;
    }

    {
        BinaryTree<int> testTree{10, 6, 14, 5, 8, 11, 18};

        std::cout << "Depth: " << testTree.Depth() << std::endl;

        std::cout << "Breadth first search: ";
        testTree.BreadthFirstSearch();

        std::cout << "Pre order traversal: ";
        testTree.DepthFirstPreOrderTraversal();

        std::cout << "Post order traversal: ";
        testTree.DepthFirstPostOrderTraversal();

        std::cout << "In order traversal: ";
        testTree.DepthFirstInOrderTraversal();

        std::cout << "Reverse order traversal: ";
        testTree.DepthFirstReverseOrderTraversal();
        
        std::cout << std::endl;
    }

    {
        auto heightBalanceTest = [] (std::function<bool(BinaryTree<int>&)> fn, BinaryTree<int>& tree,
         bool expectedValue) 
            {
                tree.DepthFirstInOrderTraversal();
                bool outcome = fn(tree);

                std::cout << "Tree " << (outcome ? "is " : "is not ") << "height balanced" 
                    << std::endl;
                std::cout << (expectedValue == outcome ? "CORRECT " : "WRONG ") << " Expected value: "
                    << expectedValue << std::endl;
                std::cout << std::endl;
            };

        std::cout << "Height balanced test using breadth first search" << std::endl;
        heightBalanceTest(&BinaryTree<int>::IsHeightBalanced, BinaryTree<int>{3, 9, 20, 15, 7}, false);
        heightBalanceTest(&BinaryTree<int>::IsHeightBalanced, BinaryTree<int>{10, 6, 14, 5, 8, 11, 18}, true);
        heightBalanceTest(&BinaryTree<int>::IsHeightBalanced, BinaryTree<int>{1,2,2,3,3,4,4}, false);

        std::cout << "Height balanced test using depth first post-order traversal" << std::endl;
        heightBalanceTest(&BinaryTree<int>::IsHeightBalanced_DFS, BinaryTree<int>{3, 9, 20, 15, 7}, false);
        heightBalanceTest(&BinaryTree<int>::IsHeightBalanced_DFS, BinaryTree<int>{10, 6, 14, 5, 8, 11, 18}, true);
        heightBalanceTest(&BinaryTree<int>::IsHeightBalanced_DFS, BinaryTree<int>{1,2,2,3,3,4,4}, false);
    }

    {
        // Invert binary tree
        std::cout << "Binary Tree inversion" << std::endl;
        BinaryTree<int> test{4,2,7,1,3,6,9};
        test.DepthFirstInOrderTraversal();

        test.InvertTree();
        std::cout << "Result: ";
        test.DepthFirstInOrderTraversal();
        std::cout << std::endl;
    }

    return 0;
}