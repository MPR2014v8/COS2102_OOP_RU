#include <iostream>
using namespace std;

class Rectangle{
	
	private :

		double Width;
		double Length;
		double area;
		
	public :
	//constructor 	
		Rectangle(){

			Width = 0.00;
			Length = 0.00;
			area = 0.00;
		}
		
		Rectangle(double w){
			Width = w;
		}	
		
		Rectangle(double w, double l){
			Width = w;
			Length = l;
		}
		
		~Rectangle(){	
			cout << "/Rectangle/ Bye Bye."<<endl;
		}
		//set

		void set(double w, double l){
			Width = w;
			Length = l;
		}
		void setWidth(double w){
			Width = w;
		}
		void setLength(double l){
			Length = l;
		}
		
		//get
		double getWidth(){
			return Width;
		}
		
		double getLength(){
			return Length;
		}
		
		double getArea(){
			return area;
		}
		//operator overloading
		double operator++(){
			++Length;
		}

		double operator++(int){
			return double(++Width);
		}

		friend double operator--(Rectangle &x);
		friend double operator--(Rectangle &x,int);
		
		void show();
		void findArea();
};

double operator--(Rectangle &x){
	
			if(x.Length <= 0){
				cout<<"The 'value' is out of bound"<<endl;
				exit(1);
			}
			x.Length--;
			return x.Length;
}
double operator--(Rectangle &x,int){
			if(x.Width <= 0){
				cout<<"The 'value' is out of bound"<<endl;
				exit(1);
			}
			x.Width--;
			return x.Width;
}

//show
void Rectangle::show(){

	cout<<"Width="<< Width <<endl;
	cout<<"Length="<< Length <<endl;
    cout<<"Area="<< area <<endl;
}

void Rectangle::findArea(){
	area = Width * Length;
}

int main(){
	
	Rectangle *a = new Rectangle(10.00,20.00);
	a->findArea();
	a->show();
	++*a;
	cout<<"Length="<< a-> getLength() <<endl;
	(*a)++;
	cout<<"Width="<< a-> getWidth() <<endl;
	--*a;
	cout<<"Length="<< a- >getLength() <<endl;
	(*a)--;
	cout<<"Width="<< a-> getWidth() <<endl;

	(*a)--; (*a)--; (*a)--; (*a)--; (*a)--; (*a)--; (*a)--;
	(*a)--; (*a)--; (*a)--; (*a)--; (*a)--; (*a)--; (*a)--;

	cout<<"Hello Wolrd\n";
	
	return 0;
}
