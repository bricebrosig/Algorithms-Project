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

	/* and now this one
	
		1--2--3
		|     |
		7  6--5--4
	*/

	std::vector<edge> test;

	test.emplace_back(edge{1,2,1});
	test.emplace_back(edge{2,3,1});
	test.emplace_back(edge{3,5,1});
	test.emplace_back(edge{5,4,1});
	test.emplace_back(edge{5,6,1});
	test.emplace_back(edge{1,7,1});

	Graph testCycles(test);
	testCycles.print();
	std::vector<edge> temp = findCycle(testCycles, edge{2,6,1});

	return 0;
}