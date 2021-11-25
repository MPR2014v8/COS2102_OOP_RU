#include <iostream>
#include <math.h>
using namespace std;

class Complex{
	
	private : 
	//Attribute
		double num_Real;
		double num_Imaginary;
		double size_Complex;

	public :
	//constructor
		Complex(){
			num_Real=0.0;
			num_Imaginary=0.0;
		}
		
		Complex(double x, double y){
			num_Real=x;
			num_Imaginary=y;
		}
		
		Complex(double x){
			num_Real=x;
			num_Imaginary=0.0;
		}
	//destructor	
		~Complex(){
			cout<<"Bye Bye. //Complex"<<endl;
		}
	//setter
		void set(double x, double y){
			num_Real=x;
			num_Imaginary=y;
		}
		void setX(double x){
			num_Real=x;
		}
		void setY(double y){
			num_Imaginary=y;
		}
		void setSizeCoplex(double i){
			size_Complex=i;
		}
	//getter
		double getX(){
			return num_Real;
		}
		double getY(){
			return num_Imaginary;
		}
		double getSizeCoplex(){
			return size_Complex;
		}
		void show();
		void sizeComplex();
};

void Complex::show(){
	cout<<"X="<<num_Real<<endl;
	cout<<"Y="<<num_Imaginary<<endl;
}

void Complex::sizeComplex(){
	double total,x,y,ans;
	
	x=num_Real*num_Real;
	y=num_Imaginary*num_Imaginary;
	
	total=x+y;
	ans=sqrt(total);
	setSizeCoplex(ans);
	cout<<"Size="<<size_Complex<<endl;
}

 main(){
	
	Complex a;
	a.set(9,3);
	a.show();
	a.sizeComplex();
	
	
}
