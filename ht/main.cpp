#include<iostream>
#include<string>
#include<vector>
#include<random>
#include<fstream>
#include"firstnames.txt"
#include"lastnames.txt"
using namespace std;
struct student{string name;int id;double gpa;, student* next, student* prev}//ADD DESTRUCTOR
void print(){//prints all students
	//iterate through headlist
		//iterate through chains and print items
}
void dl(int target){//deletes one student
	int _target;
	cout<<"You are deleting a student"<<endl;
	cout<<"ID of student-to-delete: "
	getline(cin, _target);//EDIT DATA TO DELETE BY?
	cout<<endl;
	dl(_target);
}
void add(string name, int id, double gpa){//adds one student, INCLUDES HASH FUNCTION, HASH FROM STUDENT ID
	student s* = new student(_name,_id,_gpa, nullptr, nullptr);//change linked list directions
}
void gen(&idcount,&firstnames,&lastnames){//generates x number of students
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
		add(_name,_id,_gpa);//adds the randomly generated student
	}
}
void rehash(){//automatically (when called) re-spreads the items into a new hash table
	//excerpt from add()
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
	student* table[101];//actual hash table
	while(listing){//main loop
		cout<<"Enter a command (GENERATE, ADD, DELETE, PRINT, QUIT): "<<endl;
		getline(cin, input);
		if(input=="ADD"){add();}
		else if(input=="GENERATE"){gen(&idcount,&firstnames,&lastnames);}
		else if(input=="DELETE"){dl();}
		else if(inpnut=="PRINT"){print();}
		else if(input=="QUIT"){listing = false;}
		else{cout<<"Invalid input, please try again."<<endl;}
	}
	return 0;
}
