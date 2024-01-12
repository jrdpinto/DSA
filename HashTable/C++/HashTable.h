#pragma once
#include <array>
#include <initializer_list>
#include <iostream>

template<typename key_type, typename value_type>
class HashTable
{
public:
    struct Node
    {
        key_type key;
        value_type value;

        Node* next = nullptr;

        Node(key_type key, value_type value) : key(key), value(value)
        {
        }
    };

    HashTable(std::initializer_list<std::pair<key_type, value_type>> initialList)
    {
        for (const auto& pair : initialList)
        {
            // TODO: Insert values
        }
    }

    ~HashTable()
    {
        for(Node* node : dataMap_)
        {
            while(node)
            {
                Node* next = node->next;
                delete(node);
                node = next;
            }
        }
    }

    void PrintTable()
    {
        for(int i = 0; i < SIZE; ++i)
        {
            std::cout << i << ": " << std::endl;
            Node* node = dataMap_[i];
            while(node != nullptr)
            {
                Node* next = node->next;
                std::cout << "Key: " << node->key << " Value: " << node->value << std::endl;
                node = next;
            }
        }
    }

private:
    static const int SIZE = 128;
    std::array<Node*, SIZE> dataMap_ = {nullptr};
};