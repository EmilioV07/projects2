#include<iostream>
#include<string>
#include<limits>
#include<vector>

struct graph{

	/*Undesireable structure
	struct vert(){//vertex struct for adding later on
		string label;//store vertex label
		int x, y;//store vertex location on the graph
		//bool visited//could be useful for traversal later on
	};
	*/

	int vertCount = 0;//keep track of vertices

	vector<std::string> labels;//stores label for each vertex
	vector<vector<pair<int,int>>> adj;//adjacency list. vector of vectors of int pairs used to store edges and weight of said edges (edge-neighbor, weight)

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
		int start;
		int end;

		std::cout<<"Enter a vertex index to add an edge to: ";
		std::getline(std::cin, startstr);
		start= = stoi(startstr);
		std::cout<<std::endl;

		std::cout<<"Enter a destination vertex: ";
		std::getline(std::cin, endstr);
		end = stoi(endstr);
		std::cout<<std::endl;

		std::cout<<"Enter edge weight: ";
		std::getline(std::cin, weightstr);
		std::cout<<std::endl;

		adj.push_back();
	}
};

int main(){
	bool running = true;
	graph* graph = new graph();

	char input = ' ';
	std::cout<<"Input (1 ADD VERTEX, 2 DELETE VERTEX, Q QUIT): ";
    std::cin>>input; std::cout<<std::endl;//grab instruction
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//set cin \n ignore for later getlines

	switch(input){
		case '1':
		std::cout<<std::endl;
		graph->addVert();//add vertex case
		break;
		case '2':
		std::cout<<std::endl;
		graph->addEdge();//add edge case
		break;
		case 'Q':
		delete graph;//how conventient
		running = false;
		break;
	}
}
