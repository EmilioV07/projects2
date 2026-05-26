#include<sstream>
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
		std::string inputs;
		std::string inputTemp;
		std::cout<<"Enter a series of numbers (space seperated): ";
		std::getline(std::cin, inputs); std::cout<<std::endl;//grab input
		for(char c : inputs){//split and add to tree
			if(c!=' '){inputTemp += c;}//walk characters and add non spaces
			else{//once space is encountered, add formed number to tree, clear, and continue iterating
				int numInput = stoi(inputTemp);
				inputTemp.clear();
				insert(root, root, numInput);
			}
		}
		if(!inputTemp.empty()){//fix for bug where single and last numbers were not added (due to only adding when space is incountered)
			int numInput = stoi(inputTemp);
			insert(root, root, numInput);
		}
	}

	node* find(node*& curr, int target){//curr to be input as root
		if(curr == nullptr){return nullptr;}//false
		if(curr->data == target){return curr;}//true
		else if(target < curr->data){return find(curr->left, target);}//recurse
		else{return find(curr->right, target);}//if target is larger, right subtree
	}

	void search(node*& root){
		std::string target;
		std::cout<<"Enter a number to search for: ";
		std::getline(std::cin, target);
		int _target = stoi(target);
		//bool found = find(root, _target);
		node* found = find(root, _target);
		//if(found){std::cout<<"Target found in the tree"<<std::endl;}
		//else{std::cout<<"Target not found in the tree"<<std::endl;}
		if(found!=nullptr){std::cout<<"Target found in the tree"<<std::endl;}
		else{std::cout<<"Target not found in the tree"<<std::endl;}
	}

	node* findPredecessor(node*& curr, node* pred){//helper function for del(), finds predecessor for root, curr to be input as root->right
		if(curr == nullptr){return pred;}//no items
		/*
		else if(curr->right != nullptr && curr->right->data < curr->data){//if nullptr, cuts before data check
			pred = curr->right;
		}
		else{
			findPredecessor(curr->right, pred);
			findPredecessor(curr->left, pred);
		}
		*/
		return nullptr;
	}

	void del(node*& targetNode){//use find helper funciton as in search to locate target node, fixed to return the found node to be passed
		if(targetNode == nullptr){return;}
		if(targetNode->left == nullptr && targetNode->right == nullptr){delete targetNode;}//no child deletion condition
		else if((targetNode->left == nullptr) XOR (targetNode->right == nullptr)){//one child deletion condition
			if(targetNode->left != nullptr){
				targetNode->left->prev = targetNode->prev;
				if(targetNode->prev!=nullptr){targetNode->prev->left = targetNode->left;}
				targetNode->left = nullptr;
				delete targetNode;
			}
			else{
				targetNode->right->prev = targetNode->prev;
				if(targetNode->prev!=nullptr){targetNode->prev->right = targetNode->right;}
				targetNode->right = nullptr;
				delete targetNode;
				targetNode = nullptr;
			}
		}
		else{//two child deletion condition
			node* pred = findPredecessor(root->right, nullptr);//should return predecessor or nullptr if there is none
			targetNode->data = pred->data;//copy predecessor data to target node
			del(pred);//delete predecessor node after copy is complete
		}
	}

	//wrappers
	void print(){print(root);}
	void add(){add(root);}
	void search(){search(root);}
	void del(){del(root);}
	~tree(){delete root;}
};

int main(){
	bool running = true;
	tree* binTree = new tree(nullptr);//initialize tree
	
	while(running){
		char input = ' ';
		//input cycle
		std::cout<<"Input (1 ADD, 2 DELETE, 3 PRINT, 4 SEARCH, Q QUIT): ";
		std::cin>>input; std::cout<<std::endl;//grab instruction
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//set cin \n ignore for later getline(s)
		
		//input decision
        switch (input){
        case '1':
            std::cout<<std::endl;
            binTree->add();
            break;
        case '2':{
            std::cout<<std::endl;
	        std::string tIstring;
			int targetInt;
			std::cout<<"Enter a node/# to delete: ";
			std::getline(std::cin, tIstring); std::cout<<std::endl;
			targetInt = stoi(tIstring);//target chosen, ready to find
			tree::node* targetNode = binTree->find(binTree->root, targetInt);//target recieved, ready for manipulation
			binTree->del(targetNode);
            break;
        }
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
