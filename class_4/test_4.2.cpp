#include <iostream>
#include <math.h>
using namespace std;

class Complex{
	
	private : 
	//Attribute
		double num_Real;
		double num_Imaginary;
		double size_Complex;
		double plus_x, plus_y, times_x, times_y;

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
		void setPlus(double x, double y){
			plus_x=x;
			plus_y=y;
		}
		void setPlusX(double x){
			plus_x=x;
		}
		void setPlusY(double y){
			plus_y=y;
		}
		void setTimes(double x, double y){
			times_x=x;
			times_y=y;
		}
		void setTimeX(double x){
			times_x=x;
		}
		void setTimeY(double y){
			times_y=y;
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
		double getPlusX(){
			return plus_x;
		}
		double getPlusY(){
			return plus_y;
		}
		double getTimeX(){
			return times_x;
		}
		double getTimeY(){
			return times_y;
		}
		
		Complex plus(Complex& x, Complex& y);
		Complex times(Complex& x, Complex& y);
		void show();
		void sizeComplex();
};

void Complex::show(){
	cout<<"X="<<num_Real<<endl;
	cout<<"Y="<<num_Imaginary<<endl;
}

void Complex::sizeComplex(){
	
	//find complex size
	
	double total,x,y,ans;
	
	x=num_Real*num_Real;
	y=num_Imaginary*num_Imaginary;
	
	total=x+y;
	ans=sqrt(total);
	setSizeCoplex(ans);
	cout<<"Size="<<size_Complex<<endl;
}
Complex Complex::plus(Complex& x, Complex& y){
	
	double tempX, tempY;
	
	tempX=x.getX()+y.getX();
	tempY=x.getY()+y.getY();
	
	Complex temp;
	temp.setPlus(tempX,tempY);
	
	return temp;
	
}
Complex Complex::times(Complex& x, Complex& y){
	
	double tempX, tempY;
	Complex temp;
	
	//real
	tempX=x.getX()*y.getX();
	tempY=x.getY()*y.getY();
	tempX=tempX-tempY;
	
	temp.setTimeX(tempX);
	
	//Imaginary
	tempX=x.getX()*y.getY();
	tempY=x.getY()*y.getX();
	tempY=tempX+tempY;
	
	temp.setTimeY(tempY);
	
	return temp;
}

int main(){
	
	Complex a(1,2),b(2,4);
	
	Complex temp = a.plus(a,b);
	cout<<"plusX="<<temp.getPlusX()<<endl;
	cout<<"plusY="<<temp.getPlusY()<<endl;
	cout<<"Answer= "<<temp.getPlusX()<<endl;
	cout<<"        -"<<endl;
	cout<<"        "<<temp.getPlusY()<<endl;
	
	return 0;
}
