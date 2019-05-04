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
		|  !  |
		7  6--5--4

		NOTE: exclamation is the inserted edge for testing
	*/

	printf("\n==testing insertion==\n\n");

	std::vector<edge> test;

	test.emplace_back(edge{1,2,2});
	test.emplace_back(edge{2,3,2});
	test.emplace_back(edge{3,5,3});
	test.emplace_back(edge{5,4,2});
	test.emplace_back(edge{5,6,2});
	test.emplace_back(edge{1,7,1});

	Graph testCycles(test);
	testCycles.insert_edge(edge{2,6,1});
	testCycles.print();

	return 0;
}