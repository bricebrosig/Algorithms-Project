#include "../inc/graph.h"

void Graph::print() {
    printf("Graph pretty print:\n");
    for(auto e : edgeSet) {
        printf("%d - %d : %f\n", e.src, e.dest, e.weight);
    }  
}

int Graph::insert_edge(edge e) {
    if(std::find(edgeSet.begin(), edgeSet.end(), e) != edgeSet.end()){
        edgeSet.push_back(e);

        if(std::find(vertexSet.begin(), vertexSet.end(), e.dest) == vertexSet.end()) // if we dont have the dest in vertex set
            vertexSet.push_back(e.dest);
        if(std::find(vertexSet.begin(), vertexSet.end(), e.src) == vertexSet.end()) // if we dont have the source in vertex set
            vertexSet.push_back(e.src);

        return 1;
    } 
    return 0;
}

int Graph::delete_edge(edge e) {
    return 0;
}

int find(std::vector<subset> subsets, int i) 
{ 
    // find root and make root as parent of i  
    // (path compression) 
    if (subsets[i].parent != i) 
        subsets[i].parent = find(subsets, subsets[i].parent); 
  
    return subsets[i].parent; 
} 

void Union(std::vector<subset> & subsets, int x, int y) 
{ 
    int xroot = find(subsets, x); 
    int yroot = find(subsets, y); 
  
    // Attach smaller rank tree under root of high  
    // rank tree (Union by Rank) 
    if (subsets[xroot].rank < subsets[yroot].rank) 
        subsets[xroot].parent = yroot; 
    else if (subsets[xroot].rank > subsets[yroot].rank){
        subsets[yroot].parent = xroot; 
     
        
  
    // If ranks are same, then make one as root and  
    // increment its rank by one 
    } else { 
        subsets[yroot].parent = xroot; 
        subsets[xroot].rank++;
        //subsets[yroot].rank++;
    } 

}

bool myComp(edge a, edge b) { 
    return a.weight < b.weight; 
}

Graph KruskalMST(Graph graph) 
{ 
    int V = graph.vertexSet.size(); 
    std::vector<edge> temp_edges = graph.edgeSet;
    std::vector<edge> result;  // edge set for the resultant graph (actually a tree)
    int e = 0;  // An index variable, used for result[] 
    int i = 0;  // An index variable, used for sorted edges 
  
    // Step 1:  Sort all the edges in non-decreasing  
    // order of their weight. If we are not allowed to  
    // change the given graph, we can create a copy of 
    // array of edges 
    //qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
    std::sort(temp_edges.begin(), temp_edges.end(), myComp);

    // Allocate memory for creating V subsets 
    //subset *subsets = (subset*) malloc( V * sizeof(subset) );
    std::vector<subset> subsets(V); 
  
    // Create V subsets with single elements 
    for (int v = 0; v < V; ++v) { 
        subsets[v].parent = v; 
        subsets[v].rank = 0; 
    }
  
    // Number of edges to be taken is equal to V-1 
    while (e < V - 1) { 
        // Step 2: Pick the smallest edge. And increment  
        // the index for next iteration 
        
        edge next_edge = temp_edges[i++];
        if(i > temp_edges.size())
        {
            printf("i is too big! e: %d, V-1: %d\n", e, V-1);
            Graph resultant_mst = Graph(result);
            return resultant_mst;
        }
        //printf("trying src: %d, dest: %d, i: %d, size: %d\n", next_edge.src, next_edge.dest, i, temp_edges.size());
        int x = find(subsets, next_edge.src); 
        //printf("Found X: %d\n", x);
        
        int y = find(subsets, next_edge.dest); 
        //printf("Found Y: %d\n", y);
  
        // If including this edge does't cause cycle, 
        // include it in result and increment the index  
        // of result for next edge 
        if (x != y) { 
            //result[e++] = next_edge;

            result.push_back(next_edge);
            Union(subsets, x, y); 
            e++;
        }
        // Else discard the next_edge 
        //e++;
        //printf("e = %d, V - 1: %d, i: %d, sizeofEdges: %d , x: %d y: %d\n", e, V -1, i, graph.getEdgeSet().size(), x, y);
    } 

    // print the contents of result[] to display the 
    // built MST 
    printf("Following are the edges in the constructed MST\n"); 
    for (auto r : result) 
        printf("%d -- %d == %f\n", r.src, r.dest, r.weight); 

    //now that result has what it needs, make the graph ( tree ) with that stuff
    Graph resultant_mst = Graph(result);

    return resultant_mst; 
}

// std::vector<edge> findCycle(Graph G)
// {
//     /*Do DFS*/
//     return;
// }