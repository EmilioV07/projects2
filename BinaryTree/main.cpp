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
		~node(){std::cout<<"deleted node"<<std::endl; delete left; delete right;}//node deletes its children on destruction, makes clearing tree simpler, REMEMBER TO CLEAN BEFORE DELETING DURING RUNTIME
	};

	node* root;
	tree(node* _root) : root(_root) {}

	void print(node*& root, int depth = 0){//print tree sideways with tab spacing
		if(root==nullptr){return;}//return if tree is empty
		print(root->right, depth+1);//otherwise (else), recursively increase (find) depth
		for(int i=0; i<depth; i++){std::cout<<"    ";}//depth spacing
			std::cout<<root->data<<'\n';//depth-based tab spacing
			print(root->left, depth + 1);
		}

	void insert(node*& curr, node*& prev, int numInput){
		if(curr == nullptr){//base case, once "root" is nullptr, add the node, and if this is not the first node, update the previous pointer.
			curr = new node(numInput,nullptr,nullptr,nullptr);
			if(prev!=nullptr){curr->prev = prev;}
			return;
		}
		else if(numInput < curr->data){insert(curr->left, curr, numInput);}//continues insertion recursion with the next subtree, previous, and input.
		else if(numInput > curr->data){insert(curr->right, curr, numInput);}
		else{std::cout<<"Ignored Duplicate"<<std::endl;}
	}

	void add(node*& root){
		//vars
		std::string inputs;
		std::string inputTemp;
		//grab input
		std::cout<<"Enter a series of numbers (space seperated): ";
		std::getline(std::cin, inputs); std::cout<<std::endl;
		//sort input
		for(char c : inputs){
			if(c!=' '){
				inputTemp += c;
				int numInput = stoi(inputTemp);//convert to int for easier comparison later
				inputTemp.clear();//clear the string for the next input to pile up
				insert(root, root, numInput);
				}
			}
				/*
				node* n = new node(numInput,nullptr,nullptr,nullptr);//make new node with piece
				node*& curr = root;
				node* prev = nullptr;
				bool sorting = true;
				while(sorting){
					if(curr == nullptr){
						curr = n;
						sorting = false;
					}
					else if(n->data == curr->data){
						delete n;
						std::cout<<"Duplicate removed"<<std::endl;
						sorting = false;
					}
					else if(n->data < curr->data){curr = curr->left;}
					else{curr = curr->right;}
				}
				curr = n;//once the sorting has reached the bottom in the right spot, assign new node
				std::cout<<"Node added"<<std::endl;
				*/
	}

	bool find(node*& curr, int target){//curr to be input as root
		if(curr == nullptr){return false;}
		if(curr->data == target){return true;}
		else if(target < curr->data){return find(curr->left, target);}
		else{return find(curr->right, target);}//if target is larger, right subtree
	}

	void search(node*& root){
		std::string target;
		std::cout<<"Enter a number to search for: ";
		std::getline(std::cin, target);
		int _target = stoi(target);
		bool found = find(root, _target);
		if(found){std::cout<<"Target found in the tree"<<std::endl;}
		else{std::cout<<"Target not found in the tree"<<std::endl;}
	}

	
	//wrappers
	void print(){print(root);}
	void add(){add(root);}
	void search(){search(root);}
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
        case '4':
			std::cout<<std::endl;
			binTree->search();
        	break;
        case 'Q':{
                //exit program ADD DELETION/CLEANUP IF root!=nullptr
                delete binTree;
                return 0;
            }
        default:
            std::cout<<std::endl<<"Invalid option, try again"<<std::endl;
        }
	}
}
