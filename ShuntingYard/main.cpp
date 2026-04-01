#include"node.h"
#include<iostream>
#include<string>


int main(){
	node* stackHead = nullptr;//insert and remove at head to avoid tail pointer
	node* qHead = nullptr;//insert at head remove at end, use tail pointer.
	node* qTail = nullptr;//tail pointer for queue
	
	string input;//arithmetic input
	char outOption;//output/notation preference (pre/in/postfix)

	bool running=true;
	while(running){//main input loop
		std::cout<<"Input: "<<std::endl;
		getline(cin, input);
		std::cout<<"Notation (1 Pre, 2 In, 3 Post): "std::endl;
		switch (outOption){
		case '1':
			std::cout<<"You have selected Prefix"<<std::endl;
			
			break;
		case '2':
			std::cout<<"You have selected Infix"<<std::endl;
			
			break;
		case '3':
			std::cout<<"You have selected Postfix"<<std::endl;
			
			break;
		case 'q':
			std::cout<<"Quitting..."<<std::endl;
			return 0;//exit program ADD DELETION/CLEANUP IF NEEDED
		default:
			std::cout<<"Invalid option, try again"<<std::endl;
	}
	}
}
