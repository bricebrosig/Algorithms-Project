#include "../inc/graph.h"

/**
 * A function to handle the insert and delete of the large data set
 * will output to a file
 */
void bigGraph();
/**
 * A function to handle the insert and delete of the small data set
 * will output to a file
 */
void smallGraph();
/**
 * A function that does very small graphs for test purposes
 * will output to terminal
 */
void testData();

// Graph Implementation using STL
int main(int argc, char** argv)
{
	bigGraph();
	smallGraph();
	testData();
	return 0;
}

void bigGraph()
{
	std::ifstream input;
	input.open("graphFiles/1138_bus.mtx");
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
			//printf("%s\n", throwaway);
		}
		else
		{
			sscanf(firstChar, "%d", &vec1);
			input >> vec2;
			input >> weight;
			//we can't have nodes with the same src and dest
			if(vec1 != vec2)
			{
				//printf("adding : {%d, %d, %d}\n", vec1, vec2, (int) weight); 
				edges.emplace_back(edge{vec1, vec2, (int) weight});
			}
			
		}
		
	}
	input.close();

	printf("\n\n===Large graph (1138 nodes)===\n");
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
}

void smallGraph()
{
	std::ifstream input;
	input.open("graphFiles/494_bus.mtx");
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
			//printf("%s\n", throwaway);
		}
		else
		{
			sscanf(firstChar, "%d", &vec1);
			input >> vec2;
			input >> weight;
			//we can't have nodes with the same src and dest
			if(vec1 != vec2)
			{
				//printf("adding : {%d, %d, %d}\n", vec1, vec2, (int) weight); 
				edges.emplace_back(edge{vec1, vec2, (int) weight});
			}
			
		}
		
	}
	input.close();

	printf("\n\n===Small graph (494 nodes)===\n");

	Graph graph(edges);
	printf("Initialized graph\n");
  
    Graph mst = KruskalMST(graph);

	printf("mst printed here:\n");
	mst.print();

	struct timeval before, after, result; //time for before, after, and subtracting the two
    gettimeofday(&before, NULL); //time before

	mst.delete_edge(graph, edge{141 , 136 , -333});
	mst.delete_edge(graph, edge{456 , 297 , -212});
	mst.delete_edge(graph, edge{385 , 356 , -192});
	mst.delete_edge(graph, edge{417 , 381 , -153});
	mst.delete_edge(graph, edge{235 , 232 , -117});
	mst.delete_edge(graph, edge{246 , 163 , -109});
	mst.delete_edge(graph, edge{333 , 247 , -78});
	mst.delete_edge(graph, edge{191 , 108 , -72});
	mst.delete_edge(graph, edge{339 , 146 , -70});
	mst.delete_edge(graph, edge{140 , 22 , -68});
	mst.delete_edge(graph, edge{493 , 302 , -66});
	mst.delete_edge(graph, edge{142 , 133 , -62});
	mst.delete_edge(graph, edge{91 , 71 , -57});
	mst.delete_edge(graph, edge{477 , 473 , -44});
	mst.delete_edge(graph, edge{247 , 202 , -20});

	gettimeofday(&after, NULL); //time after8
    timersub(&after, &before, &result); //subtract the two times

	printf("Time for delete:\n\tsec: %li\n\tusec: %li\n\n", result.tv_sec, result.tv_usec);

	gettimeofday(&before, NULL); //time before

	mst.insert_edge(edge{141 , 136 , -333});
	mst.insert_edge(edge{456 , 297 , -212});
	mst.insert_edge(edge{385 , 356 , -192});
	mst.insert_edge(edge{417 , 381 , -153});
	mst.insert_edge(edge{235 , 232 , -117});
	mst.insert_edge(edge{246 , 163 , -109});
	mst.insert_edge(edge{333 , 247 , -78});
	mst.insert_edge(edge{191 , 108 , -72});
	mst.insert_edge(edge{339 , 146 , -70});
	mst.insert_edge(edge{140 , 22 , -68});
	mst.insert_edge(edge{493 , 302 , -66});
	mst.insert_edge(edge{142 , 133 , -62});
	mst.insert_edge(edge{91 , 71 , -57});
	mst.insert_edge(edge{477 , 473 , -44});
	mst.insert_edge(edge{247 , 202 , -20});

	gettimeofday(&after, NULL); //time after8
    timersub(&after, &before, &result); //subtract the two times

	printf("Time for insert:\n\tsec: %li\n\tusec: %li\n\n", result.tv_sec, result.tv_usec);
}

void testData()
{
	/* and now this one
	
		1--2--3
		|  !  |
		7  6--5--4

		NOTE: exclamation is the inserted edge
	*/

	printf("\n==demonstrating insertion==\n\n");

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

	// /*===deletion stuff below===*/

	/**
	 * lets do this graph as well
	 * 
	 * 8---1---2---3 -
	 * \  |    |   |  \
	 * 	7------6---5---4
	 */ 

	printf("\n\ndemonstrating deletion\n\n");

	std::vector<edge> del_edges;
	del_edges.emplace_back(edge{8,1,3});
	del_edges.emplace_back(edge{1,2,1});
	del_edges.emplace_back(edge{2,3,2});
	del_edges.emplace_back(edge{3,4,2});
	del_edges.emplace_back(edge{4,5,1});
	del_edges.emplace_back(edge{5,6,2});
	del_edges.emplace_back(edge{6,7,3});
	del_edges.emplace_back(edge{7,8,1});
	del_edges.emplace_back(edge{1,7,2});
	del_edges.emplace_back(edge{2,6,1});
	del_edges.emplace_back(edge{3,5,3});

	Graph del_orig(del_edges);
	del_orig.print();

	Graph del_mst = KruskalMST(del_orig);
	del_mst.print();
	del_mst.delete_edge(del_orig, edge{2,3,2});

	printf("After the delete\n\n");
	del_mst.print();
}