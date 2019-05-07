#include "../inc/graph.h"

// Graph Implementation using STL
int main(int argc, char** argv)
{

	if(argc != 2)
	{
		perror("Usage ./bin/proj_mst [filename].mtx");
		exit(1);
	}

	std::ifstream input;
	input.open(argv[1]);
	char firstChar[256];
	char throwaway[1024];
	int vec1, vec2;
	float weight;
	 std::vector<edge> edges;
	while(input >> firstChar)
	{
		if(firstChar[0] == '%')
		{
			input.getline(throwaway, 1024);
			printf("%s", throwaway);
		}
		else
		{
			sscanf(firstChar, "%d", &vec1);
			input >> vec2;
			input >> weight;
			//we can't have nodes with the same src and dest
			if(vec1 != vec2)
			{
				printf("adding : {%d, %d, %d}\n", vec1, vec2, (int) weight); 
				edges.emplace_back(edge{vec1, vec2, (int) weight});
			}
			
		}
		
	}

	/* Let us create following weighted graph 
             10 
        0--------1 
        |  \     | 
       6|   5\   |15 
        |      \ | 
        2--------3 		4------5
            4       		20
	*/
	
	
	printf("Finished with input\n");
	input.close();


	// edges.emplace_back(edge{0,1,10});
	// edges.emplace_back(edge{0,2,6});
	// edges.emplace_back(edge{0,3,5});
	// edges.emplace_back(edge{1,3,15});
	// edges.emplace_back(edge{2,3,4});
	// edges.emplace_back(edge{4,5, 20});

	Graph graph(edges);
	printf("Initialized graph\n");
  
    Graph mst = KruskalMST(graph);

	printf("mst printed here:\n");
	//mst.print();
	struct timeval before, after, result; //time for before, after, and subtracting the two
    gettimeofday(&before, NULL); //time before

	mst.delete_edge(graph, edge{817, 816, -47});
	mst.delete_edge(graph, edge{30, 27, -1});
	mst.delete_edge(graph, edge{327, 241, -89});
	mst.delete_edge(graph, edge{335, 330, -2});
	mst.delete_edge(graph, edge{9, 5, -4});
	mst.delete_edge(graph, edge{1093, 1091, -5});
	mst.delete_edge(graph, edge{547, 515, -59});
	mst.delete_edge(graph, edge{968, 465, -65});
	mst.delete_edge(graph, edge{516, 515, -416});
	mst.delete_edge(graph, edge{1081, 1074, -85});
	mst.delete_edge(graph, edge{1059, 677, -243});
	mst.delete_edge(graph, edge{1121, 670, -54});
	mst.delete_edge(graph, edge{1057, 654, -144});
	mst.delete_edge(graph, edge{318, 94, -110});
	mst.delete_edge(graph, edge{433, 416, -91});

	gettimeofday(&after, NULL); //time after8
    timersub(&after, &before, &result); //subtract the two times

	printf("Time for delete:\n\tsec: %li\n\tusec: %li\n\n", result.tv_sec, result.tv_usec);
	//mst.print();

	gettimeofday(&before, NULL); //time before

	mst.insert_edge(edge{817, 816, -47});
	mst.insert_edge(edge{30, 27, -1});
	mst.insert_edge(edge{327, 241, -89});
	mst.insert_edge(edge{335, 330, -2});
	mst.insert_edge(edge{9, 5, -4});
	mst.insert_edge(edge{1093, 1091, -5});
	mst.insert_edge(edge{547, 515, -59});
	mst.insert_edge(edge{968, 465, -65});
	mst.insert_edge(edge{516, 515, -416});
	mst.insert_edge(edge{1081, 1074, -85});
	mst.insert_edge(edge{1059, 677, -243});
	mst.insert_edge(edge{1121, 670, -54});
	mst.insert_edge(edge{1057, 654, -144});
	mst.insert_edge(edge{318, 94, -110});
	mst.insert_edge(edge{433, 416, -91});

	gettimeofday(&after, NULL); //time after8
    timersub(&after, &before, &result); //subtract the two times

	printf("Time for insert:\n\tsec: %li\n\tusec: %li\n\n", result.tv_sec, result.tv_usec);
	//mst.print();

	/* and now this one
	
		1--2--3
		|  !  |
		7  6--5--4

		NOTE: exclamation is the inserted edge for testing
	*/

	// printf("\n==testing insertion==\n\n");

	// std::vector<edge> test;

	// test.emplace_back(edge{1,2,2});
	// test.emplace_back(edge{2,3,2});
	// test.emplace_back(edge{3,5,3});
	// test.emplace_back(edge{5,4,2});
	// test.emplace_back(edge{5,6,2});
	// test.emplace_back(edge{1,7,1});

	// Graph testCycles(test);
	// testCycles.insert_edge(edge{2,6,1});
	// testCycles.print();

	// /*===deletion stuff below===*/

	/**
	 * lets do this graph
	 * 
	 * 8---1---2---3 -
	 * \  |    |   |  \
	 * 	7------6---5---4
	 */ 

	// printf("\n\ntesting deletion\n\n");

	// std::vector<edge> del_edges;
	// del_edges.emplace_back(edge{8,1,3});
	// del_edges.emplace_back(edge{1,2,1});
	// del_edges.emplace_back(edge{2,3,2});
	// del_edges.emplace_back(edge{3,4,2});
	// del_edges.emplace_back(edge{4,5,1});
	// del_edges.emplace_back(edge{5,6,2});
	// del_edges.emplace_back(edge{6,7,3});
	// del_edges.emplace_back(edge{7,8,1});
	// del_edges.emplace_back(edge{1,7,2});
	// del_edges.emplace_back(edge{2,6,1});
	// del_edges.emplace_back(edge{3,5,3});

	// Graph del_orig(del_edges);
	// del_orig.print();

	// Graph del_mst = KruskalMST(del_orig);
	// del_mst.print();
	// del_mst.delete_edge(del_orig, edge{2,3,2});

	// printf("After the delete\n\n");
	// del_mst.print();

	return 0;
}