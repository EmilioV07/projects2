#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void print(){

}
void add(int &tree , bool fileorinput){
	if(fileorinput==true){
		
	}
	else if(fileorinput==false){
		
	}
}
void dlroot(int &tree){
	
}
void main(){
	int tree[100] = {};

	string input = "";
	bool working = true;
	while(working){
		cout<<"Enter a command (add, delete root, print): ";
		getline(cin, input);
		if(input=="add"){
			string boolin == "";
			cout<<"Add by input or file?: ";
			getline(cin, boolin);
			if(boolin==file){add(tree,true);}
			else if(boolin==input){add(tree,false);}
			else{cout<<"Invalid input, please retry."<<endl;}
		}
		else if(input=="delete root"){
			dlroot(tree);
		}
		else if(input=="print"){
			print(tree);
		}
		else if(input=="quit"){working=false;}
		else{cout<<"Invalid input, please try again."<<endl;}
	}
}
