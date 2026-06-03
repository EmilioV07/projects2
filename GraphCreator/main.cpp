#include<iostream>
#include<string>
#include<limits>
#include<vector>
#include<algorithm>

struct graph{

	std::vector<std::string> labels;//stores label for each vertex
	std::vector<std::vector<std::pair<int,int>>> adj;//adjacency list. vector of vectors of int pairs used to store edges and weight of said edges (edge-neighbor, weight)

	void addVert(){//add a vertex to the graph
		std::string label;
		std::cout<<"Enter a label for the new vertex: ";//collect user input/label
		std::getline(std::cin, label);
		labels.push_back(label);//push the label to the label vector
		adj.push_back({});//push an empty edge list to the vertex vector
		vertCount++;//this counter will be one ahead for indices, so subtract 1 when using for indexing
	}

	void addEdge(){//add an edge to the graph
		std::string startstr;
		std::string endstr;
		std::string weightstr;
		int weight;
		int start;
		int end;

		std::cout<<"Enter vertex to start edge from: ";//grab start vertex
		std::getline(std::cin, startstr);//grab input
		auto startIndex = std::find(labels.begin(), labels.end(), startstr);//find the correct index to add to by label index (linear search to find it, not a huge efficiency problem considering there are no more than 20 vertices)
		if(startIndex == labels.end()){std::cout<<"The vertex you input does not exist, please try again."<<std::endl; return;}//if vertex is not found
		start = startIndex - labels.begin();//convert to index

		std::cout<<"Enter destination vertex: ";//grab destination vertex
		std::getline(std::cin, endstr);
		auto endIndex = std::find(labels.begin(), labels.end(), endstr);
		if(endIndex == labels.end()){std::cout<<"The vertex you input does not exist, please try again."<<std::endl; return;}//if vertex is not found
		end = endIndex - labels.begin();

		std::cout<<"Enter edge weight: ";//grab desired edge weight
		std::getline(std::cin, weightstr);
		weight = stoi(weightstr);
		std::cout<<std::endl;

		adj[start].push_back({end, weight});//push new edge to adjacency list
	}
};

int main(){
	bool running = true;
	graph* g = new graph();
	while(running){
		char input = ' ';
		std::cout<<"Input (1 ADD VERTEX, 2 ADD EDGE, Q QUIT): ";
	    std::cin>>input; std::cout<<std::endl;//grab instruction
	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//set cin \n ignore for later getlines

		switch(input){
			case '1':
			std::cout<<std::endl;
			g->addVert();//add vertex case
			break;
			case '2':
			std::cout<<std::endl;
			g->addEdge();//add edge case
			break;
			case 'Q':
			delete g;//how conventient
			running = false;
			break;
			default:
			std::cout<<std::endl;
			std::cout<<"Invalid input, please try again."<<std::endl;
			break;
		}
	}
}
