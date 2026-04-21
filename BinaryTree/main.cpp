#include<iostream>

struct node{
	node* prev;
	node* left;
	node* right;
	char data;
	node(char data, node* prev, node* left, node* right);
	~node(){delete left; delete right;}//node deletes its children on destruction, makes clearing tree simpler, REMEMBER TO CLEAN BEFORE DELETING DURING RUNTIME
};

struct tree{
	node* root;
	tree(node* _root) : root(_root) {}

	void print(node* root, int depth = 0){//print tree sideways with tab spacing
		if(root==nullptr){return;}//return if tree is empty
		print(root->right, depth+1);//otherwise (else), recursively increase (find) depth
		for(int i=0; i<depth; i++){std::cout<<"    ";}//depth spacing
		std::cout<<root->data<<'\n';//depth-based tab spacing
		print(root->left, depth + 1);
		}
	}

	void add(node* _inputNode){
		
	}

	//wrappers
	void print(){print(root);}

	~tree(node* root){//clears tree
		delete root;//deletes root node, which sets off chain reaction to clear tree
	}
};

int main(){
	bool running = true;
	tree* tree = new tree(nullptr);//initialize tree
	
	while(running){
		char input = ' ';
		//input cycle
		std::cout<<"Input (1 ADD, 2 DELETE ROOT, 3, Q QUIT): ";
		std::cin>>input; std::cout<<std::endl;//grab instruction
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//set cin \n ignore for later getline(s)
		
		//input decision
        switch (input){
        case '1':
            std::cout<<std::endl;
            break;
        case '2':
            std::cout<<std::endl;
            break;
        case '3':
            std::cout<<std::endl;
            break;
        case 'Q':{
                //exit program ADD DELETION/CLEANUP IF root!=nullptr
                return 0;
            }
        default:
            std::cout<<std::endl<<"Invalid option, try again"<<st>
        }
	}
}
