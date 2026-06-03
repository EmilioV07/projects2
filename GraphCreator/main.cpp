#include<iostream>
#include<string>
#include<limits>
#include<vector>
#include<algorithm>
#include<climits>

struct graph{

	std::vector<std::string> labels;//stores label for each vertex
	std::vector<std::vector<std::pair<int,int>>> adj;//adjacency list. vector of vectors of int pairs used to store edges and weight of said edges (edge-neighbor, weight)

	void addVert(){//add a vertex to the graph
		std::string label;
		std::cout<<"Enter a label for the new vertex: ";//collect user input/label
		std::getline(std::cin, label);
		labels.push_back(label);//push the label to the label vector
		adj.push_back({});//push an empty edge list to the vertex vector
		//vertCount++;//this counter will be one ahead for indices, so subtract 1 when using for indexing
	}

	void addEdge(){//add an edge to the graph
		std::string startstr;
		std::string endstr;
		std::string weightstr;
		int weight;
		int start;
		int end;

		std::cout<<"Enter vertex to start edge from: ";//grab start vertex
		std::getline(std::cin, startstr); std::cout<<std::endl;//grab input
		auto startIndex = std::find(labels.begin(), labels.end(), startstr);//find the correct index to add to by label index (linear search to find it, not a huge efficiency problem considering there are no more than 20 vertices)
		if(startIndex == labels.end()){std::cout<<"The vertex you input does not exist, please try again."<<std::endl; return;}//if vertex is not found
		start = startIndex - labels.begin();//convert to index

		std::cout<<"Enter destination vertex: ";//grab destination vertex
		std::getline(std::cin, endstr); std::cout<<std::endl;
		auto endIndex = std::find(labels.begin(), labels.end(), endstr);
		if(endIndex == labels.end()){std::cout<<"The vertex you input does not exist, please try again."<<std::endl; return;}//if vertex is not found
		end = endIndex - labels.begin();

		std::cout<<"Enter edge weight: ";//grab desired edge weight
		std::getline(std::cin, weightstr); std::cout<<std::endl;
		weight = stoi(weightstr);
		std::cout<<std::endl;

		adj[start].push_back({end, weight});//push new edge to adjacency list
		std::cout<<"Edge added"<<std::endl;
	}

	void delVertex(){//NOTE "targetIndex" is NOT the target's index, "target" is. It is work I don't want to do to go back and fix it
		std::string targetstr;
		int target;
		std::cout<<"Enter a vertex to delete: ";
		std::getline(std::cin, targetstr); std::cout<<std::endl;//grab target input
		auto targetIndex = std::find(labels.begin(), labels.end(), targetstr);
		if(targetIndex == labels.end()){std::cout<<"The vertex you input does not exist, please try again."<<std::endl; return;}//if vertex is not found
		target = targetIndex - labels.begin();
		labels.erase(targetIndex);//remove vertex label from labels list
		adj.erase(adj.begin() + target);//remove vertex data from adjacency list
		//fix shifts
		for(auto &vertex : adj){//for every vertex (data/adj)
			for(auto i = vertex.begin(); i != vertex.end();){//for every edge on given vertex
				if(i->first == target){//if the target is in the vertex's edge list
					i = vertex.erase(i);//erase it
				}
				else{
					if(i->first > target){//if any edge was later in the list than the target
						i->first--;//decrement it to account for the shift
					}
					i++;
				}
			}
		}
	}

	void delEdge(){//remove an edge (works both ways! if there is a connections between two vertices, the vertex input order does not matter)
		std::string v1str;
		std::string v2str;
		int v1;
		int v2;

		std::cout<<"Enter vertex 1: ";//grab start vertex
		std::getline(std::cin, v1str); std::cout<<std::endl;//grab input
		auto v1Index = std::find(labels.begin(), labels.end(), v1str);//find the correct index to add to by label index (linear search to find it, not a huge efficiency problem considering there are no more than 20 vertices)
		if(v1Index == labels.end()){std::cout<<"The vertex you input does not exist, please try again."<<std::endl; return;}//if vertex is not found
		v1 = v1Index - labels.begin();//convert to index

		std::cout<<"Enter vertex 2: ";//grab destination vertex
		std::getline(std::cin, v2str); std::cout<<std::endl;
		auto v2Index = std::find(labels.begin(), labels.end(), v2str);
		if(v2Index == labels.end()){std::cout<<"The vertex you input does not exist, please try again."<<std::endl; return;}//if vertex is not found
		v2 = v2Index - labels.begin();

		for(auto i = adj[v1].begin(); i!= adj[v1].end();){//for every edge on vertex one
			if(i->first == v2){i = adj[v1].erase(i);}
			else{i++;}
		}

		for(auto i = adj[v2].begin(); i!= adj[v2].end();){//for every edge on vertex one
			if(i->first == v1){i = adj[v2].erase(i);}
			else{i++;}
		}

		std::cout<<"Edge removed"<<std::endl;

		return;
	}

	void search(){//dijkstra's algorithm
		std::string v1str;//at this point I've realized that maybe a helper funciton that grabs two vertices would be simpler, but I coded these functions one by one not knowing their structures would be so similar
		std::string v2str;
		int v1;//index variable for vertex 1
		int v2;//index variable for vertex 2

		std::cout<<"Enter vertex 1: ";//grab start vertex
		std::getline(std::cin, v1str); std::cout<<std::endl;//grab input
		auto v1Index = std::find(labels.begin(), labels.end(), v1str);//find the correct index to add to by label index (linear search to find it, not a huge efficiency problem considering there are no more than 20 vertices)
		if(v1Index == labels.end()){std::cout<<"The vertex you input does not exist, please try again."<<std::endl; return;}//if vertex is not found
		v1 = v1Index - labels.begin();//convert to index

		std::cout<<"Enter vertex 2: ";//grab destination vertex
		std::getline(std::cin, v2str); std::cout<<std::endl;
		auto v2Index = std::find(labels.begin(), labels.end(), v2str);
		if(v2Index == labels.end()){std::cout<<"The vertex you input does not exist, please try again."<<std::endl; return;}//if vertex is not found
		v2 = v2Index - labels.begin();

		std::vector<int> dist(labels.size(), INT_MAX);//distances vector, initialized as <vertcount> * intmax, practically guarantees correct route
		std::vector<bool> visited(labels.size(), false);//visited nodes vector, initializes as <vertcount> * false
		std::vector<int> parent(labels.size(), -1);//store parents to output final path

		dist[v1] = 0;//start distance as 0
		for(int k=0; k<labels.size(); k++){//actual dijkstra's algorithm, will alter dist to be list of min distances, visited to index/vertex based minimized weight(s)/path cost, and parent as a list of vertex indices corresponding with distances
			int j = -1;
			for(int i=0; i<labels.size(); i++){//for the amount of vertices
				if(visited[i]==false && (j==-1 || dist[i] < dist[j])){j=i;}//if the node is unvisited and is first vertex or distance is of lower cost than competetors, update 
			}
			if(j==-1){std::cout<<"No paths found"<<std::endl; return;}//no viable verts
			visited[j] = true;//set current vertex to visited so it will not be returned to
			for(auto &edge : adj[j]){//check whether or not a different path would be shorter, and updating dist accordingly
				int vert = edge.first;
				int weight = edge.second;
				if(dist[j] != INT_MAX && dist[j] + weight < dist[vert]){
					dist[vert] = dist[j] + weight;
					parent[vert] = j;//assign parent for later path output
				}
			}
		}

		if(dist[v2] == INT_MAX){std::cout<<"No path found from selected vertices"<<std::endl<<std::endl; return;}//unreachable vertex condition

		std::cout<<"The lowest cost route from "<<labels[v1]<<" to "<<labels[v2]<<" is:"<<std::endl;
		std::vector<int> path;
		for(int curr = v2; curr != -1; curr = parent[curr]){//reconstruct the path using indices form parent
			path.push_back(curr);
		}
		std::reverse(path.begin(), path.end());
		for(int i=0; i<path.size(); i++){
			std::cout<<labels[path[i]];//output corresponding label from path indices in a loop
			if(i != path.size() - 1){std::cout<<" --> ";}//while still recreating path, cout connecting arrows
		}
		std::cout<<std::endl<<std::endl;
		std::cout<<"With a total cost of: "<<dist[v2]<<std::endl<<std::endl;//cout total cost of the path

		return;
	}

	void print(){//print the graph (simple)
		for(int i=0; i<labels.size(); i++){//for every vertex
			std::cout<<labels[i]<<": ";//cout the label
			for(auto j = adj[i].begin(); j!=adj[i].end(); j++){//then for every edge therein
				std::cout<<"("<<labels[j->first]<<","<<j->second<<")";//cout the connection vertex and the edge weight
			}
			std::cout<<std::endl;
		}
		return;
	}
};

int main(){
	bool running = true;
	graph* g = new graph();
	while(running){//main input loop
		char input = ' ';
		std::cout<<"\n1 ADD VERTEX\n2 ADD EDGE\n3 DELETE VERTEX\n4 DELETE EDGE\n5 DIJKSTRA'S ALG.\n6 PRINT\nQ QUIT\n\nInput: ";
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
			case '3':
			std::cout<<std::endl;
			g->delVertex();
			break;
			case '4':
			g->delEdge();
			break;
			case '5':
			g->search();
			break;
			case '6':
			g->print();
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
