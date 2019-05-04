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
				printf("adding : {%d, %d, %f}\n", vec1, vec2, weight); 
			edges.emplace_back(edge{vec1, vec2, weight});
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
	mst.print();

	return 0;
}