#include "../inc/graph.h"

void Graph::print() {
    printf("Graph pretty print:\n");
    for(auto e : edgeSet) {
        printf("\t%d - %d : %d\n", e.src, e.dest, e.weight);
    }  
}

/**
 * *insert_edge
 * first step is check if it already exists; if it does, bail
 * 
 * next we find the cycle in the given graph and get back a list of edges that are in that
 * cycle.
 * Then get the biggest edge from that cycle and delete it.
 *   if the biggest one is the one we want to add we can dip out early
 * 
 *   else, we gotta push back the new edge onto edge set, and then search through the edgeset for 
 *   the one that matches the biggest.
 *   when we find it, delete, and return
 */ 
int Graph::insert_edge(edge e) {
    if(std::find(edgeSet.begin(), edgeSet.end(), e) != edgeSet.end()) { // if it already exists in the graph
        printf("Did not find edge: %d-%d:%d in the graph\n", e.src, e.dest, e.weight);
        return 0; //get out we dont add it
    }

    std::vector<edge> cycle = findCycle(*this, e); //hold the edges from the cycles
    int biggest_weight = 0; //store the biggest
    int biggest_index = 0; //and the index of the biggest blah blah

    //get the highest weight edge
    for (int i = 0; i < (int) cycle.size(); i++) {
        if(cycle[i].weight > biggest_weight) {
            biggest_weight = cycle[i].weight;
            biggest_index = i;
        }
    }

    if(e == cycle[biggest_index]) {
        //new edge is the biggest so just dont add it and bail
        return 1;
    }
    else {
        //insert the new edge and delete the biggest
        edgeSet.push_back(e);
        //we shouldnt need to check the vertex set since they should exist but just to be safe here they are
        if(std::find(vertexSet.begin(), vertexSet.end(), e.dest) == vertexSet.end()) { // if we dont have the dest in vertex set
            vertexSet.push_back(e.dest);
        }
        if(std::find(vertexSet.begin(), vertexSet.end(), e.src) == vertexSet.end()) { // if we dont have the source in vertex set
            vertexSet.push_back(e.src);
        }

        for(auto i : edgeSet) { // look through all the edges
            if(i == cycle[biggest_index]) {
                printf("deleting edge: %d-%d:%d\n", i.src, i.dest, i.weight);
                 if(true_delete(i) == 0) {
                     printf("Delete had a problem!\n");
                 }
                 return 1;
            }
        }
    }

    return 0;
}

/**
 * get the edges from the original graph that are not in the mst
 * get the vertices that are in one of the disjoint trees
 * for each of the list edges
 *      see if the src XOR the dest is in the list of vertices
 *      if it is do the smallest test
 * TODO: test this function!
 */
int Graph::delete_edge(Graph original, edge e) {
    int smallestEdge = INT_MAX; // for tracking the smallest
    edge toAdd;
    std::vector<int> disjoint_vertices;
    std::map<int, bool> map;

    //get rid of the edge and then find the disjoint vertices
    true_delete(e);
    disjoint_vertices = breadFirstSearch(*this, e.src);

    /**
     * for everything in the original vertex add it to the map and set it to false meaning its not in the disjoint set
     * then for all of the disjoint vetices, go that index in the map and set it to true
     * *this is allow for fast look up in the next part
     */
    for(auto v : original.vertexSet)
        map.insert(std::pair<int, bool>(v, false));

    for(auto v : disjoint_vertices)
        map[v] = true;

    //for each of the edges, add the ones who have a src xor dest in the disjoint verices
    for(auto e : original.edgeSet) {
        if( (map[e.src]) ^ (map[e.dest]) ){
            if(e.weight < smallestEdge) {
                smallestEdge = e.weight;
                toAdd = e; //save that as the one that we will add to the tree
            }
        }
    }

    true_insert(toAdd); //add the smallest to the tree

    return 0;
}

std::vector<int> Graph::getAdjacencies(int s) 
{
    std::vector<int> retval;
    for(auto e : edgeSet) {
        if(e.src == s) {
            retval.push_back(e.dest);
        }
        if(e.dest == s) {
            retval.push_back(e.src);
        }
    }
    return retval;
}

int Graph::getWeight(int src, int dest)
{
    for(auto e : edgeSet) 
        if( (e.src == src && e.dest == dest) || (e.dest == src && e.src == dest) )
            return e.weight;

    return -1;
}

int Graph::true_insert(edge e)
{
    if(std::find(edgeSet.begin(), edgeSet.end(), e) != edgeSet.end()) //it already in there
        return 0;
    else {
        edgeSet.push_back(e);
        if(std::find(vertexSet.begin(), vertexSet.end(), e.dest) == vertexSet.end()) { // if we dont have the dest in vertex set
            vertexSet.push_back(e.dest);
        }
        if(std::find(vertexSet.begin(), vertexSet.end(), e.src) == vertexSet.end()) { // if we dont have the source in vertex set
            vertexSet.push_back(e.src);
        }
        return 1;
    }
    return 0;
}

int Graph::true_delete(edge e)
{
    if(std::find(edgeSet.begin(), edgeSet.end(), e) == edgeSet.end()) //it already in there
        return 0; //didint find it
    else {
        edgeSet.erase(std::find(edgeSet.begin(), edgeSet.end(), e));
        return 1;
    }
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
  
        int x = find(subsets, next_edge.src); 

        
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
    } 

    // print the contents of result[] to display the 
    // built MST 
    printf("Following are the edges in the constructed MST\n"); 
    for (auto r : result) 
        printf("%d -- %d == %d\n", r.src, r.dest, r.weight); 

    //now that result has what it needs, make the graph ( tree ) with that stuff
    Graph resultant_mst = Graph(result);

    return resultant_mst; 
}

std::vector<edge> findCycle(Graph G, edge e)
{
    std::vector<edge> retval; //vector that holds the edges to return 
    std::queue<int> queue; //the queue data structure for the bfs
    std::map<int, color> colorMap; //mapping vertices to their color
    std::map<int, int> parentMap; //mapping vertices to their parents
    int source = e.src; //the source of the cycle
    int search = e.dest; //the dest of the cycle
    int s; //need this for the bfs
    const int DEF_PARENT = -1; //* this a default parent value that should work... if it doesnt then change it

    /*set the colors and parents with default values*/
    for(auto i : G.vertexSet) {
        colorMap.insert(std::pair<int, color>(i, WHITE));
        parentMap.insert(std::pair<int, int>(i, DEF_PARENT));
    }

    //making the first node gray and pushing it onto the queue
    //as we have touched it but not finished it
    colorMap[source] = GRAY;
    queue.push(source);

    //a lovely bfs
    while(!queue.empty()) {
        s = queue.front();
        queue.pop();

        for (auto i : G.getAdjacencies(s)) {
            if(colorMap[i] == WHITE) {
                colorMap[i] = GRAY;
                parentMap[i] = s;
                queue.push(i);
            }
        }
        colorMap[s] = BLACK;
    }

    int i = search;
    while(parentMap[i] != DEF_PARENT){
        retval.push_back(edge{i, parentMap[i], G.getWeight(i, parentMap[i])});
        i = parentMap[i];
    }
    retval.push_back(e); // the actual one they wanted to add

    printf("Edges in the cycle:\n");
    for(auto e : retval) {
        printf("\t%d - %d : %d\n", e.src, e.dest, e.weight);
    }

    return retval;
}

/**
 * an ordinary bfs but it does it on a disjoint graph
 * only returning the nodes from one component so no need to be
 * alarmed that we are missing stuff.
 * motivation is that we want to know what is disjoint from the rest of a graph
 * for the delete so we know what edges to add back
 */
std::vector<int> breadFirstSearch(Graph G, int s)
{
    std::queue<int> queue; // queue data structure for our bfs
    std::vector<int> retval; // holds the visited vertices to return
    std::map<int, bool> visited; // holds if its visited or not
    for (auto v : G.vertexSet) { //init the visited map
        visited.insert(std::pair<int, bool>(v, false));
    }

    //just a classic bfs
    queue.push(s);
    while(!queue.empty()) {
        s = queue.front();
        queue.pop();
        for (auto i : G.getAdjacencies(s)) {
            if(visited[i] == false) {
                visited[i] = true;
                retval.push_back(i);
                queue.push(i);
            }
        }
    }
    return retval;
}