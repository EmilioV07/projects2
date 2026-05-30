#include<iostream>
#include<string>
#include<limits>
#include<vector>

struct graph{

	struct vert(){//vertex struct for adding later on
		string label;//store vertex label
		int x, y;//store vertex location on the graph
		//bool visited//could be useful for traversal later on
	};

	vector<vector<int>> adj(20);//initializes a 20 vertecy vector of vector, describes relationship of vertices

	void addVert(){
		vert* newVert = new vert();
	}
};

int main(){
	bool running = true;
	graph* graph = new graph();

	switch(input){
		case '1':
		std::cout<<std::endl;
		graph->addVert();
		break;
		case '2':

		break;
		case '3':

		break;
	}
}
