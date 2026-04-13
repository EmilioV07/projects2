//file inclusions
#include"node.h"
#include"btnode.h"
#include"stackfuncs.h"
#include"qfuncs.h"
//library inclusions
#include<iostream>
#include<string>
#include<cctype>

void print(node* curr){//curr to be input as qHead
	if(curr!=nullptr){
		std::cout<<curr->data<<" ";
		print(curr->next);
	}
	else{std::cout<<std::endl; return;}
}

int prec(char op){//returns precidence given operator, to be used i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n shunt()
	if(op=='-'||op=='+'){return 1;}//addition subtraction precedence
	else if(op=='/'||op=='*'){return 2;}//multiplication division precedence
	else if(op=='^'){return 3;}//power precedence
	else if(op=='('){return 4;}
	else if(op==')'){return 5;}
	else{return 0;}//debug tool/for alphabetical chars
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
	print(qHead);
	return qHead;
}

node* expressionTree(node* qHead, node* root){

	return root;
}

node* prefix(node* root){//use expression tree to output postfix notation

	return root;
}

node* infix(node* root){//use expression tree to output postfix notation

	return root;
}

node* postfix(node* root){//use expression tree to output postfix notation
	
	return root;
}

int main(){
	//data structure items
	node* stackHead = nullptr;//insert and remove at head to avoid tail pointer
	node* qHead = nullptr;//insert at head remove at end, use tail pointer.
	node* root = nullptr;

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

		//input decision
		switch (outOption){
		case '1':
			std::cout<<std::endl<<"You have selected Prefix"<<std::endl;
			//prefix();
			break;
		case '2':
			std::cout<<std::endl<<"You have selected Infix"<<std::endl;
			//infix();
			break;
		case '3':
			std::cout<<std::endl<<"You have selected Postfix"<<std::endl;
			//postfix();
			shunt(stackHead, qHead, input);
			break;
		case 'q':
			std::cout<<std::endl<<"Quitting..."<<std::endl;
			return 0;//exit program ADD DELETION/CLEANUP IF NEEDED
		default:
			std::cout<<std::endl<<"Invalid option, try again"<<std::endl;
		}
	}
}
