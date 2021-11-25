#include <iostream>
using namespace std;

class Rational{
	
	private : 
	
	//Attribute
		double numerator;
		double denominator;
		double ans, plus_ans, plusX, plusY, minus_ans, minusX, minusY;
		
	public :
		
	//constructor
		Rational(){
			numerator=0.0;
			denominator=0.0;
			ans=0.0;
		}
		Rational(double numerator, double denominator);
		Rational(double numerator);
		
	//destructor
		~Rational(){
			//cout<<"Bye Bye. //Rational"<<endl;
		}
		
	//set
	void set(double numerator, double denominator){
			this->numerator=numerator;
			this->denominator=denominator;
	}
	void setX(double numerator){
			this->numerator=numerator;
	}
	void setY(double denominator){
			this->denominator=denominator;
	}
	void setAns(double i){
		ans=i;
	}
	void setPlusAns(double i){
		plus_ans=i;
	}
	void setPlusX(double i){
		plusX=i;
	}
	void setPlusY(double i){
		plusY=i;
	}
	void setMinusAns(double i){
		minus_ans=i;
	}
	void setMinusX(double i){
		minusX=i;
	}
	void setMinusY(double i){
		minusY=i;
	}
	//get
	double getX(){
			return numerator;
	}
	double getY(){
			return denominator;
	}
	double getAns(){
		return ans;
	}
	double getPlusAns(){
		return plus_ans;
	}
	double getPlusX(){
		return plusX;
	}
	double getPlusY(){
		return plusY;
	}
	double getMinusAns(){
		return minus_ans;
	}
	double getMinusX(){
		return minusX;
	}
	double getMinusY(){
		return minusY;
	}
	
	Rational plus(Rational& x, Rational& y);
	Rational minus(Rational& x, Rational& y);
	void show();
	void findDivide();
	
};

Rational::Rational(double numerator, double denominator){
	this->numerator=numerator;
	this->denominator=denominator;
	findDivide();
}

Rational::Rational(double numerator){
	this->numerator=numerator;
	denominator=0.0;
	findDivide();
}

void Rational::show(){
	cout<<"X/Y"<<endl;
	cout<<"X="<<numerator<<endl;
	cout<<"Y="<<denominator<<endl;
	cout<<"Answer="<<ans<<endl;
}

void Rational::findDivide(){
	double temp=numerator/denominator;
	setAns(temp);
}

Rational Rational::plus(Rational& x, Rational& y){
	
	Rational temp;
	double tempX, tempY;
	
	if(x.getY()== y.getY()){
		
		tempX=x.getX()+y.getX();
		temp.setPlusX(tempX);
		temp.setPlusY(y.getY());
		
	}
	
	if(x.getY()!=y.getY()){
		
		//X
		tempX=x.getX()*y.getY();
		tempY=y.getX()*x.getY();
		tempX=tempX+tempY;
		
		temp.setPlusX(tempX);
		
		//Y
		tempY=x.getY()*y.getY();
		temp.setPlusY(tempY);
		
	}
	return temp;
}
Rational Rational::minus(Rational& x, Rational& y){
			
	Rational temp;
	double tempX, tempY;
	
	if(x.getY()== y.getY()){
		
		tempX=x.getX()-y.getX();
		temp.setMinusX(tempX);
		temp.setMinusY(y.getY());
		
	}
	
	if(x.getY()!=y.getY()){
		
		//X
		tempX=x.getX()*y.getY();
		tempY=y.getX()*x.getY();
		tempX=tempX-tempY;
		
		temp.setMinusX(tempX);
		
		//Y
		tempY=x.getY()*y.getY();
		temp.setMinusY(tempY);
		
	}
	return temp;
}

int main(){
	
	Rational a(1,2), b(2,3), temp;
	
	temp=a.plus(a,b);
	
	cout<<"plusX="<<temp.getPlusX()<<endl;
	cout<<"plusY="<<temp.getPlusY()<<endl;
	
	
	temp=a.minus(a,b);
	
	cout<<"minusX="<<temp.getMinusX()<<endl;
	cout<<"minusY="<<temp.getMinusY()<<endl;
	
	return 0;
	
}
