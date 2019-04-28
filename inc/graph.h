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
#include <algorithm>

typedef struct edge {
    int src, dest, weight;
}edge;

typedef struct subset {
    int parent, rank;
}subset;

//undirected and weighted graph represetation
//adjacency list format
class Graph
{
public:
    std::vector<edge> edgeSet;
    std::vector<int> vertexSet; 

    Graph() : edgeSet(std::vector<edge>()), vertexSet(std::vector<int>()) {} //default
    Graph(std::vector<edge> e) : edgeSet(e), vertexSet(std::vector<int>()) 
    {
        for(auto edge : e) {
            if(std::find(vertexSet.begin(), vertexSet.end(), edge.dest) == vertexSet.end()) { // if we dont have the dest in vertex set
                vertexSet.push_back(edge.dest);
            }
            if(std::find(vertexSet.begin(), vertexSet.end(), edge.src) == vertexSet.end()) { // if we dont have the source in vertex set
                vertexSet.push_back(edge.src);
            }
        }
    } //given and edgeset
    Graph(std::vector<int> v) : edgeSet(std::vector<edge>()), vertexSet(v) {} //given a vertex set
    Graph(std::vector<edge> e, std::vector<int> v) : edgeSet(e), vertexSet(v) {} //given edges and vertices

    //some insertion and deletion functions
    int insert_edge(edge e);
    int delete_edge(edge e);
    int insert_vertex(int v);
    int delete_vertex(int v);

    //a pretty print for the graph
    void print();
};

// A utility function to find set of an element i 
// (uses path compression technique) 
int find(std::vector<subset> subsets, int i);

// A function that does union of two sets of x and y 
// (uses union by rank) 
void Union(std::vector<subset> subsets, int x, int y);

// Compare two edges according to their weights. 
// Used in qsort() for sorting an array of edges 
bool myComp(edge a, edge b);


//Given a graph, find the MST and return that tree
//as a graph object. 
Graph KruskalMST(Graph);


 