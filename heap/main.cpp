#include<iostream>
#include<fstream>
#include<string>
#include<array>
using namespace std;
void print(int tree[], int size){
	for(int i=0;i<size;i++){
		cout<<tree[i]<<" ";
	}
	cout<<endl;
}

void balancedown(int tree[], int &size, int head){
	int big = head;
	int l = 2*head +1;
	int r = 2*head +2;

	if(l<size && tree[l]>big){big=l;}
	if(r<size && tree[r]>big){big=r;}
	if(big!=head){
		int temp=tree[big];
		tree[big]=tree[head];
		tree[head]=temp;
		balancedown(tree, size, big);
	return;
}

//void balanceup(int tree[], int &size, int head){
	/*
	if(currentindex=0){cout<<"Ordered"<<endl;return;}
	int parentindex = 0;
	if(currentindex % 2 == 0){parentindex = (currentindex-2)/2;}//index even
	else{parentindex = (currentindex-1)/2;}//else index odd
	//balanceup(tree, size, parentindex);
	int temp = 0;
	if(tree[parentindex]<tree[currentindex]){
		temp = tree[parentindex];
		tree[parentindex]=tree[currentindex];
		tree[currentindex]=temp;
		balanceup(tree, size, parentindex);
	}
	else{cout<<"Done"<<endl;return;}
	*/
	//return;
}

void add(int tree[], string filename, int &size){//add function for file input
	return;
}
void add(int tree[], int number, int &size){//add function for manual input
	if(size==0){tree[size]=number;size++;}
	else{tree[size]=number;size++;}
	//balanceup(tree, size, size);
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
	for(int i=0;i<size;i--){
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
