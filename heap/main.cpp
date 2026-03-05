#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void print(int tree[]){
	cout<<tree<<endl;
}
/*
void balancedown(int tree[], int &size, int i){
	int largest = i;//current largest index
	int ch1 = 2*i +1;//child root calculation
	int ch2 = 2*i +2;
	return;
}
*/
void balanceup(int tree[], int &size, int currentindex){//SEGFAULT BEGINS HERE
	if(currentindex=0){cout<<"Ordered"<<endl;return;}
	int parentindex = 0;
	if(currentindex % 2 == 0){parentindex = (currentindex-2)/2;}//index even
	else{parentindex = (currentindex-1)/2;}//else index odd
	int temp = 0;
<<<<<<< HEAD
	if(tree[parentindex]<tree[currentindex]){temp = tree[parentindex];tree[parentindex]=tree[currentindex];tree[currentindex]=temp;}
	else{return;}
	balanceup(tree, size, parentindex);
=======
	if(tree[parent]<tree[index]){
		temp = tree[parent];
		tree[parent]=tree[index];
		tree[index]=temp;
		balanceup(tree, )
	}
>>>>>>> 991c105 (LT3/5 TB OVERWRITTEN)
}
void add(int tree[], string filename, int &size){//add function for file input
	return;
}
void add(int tree[], int number, int &size){//add function for manual input
	int index = 0;
	if(tree[0]!=0){while(tree[index]!=0){index++;}}
	tree[index]=number;
	cout<<"Number added, re-ordering..."<<endl;
	balanceup(tree,size,index);//INDEX PASSED AS CURRENT SLOT TO MOVE UP FROM
}
int rmroot(int tree[], int &size){
	tree[0]=tree[size-1];
	tree[size-1]=0;
	size-=1;
	//balancedown(tree,size,0);//REBALANCES NODES
	return 0;
}
int rmall(int tree[]){
	return 0;
}
int main(){
	//'global' variables
	int tree[100] = {};
	int size = 100;//initial max size
	for(int i=0;i<100;i++){tree[i]=0;}
	string input = "";
	bool working = true;
	while(working){//main input loop
		cout<<"Enter a command (add, remove root, remove all, print): ";
		getline(cin, input);
		cout<<endl;
		if(input=="add"){
			string addtype = "";
			cout<<"Add by input or file?: ";
			getline(cin, addtype);
			cout<<endl;
			if(addtype=="file"){
				string filename = "";
				cout<<"Enter filename: ";
				getline(cin, filename);
				add(tree,filename,size);
			}
			else if(addtype=="input"){
				string numstr = "";
				cout<<"Enter a number to add (1-1000): ";
				getline(cin, numstr);
				cout<<endl;
				int number = stoi(numstr);
				if(number<1 || number>1000){cout<<"Out of range, please retry."<<endl;}
				else{add(tree,number,size);}
			}
			else{cout<<"Invalid input, please retry."<<endl;}
		}
		else if(input=="remove root"){
			rmroot(tree, size);
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
	return 0;
}
