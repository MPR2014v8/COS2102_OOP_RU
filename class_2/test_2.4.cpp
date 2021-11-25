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
			cout<<"Bye Bye."<<endl;
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
		
		void show();
};

void Person::show(){
	
	cout<<"firstName = "<<firstName<<endl;
	cout<<"lastName = "<<lastName<<endl;
	cout<<"Birth = "<<Birth<<endl;
	cout<<endl;
	
}

int Person::countObj;

int main(){
	
	//test
	
	Person a("Fujitora", "ken", "10/01/1999");
	a.show();
	
	
	return 0;
}
