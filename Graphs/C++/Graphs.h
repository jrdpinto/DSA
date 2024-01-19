#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>

typedef std::unordered_set<std::string> edges;
typedef std::pair<std::string, edges> nodeEntry;

class Graph
{
public:
    Graph() = default;
    ~Graph() = default;

    bool AddNode(const std::string& node)
    {
        return nodes_.insert(nodeEntry(node, edges{})).second;
    }

private:
    std::unordered_map<std::string, edges> nodes_;
};