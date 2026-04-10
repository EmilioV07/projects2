//file inclusions
#include"node.h"
#include"btnode.h"
#include"stackfuncs.h"
#include"qfuncs.h"
//library inclusions
#include<iostream>
#include<string>
#include<cctype>

node* shunt(node* stackHead, node* qHead, node* qTail, std::string input){//shunting yard algorithm, returns queue head pointer
	for(char c : input){
		if(isalpha(c)){
			std::cout<<"Enqueue"<<std::endl;
			node* inputNode = new node(c,nullptr);//if input is a character, move it to output queue
			enq(inputNode, qHead);
		}
		else{
			std::cout<<"enqueue"<<std::endl;
			node* inputNode = new node(c,nullptr);//if input is an operator, move it to the operator stack
			push(inputNode, stackHead);
		}
	}
	return qHead;
}

int main(){
	//data structure items
	node* stackHead = nullptr;//insert and remove at head to avoid tail pointer
	node* qHead = nullptr;//insert at head remove at end, use tail pointer.
	//node* qTail = nullptr;//tail pointer for queue
	//UI items
	std::string input;//arithmetic input
	char outOption;//output/notation preference (pre/in/postfix)
	//shuntedExpression = shunt(stachHead, qHead, qTail, input);
	bool running=true;
	while(running){//main input loop
		std::cout<<"Input: ";
		std::getline(std::cin, input); std::cout<<std::endl;
		std::cout<<"Notation (1 Pre, 2 In, 3 Post, q Quit): ";
		//std::getline(std::cin, outOption);
		std::cin >> outOption;
		//std::cin.ignore(std::numeric_limits<std::streamsize>std::max(), '\n');
		std::cin.ignore(1, '\n');
		switch (outOption){
		case '1':
			std::cout<<std::endl<<"You have selected Prefix"<<std::endl;
			
			break;
		case '2':
			std::cout<<std::endl<<"You have selected Infix"<<std::endl;
			
			break;
		case '3':
			std::cout<<std::endl<<"You have selected Postfix"<<std::endl;
			
			break;
		case 'q':
			std::cout<<std::endl<<"Quitting..."<<std::endl;
			return 0;//exit program ADD DELETION/CLEANUP IF NEEDED
		default:
			std::cout<<std::endl<<"Invalid option, try again"<<std::endl;
		}
	}
}
