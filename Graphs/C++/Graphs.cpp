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

    {
        Graph testGraph;
        testGraph.AddNode("a");
        testGraph.AddNode("b");
        testGraph.AddNode("c");
        testGraph.AddNode("d");
        testGraph.AddNode("e");

        testGraph.AddEdge("a", "b");
        testGraph.AddEdge("a", "c");
        testGraph.AddEdge("a", "d");
        testGraph.AddEdge("d", "e");

        testGraph.RemoveNode("a");
    }

    return 0;
}