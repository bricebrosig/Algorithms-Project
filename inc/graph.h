/*TODO:
Graph representation
    Insert
    Delete
    kruskal
    disjoint set
    Breadth First Search
        find cycles
*/

#include <stdlib.h>
#include <stdio.h>
#include <vector>

typedef struct edge{
    int src, dest, weight;
}edge;

typedef struct vertex{
    int value, degree;
}vertex;

//undirected and weighted graph represetation
//adjacency list format
class Graph
{
public:
    std::vector<edge> edgeSet;
    std::vector<vertex> vertexSet;

    Graph(); //default
    Graph(std::vector<edge>); //given and edgeset
    Graph(std::vector<vertex>); //given a vertex set
    Graph(std::vector<edge>, std::vector<vertex>); //given edges and vertices

    //some insertion and deletion functions
    insert_edge(edge);
    delete_edge(edge);
    insert_vertex(vertex);
    delete_vertex(vertex);
    
};

/*
    Given a graph, find the MST and return that tree
    as a graph object. 
*/
Graph KruskalMST(Graph);

