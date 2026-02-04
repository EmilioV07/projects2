#include<iostream>
#include<string>
#include<vector>
#include<random>
#include<fstream>
#include"firstnames.txt"
#include"lastnames.txt"
using namespace std;
struct student{string name;int id;double gpa;, student* next, student* prev}//ADD DESTRUCTOR
void print(student** &table){//prints all students
	//iterate through headlist
		//iterate through chains and print items
}
void dl(student** &table){//deletes one student
	int _target;
	cout<<"You are deleting a student"<<endl;
	cout<<"ID of student-to-delete: "
	getline(cin, _target);
	cout<<endl;
	//DELETE THE TARGET
}
bool rehash(student** &table){//automatically (when called) re-spreads the items into a new hash table
	bool rhtf;
	
	student** newtable = new student*[2*(sizeof(table)/sizeof(table[0]))];//assigns 'global' table variable to new table of double size
	for(int i=0;i<(sizeof(newtable)/sizeof(newtable[0]));i++){student* h=nullptr;newtable[i]=h;}//fills table with empty head pointers
	
	for(student* item ; table){//FOR EVERY OLD STUDENT
		if(item==nullptr){continue;}//IF THERE IS NO STUDENT
		if(item!=nullptr){//IF THERE IS A STUDENT
			int index;
			int chainlen = 1;
			bool placing;
			student* oldtemp = item;
			student* newtemp = newtable[index];
			for(char i ; oldtemp->_name){index += (static_cast<int>(i) + 47) * 109;
			index %= (sizeof(newtable)/sizeof(newtable[0]))
			while(placing)
				if(newtemp==nullptr){//IF SPOT UNOCCUPIED
					newtemp=oldtemp;//place
					oldtemp=oldtemp->next;//iterate
					newtemp->next=nullptr;//patch
				}
				else if(newtemp!=nullptr && newtemp->next==nullptr){//IF SPOT OCCUPIED & NEXT UNOCCUPIED
					newtemp->next=oldtemp;//place
					oldtemp=oldtemp->next;//iterate
					newtemp->next->next=nullptr;//patch
				}
				else if(newtemp!=nullptr && newtemp->next!=nullptr){//IF SPOT OCCUPIED & NEXT IS OCCUPIED
					newtemp=newtemp->next;//iterate
					chainlen++;
				}
				if(chainlen==4){cout<<"Another Chain Overflow Has Ocurred, Rehash will loop until resolved."<<endl;rhtf=true;}//MOVE/REHASH, THEN INCREMENT TEMP
		}
	}
	table = newtable;//Finally reassign the 'global' table to the new table
	//DELETE THE OLD TABLE SOMEHOW
	return rhtf;//RETURNS WHETHER OR NOT ANOTHER REHASH IS NEEDED
}
void add(int &idcount,student** &table){//adds one student, INCLUDES HASH FUNCTION, HASH FROM STUDENT ID
	string _name;
	double _gpa;
	cout<<"You are adding a student"<<endl;
	cout<<"Name(First Last): ";
	getline(cin,_name); cout<<endl;
	cout<<"GPA: ";
	getline(cin,_gpa); cout<<endl;
	double _gpaint=stod(_gpa);
	student* s = new student(_name,_id,_gpaint, nullptr, nullptr);//change linked list directions
	student* h=s;
	int index;
	for(char i ; _name){index += (static_cast<int>(i) + 47) * 109;}//HASH TIME UNDO BY /109, -47
	index %= (sizeof(table)/sizeof(table[0]));
	else{
		int chainlen = 1;
		student* temp = table[index];
		while(searching){
			if(temp==nullptr){temp = s; chainlen++;}
			else if(temp!=nullptr && temp->next==nullptr){temp->next = s;s->prev=temp;chainlen++;}//IF NO ENTRIES, ADD
			else if(temp!=nullptr && temp->next!=nullptr){temp=temp->next;chainlen++;}//increment if not end
			if(chainlen==4){
				bool rehashing;
				cout<<"Chain Overflow, rehashing..."<<endl;
				while(rehashing){if(rehash(&table)==true){continue;}else if(rehash(&table)==false){cout<<"Rehashed"<<endl;rehashing=false;searching=false;}
			}//CONDITIONAL TO REHASH
		}
	}//ITERATE TO LAST ELEMENT AND KEEP TRACK OF LENGTH TO DETERMINE REHASH
}
void gen(int &idcount,string &firstnames,string &lastnames,student** &table){//generates x number of students
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
		uniform_int_distribution<int> namedist(0, v.size()-1);//generates random index based on vector size (40 items in this case)
		string randomfirst = firstnames[namedist(gen)];
		string randomlast = lastnames[namedist(gen)];
		_name = randomfirst+" "+randomlast;//assign name
		add(_name,_id,_gpa);//adds the randomly generated student REPLACE
	}
}
int main{
	string line;//variable initializations, first and lastname vectors, run contidion, id count, table.
	ifstream file1("firstnames");vector<string> firstnames;//file1 and corresponding vector
	while(getline(file1, line)){firstnames.push_back(line);}
	ifstream file2("lastnames");vector<string> lastnames;//file2 and corresponding vector
	while(getline(file2, line)){lastnames.push_back(line);}
	string input;
	bool listing = true;
	int idcount = 111111;
	//int primecount = 0;
	//int primes[] = {101,211,431,863,1733,3467};
	student** table = new student*[101];//actual hash table
	for(int i=0;i<100;i++){student* h=nullptr;table[i]=h;}//fills table with empty head pointers
	while(listing){//main loop
		cout<<"Enter a command (GENERATE, ADD, DELETE, PRINT, QUIT): "<<endl;
		getline(cin, input);
		if(input=="ADD"){add(&idcount,&table);}
		else if(input=="GENERATE"){gen(&idcount,&firstnames,&lastnames);}
		else if(input=="DELETE"){dl(&table);}
		else if(inpnut=="PRINT"){print(&table);}
		else if(input=="QUIT"){listing = false;}
		else{cout<<"Invalid input, please try again."<<endl;}
	}
	return 0;
}
