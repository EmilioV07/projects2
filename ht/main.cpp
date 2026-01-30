#include<iostream>
#include<string>
#include<vector>
#include<random>
#include<fstream>
#include"firstnames.txt"
#include"lastnames.txt"
using namespace std;
struct student{string name;int id;double gpa;, student* next, student* prev}
void print(){//prints all students
	
}
void dl(int target){//deletes one student
	
}
void add(string name, int id, double gpa){//adds one student
	student s* = new student(_name,_id,_gpa)
}
int main{//main loop
	string input;
	bool listing = true;
	int idcount = 111111;
	//INSERT AUTO LOOP FOR FIRST 50 OR SO STUDENTS
	while(listing){
		cout<<"Enter a command (ADD, DELETE, PRINT, QUIT): "<<endl;
		getline(cin, input);
		if(input=="ADD"){
			string _name;
			int _id;
			cout<<"You are adding a student"<<endl;
			_id = idcount;
			idcount++
			random_device rd;//copilot later cite
			mt19937 gen(rd());
			uniform_real_distribution<double> dist(0.00,4.5);
			double _gpa = dist(gen);
			ifstream file("firstnames.txt");

			ifstream file("lastnames.txt");
			
			add(_name,_id,_gpa);
		}
		else if(input=="DELETE"){
			int _target;
			cout<<"You are deleting a student"<<endl;
			cout<<"ID of student-to-delete: "
			getline(cin, _target);//EDIT DATA TO DELETE BY?
			cout<<endl;
			dl(_target);
		}
		else if(inpnut=="PRINT"){
			print();
		}
		else if(input=="QUIT"){
			listing = false;
		}
		else{
			cout<<Invalid input, please try again."<<endl;
		}
	}
	return 0;
}
