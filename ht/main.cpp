#include<iostream>
#include<string>
#include<vector>
#include<random>
#include<fstream>
using namespace std;
struct student{
	string name;
	int id;
	double gpa;
	student* next;
	student();
	student(string n, int i, double g, student* nx=nullptr)
		: name(n), id(i), gpa(g), next(nx), {}
	};
void print(student** &table, int &tablesize){//prints all students
	//iterate through headlist
		//iterate through chains and print items
}
void dl(student** &table, int &tablesize){//deletes one student
	int _target;
	string _targetstr;
	cout<<"You are deleting a student"<<endl;
	cout<<"ID of student-to-delete: ";
	getline(cin, _targetstr);
	_target=stoi(_targetstr);
	cout<<endl;
	//DELETE THE TARGET
}
bool rehash(student** &table, int &tablesize){//automatically (when called) re-spreads the items into a new hash table
	bool rhtf=false;
	int newsize = 2*tablesize;
	student** newtable = new student*[newsize];//assigns 'global' table variable to new table of double size
	for(int i=0;i<newsize;i++){newtable[i]=nullptr;}//fills table with empty head pointers

	for(int i=0;i<tablesize;i++){//FOR EVERY OLD STUDENT
		student* curr = table[i];//current pointer
		while(curr!=nullptr){//finding loop
			student* next = curr->next;//saves next pointer
			curr->next=nullptr;//clears direction of plucked student

			int index = 0;
			for(char c : curr->name){index += (static_cast<int>(c) + 47) * 109;}
			index %= newsize;
			if(newtable[index]==nullptr){newtable[index]=curr;}
			else{
				student* temp = newtable[index];
				int chainlen=1;
				while(temp->next!=nullptr){temp=temp->next;chainlen++;}//iterate to end of chain
				temp->next=curr;
				if(chainlen>=4){rhtf=true;}
			}
			curr=next;
		}
	}
	delete[] table;
	table = newtable;//Finally reassign the 'global' table to the new table
	tablesize=newsize;
	return rhtf;//RETURNS WHETHER OR NOT ANOTHER REHASH IS NEEDED
}

void add(int &idcount,student** &table, int &tablesize){//adds one student, INCLUDES HASH FUNCTION, HASH FROM STUDENT ID
	string _name;
	double _gpad;
	string _gpa;
	cout<<"You are adding a student"<<endl;
	cout<<"Name(First Last): ";
	getline(cin,_name); cout<<endl;
	cout<<"GPA: ";
	getline(cin,_gpa); cout<<endl;
	_gpad=stod(_gpa);
	student* s = new student(_name,idcount++,_gpad, nullptr, nullptr);//change linked list directions
	int index = 0;
	for(char i : _name){index += (static_cast<int>(i) + 47) * 109;}//HASH TIME UNDO BY /109, -47
	index %= tablesize;
	int chainlen = 1;
	if(table[index]==nullptr){table[index]=s;}
	else{
		student* temp = table[index];
		while(temp->next!=nullptr){temp=temp->next;chainlen++;}//iterate to end of chain
			temp->next=s;
			if(chainlen>=4){
				cout<<"Chain Overflow, rehashing..."<<endl;
				while(rehash(table,tablesize)){//rehashes until rehash returns false
					cout<<"Chain Overflow; Rehashing..."<<endl;
				}
				cout<<"Rehashed"<<endl;
			}
	}
}

void gen(int &idcount,vector<string> &firstnames,vector<string> &lastnames,student** &table,int &tablesize){//generates x number of students
	string numstr;
	int num;
	cout<<"You are generating any number of students randomly"<<endl;
	cout<<"How many students would you like to generate: ";
	getline(cin,numstr);//POTENTIAL ADD DEBUG FOR NON INT INPUTS
	num = stoi(numstr);//converts string console input into integer for looping
	for(int i=0;i<num;i++){
		string _name;
		int _id;
		double _gpa;
		cout<<"How many students would you like to generate?"<<endl;
		cout<<"You are adding a student"<<endl;
		_id = idcount; idcount++;//assign id
		random_device rd;//Copilot random device syntax
		mt19937 gen(rd());//random generator
		uniform_real_distribution<double> gpadist(0.00,4.5);
		_gpa = gpadist(gen);//assign gpa
		uniform_int_distribution<int> namedist(0, firstnames.size()-1);//generates random index based on vector size (40 items in this case)
		string randomfirst = firstnames[namedist(gen)];
		string randomlast = lastnames[namedist(gen)];
		_name = randomfirst+" "+randomlast;//assign name
		int index;
		for(char i : _name){index += (static_cast<int>(i) + 47) * 109;}//HASH TIME UNDO BY /109, -47
		index %= tablesize;
		int chainlen = 1;
		student* temp = table[index];
		while(searching){
			if(temp==nullptr){temp = s; chainlen++;}
			else if(temp!=nullptr && temp->next==nullptr){temp->next = s;chainlen++;}//IF NO ENTRIES, ADD
			else if(temp!=nullptr && temp->next!=nullptr){temp=temp->next;chainlen++;}//increment if not end
			if(chainlen==4){
				bool rehashing;
				cout<<"Chain Overflow, rehashing..."<<endl;
				while(rehashing){if(rehash(&table)==true){continue;}else if(rehash(&table)==false){cout<<"Rehashed"<<endl;rehashing=false;searching=false;}
			}//CONDITIONAL TO REHASH
		}
	}
}
int main(){
	string line;//variable initializations, first and lastname vectors, run contidion, id count, table.
	ifstream file1("firstnames");vector<string> firstnames;//file1 and corresponding vector
	while(getline(file1, line)){firstnames.push_back(line);}
	ifstream file2("lastnames");vector<string> lastnames;//file2 and corresponding vector
	while(getline(file2, line)){lastnames.push_back(line);}
	string input;
	bool listing=true;
	int idcount = 111111;
	tablesize = 101;
	student** table = new student*[tablesize];//actual hash table
	for(int i=0;i<101;i++){student* h=nullptr;table[i]=h;}//fills table with empty head pointers
	while(listing){//main loop
		cout<<"Enter a command (GENERATE, ADD, DELETE, PRINT, QUIT): "<<endl;
		getline(cin, input);
		if(input=="ADD"){add(idcount,table,tablesize);}
		else if(input=="GENERATE"){gen(idcount,firstnames,lastnames,tablesize);}
		else if(input=="DELETE"){dl(table,tablesize);}
		else if(input=="PRINT"){print(table,tablesize);}
		else if(input=="QUIT"){listing = false;}
		else{cout<<"Invalid input, please try again."<<endl;}
	}
	return 0;
}
