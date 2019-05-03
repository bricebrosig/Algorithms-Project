#include "../inc/graph.h"

// Graph Implementation using STL
int main()
{
	/* Let us create following weighted graph 
             10 
        0--------1 
        |  \     | 
       6|   5\   |15 
        |      \ | 
        2--------3 
            4       
	*/
	
	std::vector<edge> edges;

	edges.emplace_back(edge{0,1,10});
	edges.emplace_back(edge{0,2,6});
	edges.emplace_back(edge{0,3,5});
	edges.emplace_back(edge{1,3,15});
	edges.emplace_back(edge{2,3,4});

	Graph graph(edges);
  
    Graph mst = KruskalMST(graph);

	printf("mst printed here:\n");
	mst.print();
	return 0;
}