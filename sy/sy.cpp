#include<iostream>
#include<string>

int main(){
	string input;//arithmetic input
	char outOption;//output/notation preference
	bool running=true;
	while(running){//main input loop
		switch (outOption){
		case '1':
			std::cout<<"1"<<std::endl;
			break;
		case '2':
			std::cout<<"2"<<std::endl;
			break;
		case '3':
			std::cout<<"3"<<std::endl;
			break;
		case 'q':
			std::cout<<Quitting...<<endl;
			return 0;//exit program ADD DELETION/CLEANUP IF NEEDED
		default:
			std::cout<<"Invalid option, try again"<<std::endl;
	}
	}
}
