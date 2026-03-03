#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void print(){

}
void balancedown(int &tree, int size, int i){
	int largest = i;//current largest index
	int ch1 = 2*i +1;//child root calculation
	int ch2 = 2*i +2;
}
void balanceup(int &tree, int size, int current){
	//current represents current index when added
	int parent = 0;//All LEFT children have ODD indices, and all EVEN have EVEN indices
	if(index%2=0){parent = (index-2)/2;}//index even
	else{parent = (index-1)/2;}//else index odd
	int temp = 0;
	if(tree[parent]<tree[index]){temp = tree[parent];tree[parent]=tree[index];tree[index]=temp;}
}
void add(int &tree, string filename){//add function for file input
	
}
void add(int &tree, int number, int &size){//add function for manual input
	int index = 0;
	while(tree[index]!=0){i++;}
	tree[index]=number;
	balanceup(tree,size,index)//INDEX PASSED AS CURRENT SLOT TO MOVE UP FROM
}
int rmroot(int &tree, int &size){
	tree[0]=tree[size-1];
	tree[size-1]=0;
	size-=1;
	balancedown(tree,size,0);//REBALANCES NODES
	return 0;
}
int rmall(int &tree){
	return 0;
}
void main(){
	//'global' variables
	int tree[100] = {};
	size = 100;//initial max size
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
				add(tree,filename,size);
			}
			else if(boolin==input){
				string numstr = "";
				cou<<"Enter a number to add (1-1000): ";
				getline(cin, number);
				cout<<endl;
				int number = stoi(numstr);
				if(1000<number<1){cout<<"Out of range, please retry."<<endl;}
				else{add(tree,number,size);}
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
