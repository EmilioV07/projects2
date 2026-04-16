//file inclusions
#include"node.h"
#include"btnode.h"
#include"stackfuncs.h"
#include"qfuncs.h"
//library inclusions
#include<iostream>
#include<string>
#include<cctype>

int prec(char op){//returns precidence given operator, to be used i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n shunt()
	if(op=='-'||op=='+'){return 1;}//addition subtraction precedence
	else if(op=='/'||op=='*'){return 2;}//multiplication division precedence
	else if(op=='^'){return 3;}//power precedence
	else if(op=='('){return 4;}
	else if(op==')'){return 5;}
	else{return 0;}//debug tool/for alphabetical chars
}

struct binaryTree{

	btnode* root = nullptr;
	binaryTree(btnode* _root){root=_root;}

	void push(btnode*& inputNode, btnode*& btstackHead){//add a node to the top of the stack given '_data' (from input string)
       if(btstackHead!=nullptr){//if stack is not empty (call first to avoid redundant check)
           inputNode->next=btstackHead;
           btstackHead=inputNode;
           return;
       }
       else{//if stack is empty
           btstackHead=inputNode;
           return;
       }
   }
    btnode* pop(btnode*& btstackHead){//return a pointer to the top item after removing it from the stack
       if(btstackHead==nullptr){return nullptr;}
       btnode* holder = btstackHead;//store head/top of list
       btstackHead=btstackHead->next;//move head pointer to node underneath
       holder->next=nullptr;//clean node
       return holder;
   }

	void buildTree(node*& qHead, btnode*& btstackHead){//takes shunted queue output and turns it into a binary expression tree
		node* curr = qHead;
		while(curr!=nullptr){//terminates when curr==nullptr
			node* next = curr->next;
			if(prec(curr->data)==0){
				btnode* tempBtnode = new btnode(curr->data,nullptr,nullptr,nullptr);
				push(tempBtnode, btstackHead);//if operand, push to stack
			}
			else if(prec(curr->data)>=1 && prec(curr->data)<=3){
				btnode* n1 = pop(btstackHead);
				btnode* n2 = pop(btstackHead);
				btnode* op = new btnode(curr->data, n2, n1, nullptr);//make new node and assign left and right as stack tops
				if(n1==nullptr || n2==nullptr){std::cout<<"Error, invalid input"<<std::endl; return;}//CLEAN TREE
				push(op, btstackHead);//push new branch/subtree to stack
			}
			curr = next;
		}
		root = btstackHead;
		//return nullptr;
	}

	void printTree(btnode* root, int depth = 0) {//COPILOT EXCERPT FOR DEBUG, NOT NECESSARY
    if (root == nullptr) return;

    printTree(root->right, depth + 1);

    for (int i = 0; i < depth; i++)
        std::cout << "    ";

    std::cout << root->data << "\n";

    printTree(root->left, depth + 1);
    }

	~binaryTree(){return;}//destructor
};

void print(node* curr){//curr to be input as qHead
	if(curr!=nullptr){
		std::cout<<curr->data<<" ";
		print(curr->next);
	}
	else{std::cout<<std::endl; return;}
}

node* shunt(node*& stackHead, node*& qHead, std::string input){//shunting yard algorithm, returns queue head pointer
	for(char c : input){
		int pr = prec(c);//precidence of given char of iteration
		if(pr==0 && c!=' '){//1. if char is alphabetical, enqueue
			enq(new node(c, nullptr), qHead);//decided to create new nodes individually
		}
		else if(pr==4){//2. if char is '(', push to stack
			push(new node(c, nullptr), stackHead);
		}
		else if(pr==5){//3. if char is ')', discard, enq stack items until '(', discard.
			while(stackHead!=nullptr && stackHead->data!='('){
				enq(pop(stackHead), qHead);
			}
			if(stackHead!=nullptr){
				node* p = pop(stackHead);
				delete p;//discards '('
			}
		}
		else if(pr>=1 && pr<=3){//4. if char is operator & valid stack condition, push
			bool isRightAssociated = (c=='^');//copilot fix for complex left-associative bug which caused improper output on all-powers test case, a manual restructure of the original code that is admittedly beyond my comprehension.
			while(stackHead!=nullptr && stackHead->data!='(' && (((!isRightAssociated && prec(stackHead->data)>=pr) || (isRightAssociated && prec(stackHead->data)>pr)))){
				enq(pop(stackHead), qHead);
			}
			push(new node(c, nullptr), stackHead);
		}
	}
	while(stackHead!=nullptr){
		enq(pop(stackHead), qHead);
	}
	stackHead = nullptr;//caution cleanup for later stack use in assembling binary expression tree
	//print(qHead);
	return qHead;
}

btnode* expressionTree(node*& qHead, btnode*& btstackHead){//clears and recycles original queue to use for output
	binaryTree* tree = new binaryTree(nullptr);//yes I know this could have been one tree in main, but I'm invested in this inefficiency (I have learned a lesson here)
	tree->buildTree(qHead, btstackHead);
	tree->printTree(tree->root,0);
	node* qclearE = qHead;
	while(qHead!=nullptr){//clear queue for use in output
		qclearE = qHead;
		qHead = qHead->next;
		delete qclearE;
	}
	return tree->root;
}

void prefix(btnode*& root){//use expression tree to output postfix notation
	std::cout<<root->data;
	if(root->left!=nullptr){prefix(root->left);}
	if(root->right!=nullptr){prefix(root->right);}
	return;
}

void postfix(btnode*& root){//use expression tree to output postfix notation
	if(root->left!=nullptr){prefix(root->left);}
	if(root->right!=nullptr){prefix(root->right);}
	std::cout<<root->data;
	return;
}

void infix(btnode*& root){//use expression tree to output postfix notation
	if(root->left!=nullptr){prefix(root->left);}
	std::cout<<root->data;
	if(root->right!=nullptr){prefix(root->right);}
	return;
}

int main(){
	//data structure items
	btnode* btstackHead = nullptr;
	node* stackHead = nullptr;//insert and remove at head to avoid tail pointer
	node* qHead = nullptr;//insert at head remove at end, use tail pointer.

	bool running=true;
	while(running){//main input loop
		//input vars
		std::string input;//arithmetic input
		char outOption = ' ';//output/notation preference (pre/in/postfix/quit as 1,2,3,q)

		//input collection
		std::cout<<"Input: ";
		std::getline(std::cin, input); std::cout<<std::endl;
		std::cout<<"Notation (1 Pre, 2 In, 3 Post, q Quit): ";
		std::cin >> outOption;
		std::cin.ignore(1, '\n');//copilot instruction on clearing input buffer to not bug out potential later getline()s
		std::cout<<std::endl;

		node* shuntedStr = shunt(stackHead, qHead, input);//SHUNT INPUT
		std::cout<<"Shunted Expression (postfix): ";
		print(qHead); std::cout<<std::endl;
		std::cout<<"Expression Tree: "<<std::endl<<std::endl;
		btnode* root = expressionTree(qHead,btstackHead);

		//input decision
		switch (outOption){
		case '1':
			std::cout<<std::endl<<"You have selected Prefix"<<std::endl<<std::endl;
			prefix(root);
			std::cout<<std::endl<<std::endl;
			break;
		case '2':
			std::cout<<std::endl<<"You have selected Infix"<<std::endl<<std::endl;
			infix(root);
			std::cout<<std::endl<<std::endl;
			break;
		case '3':
			std::cout<<std::endl<<"You have selected Postfix"<<std::endl<<std::endl;
			postfix(root);
			std::cout<<std::endl<<std::endl;
			break;
		case 'q':{
				std::cout<<std::endl<<"Quitting..."<<std::endl;
				node* clear = nullptr;
				while(stackHead!=nullptr){//clear memory
					clear = stackHead;
					stackHead = stackHead->next;
					delete clear;
				}
				while(qHead!=nullptr){
					clear = qHead;
					qHead = qHead->next;
					delete clear;
				}
				//ADD CLEAR BINARY TREE
				return 0;//exit program ADD DELETION/CLEANUP IF NEEDED
			}
		default:
			std::cout<<std::endl<<"Invalid option, try again"<<std::endl;
		}
	}
}
