#include <iostream>
using namespace std;

class Employee{
	
	private : 
		string id;
		string name;
		string lastName;
		double salary;
		double rate;
		double n_rate;
		
	public :
		
		Employee(){
			
			id="Unknow";
			name="Unknow";
			lastName="Unknow";
			salary=0;
			rate=0;	
			
		}
		
		Employee(string id, string name, string lastName, double salary);
		
		~Employee(){
			
			cout<<"Bye Bye. //Employee"<<endl;
			
		}
		
		//set
		void set(string id, string name, string lastName, double salary, double rate){
			
			this->id=id;
			this->name=name;
			this->lastName=lastName;
			this->salary=salary;
			this->rate=rate;	
			
		}
		
		void setID(string id){
			
			this->id=id;	
			
		}
		
		void setName(string name){
			
			this->name=name;	
			
		}
		
		void setLastName(string lastName){
			
			this->lastName=lastName;	
			
		}
		
		void setSalary(double salary){
			
			this->salary=salary;	
			
		}
		
		void setRate(double rate){
			
			this->rate=rate;	
			
		}
		
		void setN_Rate(double i){
			
			this->n_rate=i;
			
		}
		
		//get
		string getID(){
			
			return id;	
			
		}
		
		string getName(){
			
			return name;	
			
		}
		
		string getLastName(){
			
			return lastName;
				
		}
		
		double getSalary(){
			
			return salary;	
			
		}
		
		double getRate(){
			
			return rate;
				
		}
		
		double getN_Rate(){
			
			return n_rate;
			
		}
		
	
	void show();
	void find_rate();	
};

Employee::Employee(string id, string name, string lastName, double salary){
	
			this->id=id;
			this->name=name;
			this->lastName=lastName;
			this->salary=salary;
			rate=0.0;
			find_rate();	
			
}

void Employee::show(){
	
	cout<<"ID="<<id<<endl;
	cout<<"NAME="<<name<<endl;
	cout<<"LAST NAME="<<lastName<<endl;
	cout<<"SALARY="<<salary<<endl;
	cout<<"TAX RATE="<<rate<<endl;
	cout<<"RATE="<<n_rate<<endl;
	
}

void Employee::find_rate(){
	
	if(salary<150000) setRate(0.05); 
	if(salary>=150000 && salary<=300000) setRate(0.05);
	if(salary>=300000 && salary<=500000) setRate(0.1); 
	if(salary>=500000 && salary<=750000) setRate(0.15);
	if(salary>=750000 && salary<=1000000) setRate(0.2);
	if(salary>=1000000 && salary<=2000000) setRate(0.25); 
	if(salary>=2000000 && salary<=5000000) setRate(0.3);
	if(salary>5000000) setRate(0.35); 
		
	double temp;
	temp = salary*rate;
	setN_Rate(temp);
	
}

int main(){
	
	Employee a("1411701299211","Wachira","Thonglert",800000);
	a.show();
	
	return 0;
}
