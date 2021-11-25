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
	
		Date()
		{
			day = 0;
			month = 0;
			year = 0;
			find_leapYear();
		}

		Date(int day, int month, int year)
		{
			this->day = day;
			this->month = month;
			this->year = year;
			find_leapYear();
		}

		Date(int day,int month)
		{
			this->day = day;
			this->month = month;
			year = 0;
			find_leapYear();
		}

		Date(int day)
		{
			this->day = day;
			month = 0;
			year = 0;
			find_leapYear();
		}

		Date(Date &d)
		{
			day = d.getDay();
			month = d.getMonth();
			year = d.getYear();
			find_leapYear();
		}

		~Date(){
		//	cout<<"Bye Bye. //Date"<<endl;
		}

		//set
		void d_set(int day, int month, int year)
		{
			this->day = day;
			this->month = month;
			this->year = year;
			find_leapYear();
		}
		
		void setDay(int day)
		{
			this->day = day;
		}
		
		void setMonth(int month)
		{
			this->month = month;
		}
		
		void setYear(int year)
		{
			this->year = year;
			find_leapYear();
		}
		
		void setLeapYear(int i)
		{
			this->leapYear = i;
		}
		
		//get
		int getDay()
		{
			return day;
		}
		
		int getMonth()
		{
			return month;
		}
		
		int getYear()
		{
			return year;
		}
		
		int getLeapYear()
		{
			return leapYear;
		}
		
		void d_show();
		void find_leapYear();
};

void Date::d_show()
{
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

void Date::find_leapYear()
{	
	if(year %400 == 0)
	{	
		setLeapYear(1);
		
	}else{
		
		if(year %4 == 0 && year %100 != 0)
		{
			setLeapYear(1);
		}
		else
		{

			setLeapYear(0);
		}
		
	}
}

class Address
{
	private : 
		//attribute
		string s_address;
		string district;
		string country;
		
	public :
		//constructor
		Address()
		{
			s_address ="Unknow";
			district ="Unknow";
			country ="Unknow";
		}
		
		Address(string s_address, string district, string country)
		{
			this->s_address = s_address;
			this->district = district;
			this->country = country;
		}
		Address(Address &a)
		{
			s_address = a.a_getAddress();
			district = a.a_getDistrict();
			country = a.a_getCountry();
		}
		
		~Address(){
		//	cout<<"Bye Bye. //Address";
		}
	
		//setter
		void a_set(string s_address, string district, string country)
		{
			this->s_address = s_address;
			this->district = district;
			this->country = country;
		}
		
		void a_setAddress(string s_address)
		{
			this->s_address = s_address;
		}
		
		void a_setDistrict(string district)
		{
			this->district = district;
		}
		
		void a_setCountry(string country)
		{
			this->country = country;
		}
		
		//getter
		string a_getAddress()
		{
			return s_address;
		}
		
		string a_getDistrict()
		{
			return district;
		}
		
		string a_getCountry()
		{
			return country;
		}
		
		void a_show();
};

void Address::a_show()
{
	cout<<"Address="<< s_address <<endl;
	cout<<"District="<< district <<endl;
	cout<<"Country="<< country <<endl;
}

class Person
{
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
			Birth = new Date();
			P_address = new Address();	
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

		Person(Person &p){
		
			firstName = p.P_getFirstName();
			lastName = p.P_getLastName();

			delete Birth;
			delete P_address;

			Birth = new Date();
			P_address = new Address();	
		}
		
		//destructor
		~Person(){

			delete P_address;
			delete Birth;
		}
		
		//set
		virtual void P_set(string f_name, string l_name, 
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

class Student:virtual public Person{
	
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
		//Ta เรียกใช้
		Student(string i, string f, string b, string g, 
				string f_name, string l_name, 
				int d, int m, int y, 
				string ad, string dis, string cou ):

		Person(f_name,l_name, 
			   ad, dis, cou,
			   d, m, y){
			cout<<"Hello con std"<<endl;
			ID = i;
			Faculty = f;
			Branch = b;
			Grade = g;
		//	p_set(f_name, l_name, ad, dis, cou, d, m, y);
		}

		Student(Student &s)
		{
			ID = s.s_getID();;
			Faculty = s.s_getFaculty();
			Branch = s.s_getBranch();
			Grade = s.s_getGrade();

			P_setFirstName(s.P_getFirstName());
			P_setLastName(s.P_getLastName());
			P_setAddress(s.P_getAddress(), s.P_getDistrict(), s.P_getCountry());
			P_setBirth(s.P_getDay(), s.P_getMonth(), s.P_getYear());	
		}
		
		~Student(){
		//	cout <<"/Student/ Bye Bye."<<endl;
		}
		
		//set

		void P_set(string i, string f, string b, string g,
			       string f_name, string l_name, 
			       string s_address, string district, string country, 
			       int day, int month, int year){

			ID = i;
			Faculty = f;
			Branch = b;
			Grade = g;

			P_setFirstName(f_name);
			P_setLastName(l_name);
			P_setAddress(s_address, district, country);
			P_setBirth(day, month, year);
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

class Teacher:virtual public Person{
	
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
		//Ta เรียกใช้
		Teacher(string i, string f, string c,
				string f_name, string l_name, 
				int d, int m, int y,
				string ad, string dis, string cou
				):

		Person(f_name,l_name, 
			   ad, dis, cou,
			   d, m, y){
		cout<<"Hello con t"<<endl;
			ID = i;
			Faculty = f;
			Course = c;
		//	p_set(f_name, l_name, ad, dis, cou, d, m, y);
		}
		
		Teacher(Teacher &x){
		
			ID = x.ID;
			Faculty = x.Faculty;
			Course = x.Course;
			
			P_setFirstName( x.P_getFirstName() ); 
			P_setLastName( x.P_getLastName() ); 
			P_setAddress( x.P_getAddress(), 
		                  x.P_getDistrict(),
		                  x.P_getCountry() );
			P_setBirth(x.P_getDay(), 
			           x.P_getMonth(), 
			           x.P_getYear() );
		        			      
		}
		
		~Teacher(){
		//	cout<<"/Teacher/ Bye Bye."<<endl;
		}
		
		void P_set(string i, string f, string c,
			       string f_name, string l_name, 
			       string s_address, string district, string country, 
			       int day, int month, int year){
			cout<<"Hello std ";
			ID = i;
			Faculty = f;
			Course = c;

			P_setFirstName(f_name);
			P_setLastName(l_name);
			P_setAddress(s_address, district, country);
			P_setBirth(day, month, year);
			cout<<"firstName="<<P_getFirstName()<<endl;
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

class TeachingAssistant: public Student, public Teacher{

	string year;
	string term;
	
	public :
		
		TeachingAssistant(){

        	year = "Unknow";
        	term = "Unknow";
        }

		TeachingAssistant(string i, string f, string b, string g, 
					      string f_name, string l_name, 
						  int d, int m, int y, 
						  string ad, string dis, string cou,
						  
						  string t_i, string t_f, string t_c,

						  string ye, string te)/*:

		Student(i, f, b, g),
		Teacher(t_i, t_f, t_c),
		Person( f_name, l_name, ad, dis, cou, d, m, y)*/

		:
		Student(i, f, b, g, f_name, l_name, d, m, y, ad, dis, cou),
		Teacher(t_i, t_f, t_c, f_name, l_name, d, m, y, ad, dis, cou)

		/*,
		Person( f_name, l_name, ad, dis, cou, d, m, y)*/
		{
			year = ye;
			term = te;
		}

		TeachingAssistant(TeachingAssistant &tA)
		{
        	year = tA.getYear();
        	term = tA.getTerm();

        	s_setID(tA.s_getID());
			s_setFaculty(tA.s_getFaculty());
			s_setBranch(tA.s_getBranch());
			s_setGrade(tA.s_getGrade());

			P_setFirstName(tA.P_getFirstName());
			P_setLastName(tA.P_getLastName());
			P_setDay(tA.P_getDay());
			P_setMonth(tA.P_getMonth());
			P_setYear(tA.P_getYear());
			P_setAddress(tA.P_getAddress());
			P_setDistrict(tA.P_getDistrict());
			P_setCountry(tA.P_getCountry());

			t_setID(tA.t_getID());
			t_setFaculty(tA.t_getFaculty());
			t_setCourse(tA.t_getCourse());

        }

		~TeachingAssistant(){
			cout<<"Bye Bye. //TeachingAssistant"<<endl;
		}

		void set( string i, string f, string b, string g, 

			      string f_name, string l_name, 
				  int d, int m, int y, 
				  string ad, string dis, string cou,
				  
				  string t_i, string t_f, string t_c,

				  string ye, string te )
		{
			s_setID(i);
			s_setFaculty(f);
			s_setBranch(b);
			s_setGrade(g);

			P_setFirstName(f_name);
			P_setLastName(l_name);
			P_setDay(d);
			P_setMonth(m);
			P_setYear(y);
			P_setAddress(ad);
			P_setDistrict(dis);
			P_setCountry(cou);

			t_setID(t_i);
			t_setFaculty(t_f);
			t_setCourse(t_c);

			year = ye;
			term = te;
		}

		void setYear(string y){
			year = y;
		}

		void setTerm(string t){
			term = t;
		}

		string getYear(){
			return year;
		}

		string getTerm(){
			return term;
		}

		void show();
};

void TeachingAssistant::show(){

	cout<<"//TeachingAssistant show"<<endl;
	cout<<"ID : "<< s_getID() <<endl;
	cout<<"Faculty : "<< s_getFaculty() <<endl;
	cout<<"Branch : "<< s_getBranch() <<endl;
	cout<<"Grade : "<< s_getGrade() <<endl;
	cout<<"First Name : "<< s_getFirstName() <<endl;
	cout<<"Last Name : "<< s_getLastName() <<endl;
	cout<<"Address : "<< s_getAddress() <<endl;
	cout<<"District : "<< s_getDistrict() <<endl;
	cout<<"Country : "<< s_getCountry() <<endl;
	cout<<"Birth : "<< s_getDay() <<"/"<< s_getMonth() <<"/"<< s_getYear() <<endl;
	cout<<"Teaching year : "<< year <<endl;
	cout<<"Teaching term : "<< term <<endl;
}

int main(){
	
	TeachingAssistant *a = new TeachingAssistant("6005001497","Science","Computer Science","A+",
												 "Wachira","Thonglert",
												 26,1,1999,
												 "60/5","Udontani","Thailand",
												 "1002001497","Science","COS2103",
												 "2017","2");
	a->show();
	cout<<"/////////////////////////////////////////"<<endl;
    a->t_show();
    a->s_show();

	return 0;
}
