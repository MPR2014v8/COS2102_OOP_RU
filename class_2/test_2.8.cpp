#include <iostream>
using namespace std;

class Rational{
	
	private : 
	
	//Attribute
		double numerator;
		double denominator;
		double ans;
		
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
			cout<<"Bye Bye. //Rational"<<endl;
		}
		
	//set
	void set(double numerator, double denominator){
			this->numerator=numerator;
			this->denominator=denominator;
	}
	void setNumerator(double numerator){
			this->numerator=numerator;
	}
	void setDenominator(double denominator){
			this->denominator=denominator;
	}
	void setAns(double i){
		ans=i;
	}
	
	//get
	double getNumerator(){
			return numerator;
	}
	double getDenominator(){
			return denominator;
	}
	double getAns(){
		return ans;
	}
	
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

int main(){
	
	Rational a(1,2);
	a.show();
	
	
	return 0;
	
}
