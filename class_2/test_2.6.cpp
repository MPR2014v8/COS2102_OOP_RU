#include <iostream>
#include <string.h>
using namespace std;

class Address{
	
	private : 
		//attribute
		string s_address;
		string district;
		string county;
		
	public :
		//constructor
		Address(){
			s_address="Unknow";
			district="Unknow";
			county="Unknow";
		}
		
		Address(string s_address, string district, string county){
			this->s_address=s_address;
			this->district=district;
			this->county=county;
		}
		
		~Address(){
			cout<<"Bye Bye. //Address";
		}
		
		//setter
		void set(string s_address, string district, string county){
			this->s_address=s_address;
			this->district=district;
			this->county=county;
		}
		
		void setAddress(string s_address){
			this->s_address=s_address;
		}
		
		void setDistrict(string district){
			this->district=district;
		}
		
		void setCounty(string county){
			this->county=county;
		}
		
		//getter
		string getAddress(){
			return s_address;
		}
		
		string getDistrict(){
			return district;
		}
		
		string getCounty(){
			return county;
		}
		
		void show();
};

void Address::show(){
	cout<<"Address="<<s_address<<endl;
	cout<<"District="<<district<<endl;
	cout<<"County="<<county<<endl;
}

main(){
	
	Address a;
	a.set("60/5","yoshiki","japan");
	a.show();	
	
}
