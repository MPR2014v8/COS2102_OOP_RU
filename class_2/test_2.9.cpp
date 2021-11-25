#include <iostream>
using namespace std;

class Date{
	
	private : 
		int day;
		int month;
		int year;
		int leapYear;
	
	public :
	
		Date(){
			day=0;
			month=0;
			year=0;
		}
		Date(int day, int month, int year){
			this->day=day;
			this->month=month;
			this->year=year;
		}
		Date(int day,int month){
			this->day=day;
			this->month=month;
			year=0;
		}
		Date(int day){
			this->day=day;
			month=0;
			year=0;
		}
		~Date(){
			cout<<"Bye Bye. //Date"<<endl;
		}
		//set
		void set(int day, int month, int year){
			this->day=day;
			this->month=month;
			this->year=year;
		}
		
		void setDay(int day){
			this->day=day;
		}
		
		void setMonth(int month){
			this->month=month;
		}
		
		void setYear(int year){
			this->year=year;
		}
		
		void setLeapYear(int i){
			this->leapYear=i;
		}
		
		//get
		int getDay(){
			return day;
		}
		
		int getMonth(){
			return month;
		}
		
		int getYear(){
			return year;
		}
		
		int getLeapYear(){
			return leapYear;
		}
		
		void show();
		void find_leapYear();
};
void Date::show(){

	cout<<"day = "<<day<<" month = ";
						if(month==1) cout<<"January";
						if(month==2) cout<<"March";
						if(month==3) cout<<"May";
						if(month==4) cout<<"July";
						if(month==5) cout<<"September";
						if(month==6) cout<<"November";
						if(month==7) cout<<"Fedruary";
						if(month==8) cout<<"April";
						if(month==9) cout<<"June";
						if(month==10) cout<<"August";
						if(month==11) cout<<"October";
						if(month==12) cout<<"December";
	cout<<" year = "<<year<<endl;
	cout<<"Leap Year  ? = ";
						if(leapYear==0) cout<<"No.";
						if(leapYear==1) cout<<"Yes.";
	cout<<endl;
}

void Date::find_leapYear(){
	
	if(year%400==0){
		
		setLeapYear(1);
		
	}else{
		
		if(year%4==0 && year%100!=0){
			setLeapYear(1);
		}else{
			setLeapYear(0);
		}
		
	}
}

int main(){
	
	Date a(1,1,2012);
	a.find_leapYear();
	a.show();
	
 	return 0;
}
