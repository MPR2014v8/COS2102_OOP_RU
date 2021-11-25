#include <iostream>
#include <string.h>
using namespace std;

class Person{
	
	private :
		
		static int countObj;
		char firstName[20];
		char lastName[20];
		char Birth[20];
		
	public :
		
		//constructor
		Person(){
			
			countObj++;
			strcpy(firstName, "Unknow");
			strcpy(lastName, "Unknow");
			strcpy(Birth, "Unknow");
		}
		
		Person(char *firstName){
			
			countObj++;
			strcpy(this->firstName, firstName);
			strcpy(lastName, "Unknow");
			strcpy(Birth, "Unknow");
		}
		
		Person(char *firstName, char *lastName){
			
			countObj++;
			strcpy(this->firstName, firstName);
			strcpy(this->lastName, lastName);
			strcpy(Birth, "Unknow");
		}
		
		Person(char *firstName, char *lastName, char *Birth){
			
			countObj++;
			strcpy(this->firstName, firstName);
			strcpy(this->lastName, lastName);
			strcpy(this->Birth, Birth);
			
		}
		
		//destructor
		~Person(){
			countObj--;
			cout<<"Bye Bye. //Person"<<endl;
		}
		
		//setter
		void set(char *firstName, char *lastName, char *Birth){
			strcpy(this->firstName, firstName);
			strcpy(this->lastName, lastName);
			strcpy(this->Birth, Birth);
		}
		
		void setFirstName(char *firstName){
			strcpy(this->firstName, firstName);
		}
		
		void setLastName(char *lastName){
			strcpy(this->lastName, lastName);
		}
		
		void setBirth(char *Birth){
			strcpy(this->Birth, Birth);
		}
		
		//getter
		char* getFirstName(){
			return firstName;
		}
		
		char* getLastName(){
			return lastName;
		}
		
		char* getBirth(){
			return Birth;
		}
		
		//countObject
		static int getCountObj(){
			return countObj;
		}
		
};

int Person::countObj;

class Student{
	
	private :
		Person *NEW;
		char ID[13];
		char Faculty[13];
		char Branch[13];
		string Grade;
	
	public :
		Student(){
			NEW=new Person();
			strcpy(ID,"Unknow");
			strcpy(Faculty,"Unknow");
			strcpy(Branch,"Unknow");
			Grade= "Unknow";
		}
		
		Student(char *firstName, char *lastName, char *Birth, char *ID, char *Faculty, char *Branch){
			NEW=new Person(firstName, lastName, Birth);
			strcpy(this->ID, ID);
			strcpy(this->Faculty, Faculty);
			strcpy(this->Branch, Birth);
			Grade = "Unknow";
		}
		
		~Student(){
			delete NEW;
			cout << "Bye Bye. //Student"<<endl;
		}
		
		//set
		void set(char *firstName, char *lastName, char *Birth, char *ID, char *Faculty, char *Branch){
			NEW->set(firstName, lastName, Birth);
			strcpy(this->ID, ID);
			strcpy(this->Faculty, Faculty);
			strcpy(this->Branch, Birth);
		}
		
		void setFirstName(char *firstName){
			NEW->setFirstName(firstName);
		}
		
		void setLastName(char *lastName){
			NEW->setLastName(lastName);
		}
		
		void setBirth(char *Birth){
			NEW->setBirth(Birth);
		}
		
		void setID(char *ID){
			strcpy(this->ID, ID);
		}
		
		void setFaculty(char *Faculty){
			strcpy(this->Faculty, Faculty);
		}
		
		void setBranch(char *Branch){
			strcpy(this->Branch, Branch);
		}
		
		void setGrade(string Grade){
			this->Grade=Grade;
		}
		
		//get
		char* getFirstName(){
			return NEW->getFirstName();
		}
		
		char* getLastName(){
			return NEW->getLastName();
		}
		
		char* getBirth(){
			return NEW->getBirth();
		}
		
		char* getID(){
			return ID;
		}
		
		char* getFaculty(){
			return Faculty;
		}
		
		char* getBranch(){
			return Branch;
		}
		
		string getGrade(){
			return Grade; 
		}
		
		int getNumGrade(){
			return Grade.length();
		}
		
		void findGrade();
		void show();
};

void Student::show(){
	
	cout<<"Name : "<<NEW->getFirstName()<<" "<<NEW->getLastName()<<endl;
	cout<<"Birth : "<<NEW->getBirth()<<endl;
	cout<<"ID : "<<ID<<endl;
	cout<<"Faculty : "<<Faculty<<endl;
	cout<<"Branch : "<<Branch<<endl;
	cout<<"Grade : "<<Grade<<endl;
	cout<<endl;
}

void Student::findGrade(){
	
	int num_cos2101, num_cos2102, num_cos2103;
	string c;
	
	cout<<"COS2101="; cin>>num_cos2101;
	
	c ="";
	
	if(num_cos2101>=80) c="COS2101=A ";
	if(num_cos2101>=70 && num_cos2101<80) c+="COS2101=B ";
	if(num_cos2101>=60 && num_cos2101<70) c+="COS2101=C ";
	if(num_cos2101>=50 && num_cos2101<60) c+="COS2101=D ";
	if(num_cos2101<50) c+="COS2101=F ";
	
	cout<<"COS2102="; cin>>num_cos2102;
	
	if(num_cos2102>=80) c+="COS2102=A ";
	if(num_cos2102>=70 && num_cos2102<80) c+="COS2102=B ";
	if(num_cos2102>=60 && num_cos2102<70) c+="COS2102=C ";
	if(num_cos2102>=50 && num_cos2102<60) c+="COS2102=D ";
	if(num_cos2102<50) c+="COS2102=F ";
	
	cout<<"COS2103="; cin>>num_cos2103;
	
	if(num_cos2103>=80) c+="COS2103=A ";
	if(num_cos2103>=70 && num_cos2103<80) c+="COS2103=B ";
	if(num_cos2103>=60 && num_cos2103<70) c+="COS2103=C ";
	if(num_cos2103>=50 && num_cos2103<60) c+="COS2103=D ";
	if(num_cos2103<50) c+="COS2103=F ";
	
	setGrade(c);
}


int main(){
	
	Student a("Wachira","Thonglert","26/01/1999","6005001497","Science","Computer Science");
	a.show();
	cout<<"------------------------"<<endl;
	a.findGrade();
	cout<<"------------------------"<<endl;
	a.show();
	return 0;
}
