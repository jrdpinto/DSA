#include "Graphs.h"

int main()
{
    
    {
        Graph testGraph;
        testGraph.AddNode("A");
        testGraph.AddNode("A");
        testGraph.AddNode("B");

        testGraph.AddEdge("A", "B");
        testGraph.AddEdge("A", "B");

        testGraph.RemoveEdge("A", "B");
    }

    return 0;
}