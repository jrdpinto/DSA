#pragma once
#include <initializer_list>
#include <iostream>

template <class T>
class RedBlackTree
{
public:
    RedBlackTree() = default;

    RedBlackTree(std::initializer_list<T> initialList)
    {
        for (const T& value : initialList)
        {
        }
    }

    ~RedBlackTree()
    {
        
    }

private:
};