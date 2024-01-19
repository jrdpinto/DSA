#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>

typedef std::unordered_set<std::string> Edges;
typedef std::pair<std::string, Edges> NodeEntry;

class Graph
{
public:
    Graph() = default;
    ~Graph() = default;

    bool AddNode(const std::string& node)
    {
        return nodes_.insert(NodeEntry(node, Edges{})).second;
    }

    bool AddEdge(const std::string& node1, const std::string& node2)
    {
        if (nodes_.count(node1) == 0 || nodes_.count(node2) == 0)
        {
            return false;
        }

        bool success = true;
        success &= nodes_[node1].insert(node2).second;
        success &= nodes_[node2].insert(node1).second;
        
        return success;
    }

private:
    std::unordered_map<std::string, Edges> nodes_;
};