#include <iostream>
#include <string>
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
		//	cout<<"Bye Bye. //Date"<<endl;
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
						if(month == 6) cout<<"November";
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
	
	if(year %400 == 0){
		
		setLeapYear(1);
		
	}else{
		
		if(year %4 == 0 && year %100 != 0){

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

			s_address ="Unknow";
			district ="Unknow";
			country ="Unknow";
		}
		
		Address(string s_address, string district, string country){

			this->s_address = s_address;
			this->district = district;
			this->country = country;
		}
		
		~Address(){
		//	cout<<"Bye Bye. //Address";
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
		
		void a_setCountry(string country){
			this->country = country;
		}
		
		//getter
		string a_getAddress(){
			return s_address;
		}
		
		string a_getDistrict(){
			return district;
		}
		
		string a_getCountry(){
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
		//	cout<<"hello P //decon \n";
			firstName ="Unknow";
			lastName ="Unknow";
			Birth = 0;
			P_address = 0;	
		}
		
		Person(string f_name, string l_name, 
			   string s_address, string district, string country, 
			   int day, int month, int year)
		{
		//	cout<<"hello P //con \n";
			firstName = f_name;
			lastName = l_name;
			
			P_address = new Address(s_address, district, country);
			Birth = new Date(day, month, year);
			
		}
		
		//destructor
		~Person(){

			delete P_address;
			delete Birth;
		}
		
		//setter
		void p_set(string f_name, string l_name, 
			       string s_address, string district, string country, 
			       int day, int month, int year){

			firstName = f_name;
			lastName = l_name;
			
			P_address = new Address(s_address, district, country);
			Birth = new Date(day, month, year);
			
		}
		
		void P_setFirstName(string f){
			firstName = f;
		}
		
		void P_setLastName(string i){
			lastName = i;
		}
		
		void P_setAddress(string s_address, string district, string country){
			
			P_address-> a_setAddress (s_address);
			P_address-> a_setDistrict (district);
			P_address-> a_setCountry (country);
		}
		
		void P_setBirth(int day, int month, int year){
			
			Birth-> setDay (day);
			Birth-> setMonth (month);
			Birth-> setYear (year);
		}
		
		void P_setDay(int d){
			Birth-> setDay (d);
		}
		
		void P_setMonth(int m){
			Birth-> setMonth (m);
		}
		
		void P_setYear(int y){
			Birth-> setYear (y);
		}
		
		void P_setAddress(string a){
			P_address-> a_setAddress (a);
		}
		
		void P_setDistrict(string d){
			P_address-> a_setDistrict (d);
		}
		
		void P_setCountry(string c){
			P_address-> a_setCountry (c);
		}
		
		//getter
		string P_getFirstName(){
			return firstName;
		}
		
		string P_getLastName(){
			return lastName;
		}
		
		int P_getDay(){
			return Birth-> getDay();
		}
		
		int P_getMonth(){
			return Birth-> getMonth();
		}
		
		int P_getYear(){
			return Birth-> getYear();
		}
		
		string P_getAddress(){
			return P_address-> a_getAddress();
		}
	
		string P_getDistrict(){
			return P_address-> a_getDistrict();
		}
		
		string P_getCountry(){
			return P_address-> a_getCountry();
		}

		Address& P_getP_address(){
			return *P_address;
		}
		
		Date P_getBirth(){
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
		  " country."<<P_address-> a_getCountry() <<endl;
	
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
				int d, int m, int y, 
				string ad, string dis, string cou ):

		Person(f_name,l_name, 
			   ad, dis, cou,
			   d, m, y){
	
			ID = i;
			Faculty = f;
			Branch = b;
			Grade = g;
		//	p_set(f_name, l_name, ad, dis, cou, d, m, y);
		}
		
		~Student(){
		//	cout <<"/Student/ Bye Bye."<<endl;
		}
		
		//set
		void s_set(string i, string f, string b, string g, 
				string f_name, string l_name, 
				int d, int m, int y, 
				string ad, string dis, string cou ){
		
			ID = i;
			Faculty = f;
			Branch = b;
			Grade = g;
			p_set(f_name, l_name, ad, dis, cou, d, m, y);
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
		
		void s_setFirstName(string f){
			P_setFirstName(f);
		}
		
		void s_setLastName(string i){
			P_setLastName(i);
		}
		
		void s_setAddress(string s_address, string district, string country){
			
			P_setAddress(s_address, district, country);
		}
		
		void s_setBirth(int day, int month, int year){
			
			P_setBirth(day, month, year);
		}	
		
		void s_setDay(int d){
			P_setDay(d);
		}
		
		void s_setMonth(int m){
			P_setMonth(m);
		}
		
		void s_setYear(int y){
			P_setYear(y);
		}
		
		void s_setAddress(string a){
			P_setAddress(a);
		}
		
		void s_setDistrict(string d){
			P_setDistrict(d);
		}
		
		void s_setCountry(string c){
			P_setCountry(c);
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
		
		int s_getDay(){
			return P_getDay();
		}
		
		int s_getMonth(){
			return P_getMonth();
		}
		
		int s_getYear(){
			return P_getYear();
		}
		
		string s_getFirstName(){
			return P_getFirstName();
		}
		
		string s_getLastName(){
			return P_getLastName();
		}
		
		string s_getAddress(){
			return P_getAddress();
		}
		
		string s_getDistrict(){
			return P_getDistrict();
		}
		
		string s_getCountry(){
			return P_getCountry();
		}
		
		void findGrade();
		void s_show();
};

void Student::s_show(){
	cout<<"//Student"<<endl;
	cout<<"ID : "<< ID <<endl;
	cout<<"Faculty : "<< Faculty <<endl;
	cout<<"Branch : "<< Branch <<endl;
	cout<<"Grade : "<< Grade <<endl;
	cout<<endl;
	
	cout<<"//Person"<<endl;
	P_show();
	cout<<"/////////////////////////////////////////"<<endl;
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
				int d, int m, int y,
				string ad, string dis, string cou
				):

		Person(f_name,l_name, 
			   ad, dis, cou,
			   d, m, y){
		
			ID = i;
			Faculty = f;
			Course = c;
		//	p_set(f_name, l_name, ad, dis, cou, d, m, y);
		}
		
		Teacher(Teacher &x){
		
			ID = x.ID;
			Faculty = x.Faculty;
			Course = x.Course;
			
			p_set(x.P_getFirstName(), x.P_getLastName(),
		          x.P_getAddress(), x.P_getDistrict(), x.P_getCountry(),
			      x.P_getDay(), x.P_getMonth(), x.P_getYear() );
		}
		
		~Teacher(){
		//	cout<<"/Teacher/ Bye Bye."<<endl;
		}
		
		void t_set(string i, string f, string c,
				string f_name, string l_name, 
				int d, int m, int y,
				string ad, string dis, string cou){

			ID = i;
			Faculty = f;
			Course = c;
			p_set(f_name, l_name, ad, dis, cou, d, m, y);
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
		
				
		void t_setFirstName(string f){
			P_setFirstName(f);
		}
		
		void t_setLastName(string i){
			P_setLastName(i);
		}
		
		void t_setAddress(string s_address, string district, string country){
			
			P_setAddress(s_address, district, country);
		}
		
		void t_setBirth(int day, int month, int year){
			
			P_setBirth(day, month, year);
		}	
		
		void t_setDay(int d){
			P_setDay(d);
		}
		
		void t_setMonth(int m){
			P_setMonth(m);
		}
		
		void t_setYear(int y){
			P_setYear(y);
		}
		
		void t_setAddress(string a){
			P_setAddress(a);
		}
		
		void t_setDistrict(string d){
			P_setDistrict(d);
		}
		
		void t_setCountry(string c){
			P_setCountry(c);
		}
		
//get
		string t_getID(){
			return ID;
		}
		
		string t_getFaculty(){
			return Faculty;
		}
		
		string t_getCourse(){
			return Course;
		}
		
		int t_getDay(){
			return P_getDay();
		}
		
		int t_getMonth(){
			return P_getMonth();
		}
		
		int t_getYear(){
			return P_getYear();
		}
		
		string t_getFirstName(){
			return P_getFirstName();
		}
		
		string t_getLastName(){
			return P_getLastName();
		}
		
		string t_getAddress(){
			return P_getAddress();
		}
		
		string t_getDistrict(){
			return P_getDistrict();
		}
		
		string t_getCountry(){
			return P_getCountry();
		}

		void t_show();
};

void Teacher::t_show(){
	
	cout<<"//teacher"<<endl;
	cout<<"ID="<< ID <<endl;
	cout<<"Faculty="<< Faculty <<endl;
	cout<<"Course="<< Course <<endl;
	cout<<endl;
	cout<<"//Person"<<endl;
	P_show();
	cout<<"/////////////////////////////////////////"<<endl;
}

class TeachingAssistant:public Student, public Teacher{
	
	public :
		
		TeachingAssistant(){
						  	s_set("None","None","None","None","None","None",0,0,0,"None","None","None");
						  	t_set("None","None","None","None","None",0,0,0,"None","None","None");
		}
		TeachingAssistant(string i, string f, string b, string g, 
					      string f_name, string l_name, 
						  int d, int m, int y, 
						  string ad, string dis, string cou,
						  
						  string t_i, string t_f, string t_c,
						  string t_f_name, string t_l_name, 
						  int t_d, int t_m, int t_y,
						  string t_ad, string t_dis, string t_cou)
						  {
						  	
						  	s_set(i,f,b,g,f_name,l_name,d,m,y,ad,dis,cou);
						  	t_set(t_i,t_f,t_c,t_f_name,t_l_name,t_d,t_m,t_y,t_ad,t_dis,t_cou);
						  	
					      }
	
		void show();
};

void TeachingAssistant::show(){

	cout<<"//Teaching Assistant"<<endl;
	s_show();
	t_show();
}

int main(){
	
	cout<<"//a"<<endl;
	TeachingAssistant a("6005001497","Science","Computer Science","4.00",
	                    "Wachira","Thonglert",26,01,1999,"60/5","L.A.","USA",
	                    
					    "1002008989","Science","Computer Science",
						"Hatori","Hanzo",12,02,1950,"50/4","L.A.","USA");
	
	a.show();
/*
	TeachingAssistant *b = new TeachingAssistant();;
	b-> s_setID ("6005009987");
	b-> s_setFaculty ("Science");
	b-> s_setBranch ("Computer Science");
	b-> s_setGrade ("4.00");
	b-> s_setFirstName ("Wachira");
	b-> s_setLastName ("Thonglert");
	b-> s_setDay (8);
	b-> s_setMonth (11);
	b-> s_setYear (1998);
	b-> s_setAddress ("60/8");
	b-> s_setDistrict ("LA");
	b-> s_setCountry ("USA");
	
	b-> t_setID ("1002003837");
	b-> t_setFaculty ("Science");
	b-> t_setCourse ("COS2102");
	b-> t_setFirstName ("Zato");
	b-> t_setLastName ("kang");
	b-> t_setDay (6);
	b-> t_setMonth (1);
	b-> t_setYear (1940);
	b-> t_setAddress ("67/2");
	b-> t_setDistrict ("LA");
	b-> t_setCountry ("USA");
	
	cout<<"//Teaching Assistant"<<endl;
	
	cout<<"//Student"<<endl;
	cout<<"ID : "<< b-> s_getID() <<endl;
	cout<<"Faculty : "<< b-> s_getFaculty() <<endl;
	cout<<"Branch : "<< b-> s_getBranch() <<endl;
	cout<<"Grade : "<< b-> s_getGrade() <<endl;
	
	cout<<endl;
	cout<<"//Person"<<endl;
	
	cout<<"firstName = "<< b->s_getFirstName()<<endl;
	cout<<"lastName = "<< b->s_getLastName()<<endl;
	
	cout<<"Birth = "<< b-> s_getDay() <<"/"<<
	                   b-> s_getMonth() <<"/"<<
					   b-> s_getYear() <<endl;
	
	cout<<"Address = "<< b-> s_getAddress() <<
          " district."<< b-> s_getDistrict() <<
		  " country."<< b-> s_getCountry() <<endl;
	
	cout<<endl;
	cout<<"/////////////////////////////////////////"<<endl;
	
	
	cout<<"//teacher"<<endl;
	cout<<"ID="<< b-> t_getID() <<endl;
	cout<<"Faculty="<< b-> t_getFaculty() <<endl;
	cout<<"Course="<< b-> t_getCourse() <<endl;
	
	cout<<endl;
	cout<<"//Person"<<endl;
	
	cout<<"firstName = "<< b-> t_getFirstName()<<endl;
	cout<<"lastName = "<< b-> t_getLastName()<<endl;
	
	cout<<"Birth = "<< b-> t_getDay() <<"/"<<
	                   b-> t_getMonth() <<"/"<<
					   b-> t_getYear() <<endl;
	
	cout<<"Address = "<< b-> t_getAddress() <<
          " district."<< b-> t_getDistrict() <<
		  " country."<< b-> t_getCountry() <<endl;
	
	cout<<endl;
	cout<<"/////////////////////////////////////////"<<endl;*/
	return 0;
}
