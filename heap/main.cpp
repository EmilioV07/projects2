#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void print(){

}
void add(int &tree, string filename){//add function for file input
	
}
void add(int &tree, int number){//add function for manual input
	
}
int rmroot(int &tree){
	return 0;
}
int rmall(int &tree){
	return 0;
}
void main(){
	//'global' variables
	int tree[100] = {};
	for(int i=0;i<100;i++;){tree[i]=0;}
	string input = "";
	bool working = true;
	while(working){//main input loop
		cout<<"Enter a command (add, remove root, remove all, print): ";
		getline(cin, input);
		cout<<endl;
		if(input=="add"){
			string boolin == "";
			cout<<"Add by input or file?: ";
			getline(cin, boolin);
			cout<<endl;
			if(boolin==file){
				string filename = "";
				cout<<"Enter filename: ";
				getline(cin, filename);
				add(tree,filename);
			}
			else if(boolin==input){
				string numstr = "";
				cou<<"Enter a number to add (1-1000): ";
				getline(cin, number);
				cout<<endl;
				int number = stoi(numstr);
				if(1000<number<1){cout<<"Out of range, please retry."<<endl;}
				else{add(tree,number);}
			}
			else{cout<<"Invalid input, please retry."<<endl;}
		}
		else if(input=="remove root"){
			rmroot(tree);
		}
		else if(input=="remove all"){
			rmall(tree);
		}
		else if(input=="print"){
			print(tree);
		}
		else if(input=="quit"){working=false;}
		else{cout<<"Invalid input, please try again."<<endl;}
	}
}
