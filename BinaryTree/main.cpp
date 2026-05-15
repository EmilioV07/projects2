#include<iostream>
#include<string>
#include<vector>
#include<limits>

struct tree{

	struct node{//node stuff
		node* prev;
		node* left;
		node* right;
		int data;
		node(int data, node* prev = nullptr, node* left = nullptr, node* right = nullptr) : data(data), prev(prev), left(left), right(right) {}//inline constructor defaults to no neighbors/linked nodes
		~node(){delete left; delete right;}//node deletes its children on destruction, makes clearing tree simpler, REMEMBER TO CLEAN BEFORE DELETING DURING RUNTIME
	};

	node* root;
	tree(node* _root) : root(_root) {}

	void print(node* root, int depth = 0){//print tree sideways with tab spacing
		if(root==nullptr){return;}//return if tree is empty
		print(root->right, depth+1);//otherwise (else), recursively increase (find) depth
		for(int i=0; i<depth; i++){std::cout<<"    ";}//depth spacing
			std::cout<<root->data<<'\n';//depth-based tab spacing
			print(root->left, depth + 1);
		}

	void add(node* root){
		//vars
		std::string inputs;
		std::string inputTemp;
		//grab input
		std::cout<<"Enter a series of numbers (space seperated): ";
		std::getline(std::cin, inputs); std::cout<<std::endl;
		//sort input
		for(char c : inputs){
			if(c!=' '){inputTemp += c;}
			else{//once first space is encountered, a whole number has been formed, so make a node with it and add it to the tree
				int numInput = stoi(inputTemp);//convert to int for easier comparison later
				inputTemp.clear();//clear the string for the next input to pile up
				node* n = new node(numInput,nullptr,nullptr,nullptr);//make new node with piece
				if(root==nullptr){root=n;}//if no root, make it root
				else{//if there is root, sort
					node* curr = root;
					while(curr!=nullptr){
						if(n->data == curr->data){delete n; std::cout<<"Duplicate removed"<<std::endl;}
						else if(n->data < curr->data){curr = curr->left;}
						else if(n->data > curr->data){curr = curr->right;}
					}
					curr = n;//once the sorting has reached the bottom in the right spot, assign new node
					std::cout<<"Node added"<<std::endl;
				}
			}
		}
	}

	//wrappers
	void print(){print(root);}
	void add(){add(root);}
	~tree(){delete root;}
};

int main(){
	bool running = true;
	tree* binTree = new tree(nullptr);//initialize tree
	
	while(running){
		char input = ' ';
		//input cycle
		std::cout<<"Input (1 ADD, 2 DELETE ROOT, 3 PRINT, Q QUIT): ";
		std::cin>>input; std::cout<<std::endl;//grab instruction
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//set cin \n ignore for later getline(s)
		
		//input decision
        switch (input){
        case '1':
            std::cout<<std::endl;
            binTree->add();
            break;
        case '2':
            std::cout<<std::endl;
            break;
        case '3':
            std::cout<<std::endl;
            binTree->print();
            break;
        case 'Q':{
                //exit program ADD DELETION/CLEANUP IF root!=nullptr
                return 0;
            }
        default:
            std::cout<<std::endl<<"Invalid option, try again"<<std::endl;
        }
	}
}
