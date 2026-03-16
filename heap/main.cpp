#include<iostream>
#include<fstream>
#include<string>
#include<array>
using namespace std;
void print(int tree[], int size){
	cout<<"Size: "<<size<<endl;
	for(int i=0;i<size;i++){
		cout<<tree[i]<<" ";
	}
	cout<<endl;
}

void balancedown(int tree[], int &size, int currentindex){
	if(currentindex==size-1 || currentindex==size-2){cout<<"Ordered"<<endl;return;}
	int lchild = (2*currentindex)+1;
	int rchild = (2*currentindex)+2;
	
	if(tree[currentindex]<tree[lchild] && tree[lchild] > tree[rchild]){
		int temp = tree[lchild];
		tree[lchild]=tree[currentindex];
		tree[currentindex]=temp;
		balancedown(tree, size, lchild);
	}
	else if(tree[currentindex]<tree[rchild] && tree[rchild]>tree[lchild]){
		int temp = tree[rchild];
		tree[rchild]=tree[currentindex];
		tree[currentindex]=temp;
		balancedown(tree, size, rchild);
	}
}

void balanceup(int tree[], int &size, int currentindex){
	if(currentindex==0){cout<<"Ordered"<<endl;return;}
	int parent;
	if(currentindex % 2 == 0){parent = (currentindex-2)/2;}
	else{parent = (currentindex-1)/2;}
	if(tree[parent]<tree[currentindex]){//if parent is smaller, swap
		int temp;
		temp = tree[currentindex];
		tree[currentindex]=tree[parent];
		tree[parent]=temp;
		balanceup(tree, size, parent);
	}
	else{cout<<"Ordered"<<endl;return;}
}

void add(int tree[], string filename, int &size){//add function for file input
	return;
}
void add(int tree[], int number, int &size){//add function for manual input
	if(size==0){tree[size]=number;size++;}
	else{tree[size]=number;size++;}
	balanceup(tree, size, size-1);
}
void rmroot(int tree[], int &size){
	if(size==0){cout<<"Done"<<endl;return;}
	tree[0]=tree[size-1];
	tree[size-1]=0;
	size--;
	balancedown(tree, size, 0);
	return;
}
void rmall(int tree[], int &size){
	for(int i=0;i<size;i++){
		rmroot(tree, size);
	}
}
int main(){
	//'global' variables
	int tree[100] = {};
	int size = 0;//initial max size
	for(int i=0;i<100;i++){tree[i]=0;}
	string input = "";
	bool working = true;
	while(working){//main input loop
		cout<<"Enter a command (add, remove root, remove all, print, quit): ";
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
			rmall(tree, size);
		}
		else if(input=="print"){
			print(tree, size);
		}
		else if(input=="quit"){working=false;}
		else{cout<<"Invalid input, please try again."<<endl;}
	}
	return 0;
}
