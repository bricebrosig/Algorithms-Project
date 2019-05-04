#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include "limits.h"

enum color {WHITE, GRAY, BLACK};

typedef struct edge {
    int src, dest, weight;

    bool operator==(const edge& e) {
        return (src == e.src) && (dest == e.dest) && (weight == e.weight);
    }
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

    /**
     *add a new edge to edge list if it doesnt already exist
     *returns an int that is the status
     */
    int insert_edge(edge e);
    int delete_edge(edge e);

    /**
     * @brief: looks through edgelist to find what is adjacent to the vertex given
     * @param: value of the node from which we want to find the adjacencies
     * @returns: a vector of ints where each int are the values of the adjacent nodes
    */
    std::vector<int> getAdjacencies(int v);
    
    /**
     * !this might need to change to a float
     */
    int getWeight(int src, int dest);

    //a pretty print for the graph
    void print();
};

// A utility function to find set of an element i 
// (uses path compression technique) 
int find(std::vector<subset> subsets, int i);

// A function that does union of two sets of x and y 
// (uses union by rank) 
void Union(std::vector<subset> &subsets, int x, int y);

// Compare two edges according to their weights. 
// Used in qsort() for sorting an array of edges 
bool myComp(edge a, edge b);


//Given a graph, find the MST and return that tree
//as a graph object. 
Graph KruskalMST(Graph);

/**
 * @brief: a BFS that takes a Graph and an edge that got added by insert
 *          uses the classic color bfs to track parents to get a cycle in the graph
 * @param Graph: takes a graph that is assumed to be an mst
 * @param edge: takes an edge that was added by an insert, finds the cycle in the graph that connects
 *              the two
 * @returns: a vector of edges that are the edges in the cycle that would be formed by adding the edged passed
 * @requires: that the graph passed is an mst... not really required but in the context of this program
 *              that needs to happen.
 */
std::vector<edge> findCycle(Graph, edge);


 