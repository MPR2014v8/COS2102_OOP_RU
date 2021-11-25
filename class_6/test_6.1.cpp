#include<iostream>
#include<string>
using namespace std;

class Date{
	
	private : 

		int day;
		int month;
		int year;
		int leapYear;
	
	public :
	
		Date(){

			day = 0;
			month = 0;
			year = 0;
			find_leapYear();
		}
		Date(int day, int month, int year){

			this->day = day;
			this->month = month;
			this->year = year;
			find_leapYear();
		}

		Date(int day,int month){

			this->day = day;
			this->month = month;
			year = 0;
			find_leapYear();
		}
		Date(int day){

			this->day = day;
			month = 0;
			year = 0;
			find_leapYear();
		}

		~Date(){

			cout<<"Bye Bye. //Date"<<endl;
		}

		//set
		void d_set(int day, int month, int year){

			this->day = day;
			this->month = month;
			this->year = year;
			find_leapYear();
		}
		
		void setDay(int day){
			this->day = day;
		}
		
		void setMonth(int month){
			this->month = month;
		}
		
		void setYear(int year){

			this->year = year;
			find_leapYear();
		}
		
		void setLeapYear(int i){
			this->leapYear = i;
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
		
		void d_show();
		void find_leapYear();
};
void Date::d_show(){

	cout<<"day = "<<day<<" month = ";
						if(month == 1) cout<<"January";
						if(month == 2) cout<<"March";
						if(month == 3) cout<<"May";
						if(month == 4) cout<<"July";
						if(month == 5) cout<<"September";
						if(month ==6 ) cout<<"November";
						if(month == 7) cout<<"Fedruary";
						if(month == 8) cout<<"April";
						if(month == 9) cout<<"June";
						if(month == 10) cout<<"August";
						if(month == 11) cout<<"October";
						if(month == 12) cout<<"December";
	cout<<" year = "<< year <<endl;
	cout<<"Leap Year  ? = ";
						if(leapYear == 0) cout<<"No.";
						if(leapYear == 1) cout<<"Yes.";
	cout<<endl;
}

void Date::find_leapYear(){
	
	if(year % 400 == 0){
		
		setLeapYear(1);
		
	}else{
		
		if(year % 4 == 0 && year % 100 != 0){

			setLeapYear(1);
		}else{

			setLeapYear(0);
		}
		
	}
}

class Address{
	
	private : 
		//attribute
		string s_address;
		string district;
		string country;
		
	public :
		//constructor
		Address(){

			s_address="Unknow";
			district="Unknow";
			country="Unknow";
		}
		
		Address(string s_address, string district, string country){

			this->s_address = s_address;
			this->district = district;
			this->country = country;
		}
		
		~Address(){
			cout<<"Bye Bye. //Address";
		}
	
		//setter
		void a_set(string s_address, string district, string country){

			this->s_address = s_address;
			this->district = district;
			this->country = country;
		}
		
		void a_setAddress(string s_address){
			this->s_address = s_address;
		}
		
		void a_setDistrict(string district){
			this->district = district;
		}
		
		void a_setCounty(string country){
			this->country = country;
		}
		
		//getter
		string a_getAddress(){
			return s_address;
		}
		
		string a_getDistrict(){
			return district;
		}
		
		string a_getCounty(){
			return country;
		}
		
		void a_show();
};

void Address::a_show(){
	cout<<"Address="<< s_address <<endl;
	cout<<"District="<< district <<endl;
	cout<<"Country="<< country <<endl;
}


class Person{
	
	private :
		
		string firstName;
		string lastName;
		Date *Birth;
		Address *P_address;
		
	public :
		
		//constructor
		Person(){
			
			firstName ="Unknow";
			lastName ="Unknow";
			Birth = 0;
			P_address = 0;	
		}
		
		Person(string f_name, string l_name, 
			   string s_address, string district, string country, 
			   int day, int month, int year)
		{

			firstName = f_name;
			lastName = l_name;
			
			P_address = new Address(s_address, district, country);
			Birth = new Date(day, month, year);
			
		}
		
		//destructor
		~Person(){

			delete P_address;
			delete Birth;
			cout<<"/Person/ Bye Bye"<< firstName <<" "<< lastName <<". "<<endl;
		}
		
		//setter
		void p_set(string f_name, string l_name, 
			   string s_address, string district, string country, 
			   int day, int month, int year){

			firstName = f_name;
			lastName = l_name;
			
			delete P_address;
			delete Birth;
			
			P_address = new Address(s_address, district, country);
			Birth = new Date(day, month, year);
			
		}
		
		void P_setFirstName(string f){
			firstName = f;
		}
		
		void P_setLastName(string i){
			lastName = i;
		}
		
		void P_setP_address(string s_address, string district, string country){
			
			P_address-> a_setAddress (s_address);
			P_address-> a_setDistrict (district);
			P_address-> a_setCounty (country);
		}
		
		void P_setBirth(int day, int month, int year){
			
			Birth-> setDay (day);
			Birth-> setMonth (month);
			Birth-> setYear (year);
		}
		
		//getter
		string P_getFirstName(){
			return firstName;
		}
		
		string P_getLastName(){
			return lastName;
		}
		
		Address& P_getP_address(){
			return *P_address;
		}
		
		Date& P_getBirth(){
			return *Birth;
		}

		void P_show();
};

void Person::P_show(){
	
	cout<<"firstName = "<< firstName <<endl;
	cout<<"lastName = "<< lastName <<endl;
	
	cout<<"Birth = "<<Birth-> getDay() <<"/"<<
	                  Birth-> getMonth() <<"/"<<
					  Birth-> getYear() <<endl;
	
	cout<<"Address = "<<P_address-> a_getAddress() <<
          " district."<<P_address-> a_getDistrict() <<
		  " country."<<P_address-> a_getCounty() <<endl;
	
	cout<<endl;
	
}

class Student:public Person{
	
	private :

		string ID;
		string Faculty;
		string Branch;
		string Grade;
	
	public :
		
		Student(){
			
			ID ="Unknow";
			Faculty ="Unknow";
			Branch ="Unknow";
			Grade ="Unknow";
		}
		
		Student(string i, string f, string b, string g){
			
			ID = i;
			Faculty = f;
			Branch = b;
			Grade = g;
		}
		
		Student(string i, string f, string b, string g, 
				string f_name, string l_name, 
				string ad, string dis, string cou,
				int d, int m, int y  ):

		Person(f_name,l_name, 
			   ad, dis, cou,
			   d, m, y){
			
			ID = i;
			Faculty = f;
			Branch = b;
			Grade = g;
		//	p_set(f_name, l_name, ad, dis, cou, d, m, y);
			//set
		}
		
		~Student(){
			cout<<"/Student/ Bye Bye."<<endl;
		}
		
		//set
		void s_set(string i, string f, string b, string g){
			
			ID = i;
			Faculty = f;
			Branch = b;
			Grade = g;
		}
		
		void s_setID(string i){
			ID = i;
		}
		
		void s_setFaculty(string f){
			Faculty = f;
		}
		
		void s_setBranch(string b){
			Branch = b;
		}
		
		void s_setGrade(string g){
			Grade = g;
		}
		
		//get
		
		string s_getID(){
			return ID;
		}
		
		string s_getFaculty(){
			return Faculty;
		}
		
		string s_getBranch(){
			return Branch;
		}
		
		string s_getGrade(){
			return Grade; 
		}
		
		void findGrade();
		void s_show();
};

void Student::s_show(){
	
	cout<<"ID : "<< ID <<endl;
	cout<<"Faculty : "<< Faculty <<endl;
	cout<<"Branch : "<< Branch <<endl;
	cout<<"Grade : "<< Grade <<endl;
	cout<<endl;
}

void Student::findGrade(){
	
	int num_cos2101, num_cos2102, num_cos2103;
	string c;
	
	cout<<"COS2101="; cin>>num_cos2101;
	
	c ="";
	
	if(num_cos2101 >= 80) c="COS2101=A ";
	if(num_cos2101 >= 70 && num_cos2101 < 80) c+="COS2101=B ";
	if(num_cos2101 >= 60 && num_cos2101 < 70) c+="COS2101=C ";
	if(num_cos2101 >= 50 && num_cos2101 < 60) c+="COS2101=D ";
	if(num_cos2101 < 50) c+="COS2101=F ";
	
	cout<<"COS2102="; cin>>num_cos2102;
	
	if(num_cos2102 >= 80) c+="COS2102=A ";
	if(num_cos2102 >= 70 && num_cos2102 < 80) c+="COS2102=B ";
	if(num_cos2102 >= 60 && num_cos2102 < 70) c+="COS2102=C ";
	if(num_cos2102 >= 50 && num_cos2102 < 60) c+="COS2102=D ";
	if(num_cos2102 < 50) c+="COS2102=F ";
	
	cout<<"COS2103="; cin>>num_cos2103;
	
	if(num_cos2103 >= 80) c+="COS2103=A ";
	if(num_cos2103 >= 70 && num_cos2103 < 80) c+="COS2103=B ";
	if(num_cos2103 >= 60 && num_cos2103 < 70) c+="COS2103=C ";
	if(num_cos2103 >= 50 && num_cos2103 < 60) c+="COS2103=D ";
	if(num_cos2103 < 50) c+="COS2103=F ";
	
	s_setGrade(c);
}

class Teacher:public Person{
	
	private:
		string ID;
		string Faculty;
		string Course;
		
	public:
		Teacher(){
			
			ID ="Unknow";
			Faculty ="Unknow";
			Course ="Unknow";
		}
		
		Teacher(string i, string f, string c){
			
			ID = i;
			Faculty = f;
			Course = c;
		}
		
		Teacher(string i, string f, string c,
				string f_name, string l_name, 
				string ad, string dis, string cou,
				int d, int m, int y):

		Person(f_name,l_name, 
			   ad, dis, cou,
			   d, m, y){
			
			ID = i;
			Faculty = f;
			Course = c;
			
		//	p_set(f_name, l_name, ad, dis, cou, d, m, y);
		}
		
		~Teacher(){
			cout<<"/Teacher/ Bye Bye."<<endl;
		}
		
		void t_set(string i, string f, string c){

			ID = i;
			Faculty = f;
			Course = c;
		}
		
		void t_setID(string i){
			ID = i;
		}
		
		void t_setFaculty(string f){
			Faculty = f;
		}
		
		void t_setCourse(string c){
			Course = c;
		}
		
		string t_getID(){
			return ID;
		}
		
		string t_getFaculty(){
			return Faculty;
		}
		
		string t_getCourse(){
			return Course;
		}
		void t_show();
};

void Teacher::t_show(){
	
	cout<<"ID="<< ID <<endl;
	cout<<"Faculty="<< Faculty <<endl;
	cout<<"Course="<< Course <<endl;
}

int main(){
	
	cout<<"//Person"<<endl;
	Person *test = new Person("Chirs","Redfield","60/5","Texas","USA",11,11,1999);
	test-> P_show();
	
	cout<<"//Student"<<endl;
	Student *b= new Student("6005001987","sience","computer","A","Tomb","Rider","50/8","Las Vegas","USA",25,01,1998);
	
	b-> s_show();
	b-> P_show();
	
	cout<<"//Teacher"<<endl;
	Teacher *a = new Teacher("1004009495","sicence","cos2102");
	a-> p_set("Mina","Hamburg","40/7","Miami","USA",29,02,1975);
	a-> t_show();

	cout<<endl;
	a-> P_show();
	
	return 0;

}
