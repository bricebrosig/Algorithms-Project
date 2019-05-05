#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include "limits.h"

enum color {WHITE, GRAY, BLACK}; //simple enum for the color tracking in the bfs

/**
 * edge representation as a src, dest, and weight
 * has == overloaded for easy comparison
 */ 
typedef struct edge {
    int src, dest;
    float weight;

    bool operator==(const edge& e) {
        return ((src == e.src) && (dest == e.dest) && (weight == e.weight))
                || ((src == e.dest) && (dest == e.src) && (weight == e.weight));
    }
}edge;

/**
 * subset for the kruskal algorithm
 */ 
typedef struct subset {
    int parent, rank;
}subset;

/**
 * * Class Graph
 * edgeset & vertex set representaion of a graph
 * has operations for insert and delete as well as an insert and delete
 * that will maintain the integrity of the mst
 * 
 * NOTE:that we have two functions for insert and delete.
 *      The two that start with "true", true_delete() and true_insert() are 
 *      regular insertion and deletion. That is, they just find what you ask and they
 *      insert or delete, respectively.
 * 
 *      The other two, insert_edge and delete_edge, assume that th graph is an mst and will
 *      maintain the integrity of the mst when called. That is, they will do the desired operation
 *      but also add a new edge to the mst or rebuild the mst should it become disjoint.
 * 
 * TODO: have this graph duplicate all the edges backwards as it is undirected...
 */ 
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

    //TODO: think about changing these to some new more informative names since they do extra stuff
    /**
     * @brief: this is the modified insert that checks for a cycle first
     * @param egde e: takes the edge that is to be inserted
     * @return: an int as status; 1 for inserted, 0 for not inserted
     */
    int insert_edge(edge e);

    /**
     * @brief: delete that considered the integrity of the mst. upon deleting it will
     *          repair the mst
     * @param edge e: takes the edge that is to be deleted
     * @return: int that is the status; 1 for delted, 0 for not
     */
    int delete_edge(edge e);

    /**
     * @brief: true insert simply puts an edge into the graph without consideration of the mst
     * @param edge e: takes the edge that is to be inserted
     * @return: returns an int as status of the insertion; 1 for inserted, 0 for not
     */
    int true_insert(edge);

    /**
     * @brief: true_dele simply removes an edge from the graph without consideration of the mst
     * @param edge e: takes the edge that is to be deleted
     * @return: int that is the status of the deletion; 1 for good and 0 for bad
     */ 
    int true_delete(edge);

    /**
     * @brief: looks through edgelist to find what is adjacent to the vertex given
     * @param: value of the node from which we want to find the adjacencies
     * @returns: a vector of ints where each int are the values of the adjacent nodes
    */
    std::vector<int> getAdjacencies(int v);
    
    /**
     * !this might need to change to a float
     * @brief: given the source and destination of the edge, gets the wieght asociated
     * @param int src: the src of the edge in question
     * @param int dest: the dest of the edge in question
     * @return: the weight of the given src and destination;
     *          returns -1 if its not found
     */
    int getWeight(int src, int dest);

    /**
     * @brief: simple pretty print for the graph. Walks through edge set and prints the src
     *          dest, and weight associated on each line
     * @return: void; just prints to terminal
     */ 
    void print();
};

/*==========UTILITY_FUNCITONS============*/

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


 