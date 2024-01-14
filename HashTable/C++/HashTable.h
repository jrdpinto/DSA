#pragma once
#include <array>
#include <functional>
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
            Set(pair.first, pair.second);
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
            Node* node = dataMap_[i];
            if (node)
            {
                std::cout << std::endl;
                std::cout << "Values at " << i << std::endl;
            }

            while(node != nullptr)
            {
                Node* next = node->next;
                std::cout << "Key: " << node->key << " Value: " << node->value << std::endl;
                node = next;
            }
        }
    }

    void Set(key_type key, value_type value)
    {
        size_t index = Hash(key);
        Node* newNode = new Node(key, value);

        Node* existingNode = dataMap_[index];
        if (existingNode)
        {
            existingNode->next = newNode;
        }
        else
        {
            dataMap_[index] = newNode;
        }
    }

private:
    static const int SIZE = 128;
    std::array<Node*, SIZE> dataMap_ = {nullptr};

    size_t Hash(key_type key)
    {
        return std::hash<key_type>{}(key) % SIZE;
    }
};