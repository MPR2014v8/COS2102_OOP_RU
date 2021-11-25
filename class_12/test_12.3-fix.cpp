#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

class Rectangle{
	
	private:
		
		double width;
		double height;
		double r_area;
		
	public:
		
		Rectangle(){

			width =0;
			height =0;
			r_area =0;

		}
		
		Rectangle(double w, double h){
			
			width = w;
			height = h;
			r_area = width * height;
		}
		
		void setWidth(double w){
			width = w;
			r_area = width * height;
		}
		
		void setHeight(double h){
			height = h;
			r_area = width * height;
		}
		
		double getWidth(){
			return width;
		}
		
		double getHeight(){
			return height;
		}
		
		double getArea(){
			return r_area;
		}

		friend ostream& operator << (ostream &os, Rectangle &p);
		friend istream& operator >> (istream &is, Rectangle &p);
};

ostream& operator << (ostream &os, Rectangle &p){

	cout<<"//show\n";
	os<<"Width : "<< p.width <<endl;
	os<<"Height : "<< p.height <<endl;
	os<<"Area : "<< p.r_area <<endl;

	return os;
}

istream& operator >> (istream &is, Rectangle &p) 
{
	cout<<"Width : "; is>>p.width; 

	if( p.width < 0.001 ) throw 0;
	if (p.width > 10000) throw 1.0;
	
	cout<<"Height : "; is>>p.height; 

	if( p.height < 0.001 ) throw 0; 
	if (p.height > 10000) throw 0.1;
	
	p.r_area = p.width * p.height;

	return is;
}

int main(){

try
{
	Rectangle a;
	cin>>a;
	cout<<a;
}

catch(int){
	cout<<"The number less than bound. ";
}
catch(double){
	cout<<"The number great than bound";
}

	return 0;
}