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
		
		Rectangle(double l){
			Width = 1;
			Length = l;
			area = Width * Length;
		}	
		
		Rectangle(double w, double l){
			Width = w;
			Length = l;
			area = Width * Length;
		}

		Rectangle(Rectangle &r){
			Width = r.getWidth();
			Length = r.getLength();
			area = Width * Length;
		}
		
		~Rectangle(){	
			//cout << "/Rectangle/ Bye Bye."<<endl;
		}
		//set

		void set(double w, double l){

			Width = w;
			Length = l;
			area = Width * Length;
		}
		void setWidth(double w){
			Width = w;
			area = Width * Length;
		}
		void setLength(double l){
			Length = l;
			area = Width * Length;
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
		double operator[] (int i)
		{
			if(i == 1) return Width;
			if(i == 2) return Length;
			if(i == 3) return Area;
			
		}

		Rectangle& operator() (double l)
		{
			Width = 1;
			Length = l;
			area = Width * Length;
			return *this;
		}

		Rectangle& operator() (double w, double l)
		{
			Width = w;
			Length = l;
			area = Width * Length;
			return *this;
		}

		Rectangle& operator++(){
			++Length;
			area = Width * Length;
			return *this;
		}

		Rectangle& operator++(int){
			++Width;
			area = Width * Length;
			return *this;
		}

		bool operator<(Rectangle);
		bool operator<=(Rectangle);
		bool operator>(Rectangle);
		bool operator>=(Rectangle);
		bool operator==(Rectangle);
		bool operator!=(Rectangle);

		friend Rectangle& operator--(Rectangle &x);
		friend Rectangle& operator--(Rectangle &x, int);
		
		void show();
		void findArea();
};
bool Rectangle::operator < (Rectangle x){
	return (area < x.area) ? true : false;
}

bool Rectangle::operator <= (Rectangle x){
	return (area <= x.area) ? true : false;
}

bool Rectangle::operator > (Rectangle x){
	return (area > x.area) ? true : false;
}

bool Rectangle::operator >= (Rectangle x){
	return (area >= x.area) ? true : false;
}

bool Rectangle::operator == (Rectangle x){
	return (area==x.area) ? true:false;
}

bool Rectangle::operator !=(Rectangle x){
	return (area != x.area) ? true : false;
}

Rectangle& operator --(Rectangle &x)
{
			if(x.Length <= 0){

				cout<<"The 'value' is out of bound"<<endl;
				exit(1);
			}

			x.Length--;
			return x;
}
Rectangle& operator--(Rectangle &x, int)
{
			if(x.Width <= 0){

				cout<<"The 'value' is out of bound"<<endl;
				exit(1);
			}

			x.Width--;
			return x;
}

//show
void Rectangle::show(){

	cout<<"Width="<< Width <<endl;
	cout<<"Length="<< Length <<endl;
    cout<<"Area="<< area <<endl;
}

class arrRectangle
{
	private :

		Rectangle *a;
		int size;

	public :

		arrRectangle()
		{
			size = 5;
			a = new Rectangle[size];
		}

		arrRectangle(int s)
		{
			size = s;
			a = new Rectangle[size];
		}

		~arrRectangle()
		{
			for (int i = 0; i < size; ++i)
			{
				delete [] a;
			}
		}

		void set(int p, double w, double l)
		{
			a[p].set(w, l);
		}

		void setWidth(int p, double w)
		{
			a[p].setWidth(w);
		}

		void setLength(int p, double l)
		{
			a[p].setLength(l);
		}

		double getWidth(int p)
		{
			return a[p].getWidth();
		}

		double getLength(int p)
		{
			return a[p].getLength();
		}

		double getArea(int p)
		{
			return a[p].getArea();
		}

		Rectangle& operator[] (int i)
		{
			return a[i];
		}

		Rectangle& operator() (int i)
		{
			return a[i];
		}

		void show()
		{
			for (int i = 0; i < size; ++i)
			{
				cout<<"a["<<i<<"] : "<<endl;
				cout<<"Width = "<<a[i].getWidth()<<endl;
				cout<<"Length = "<<a[i].getLength()<<endl;
				cout<<"Area = "<<a[i].getArea()<<endl;
				cout<<endl;
			}
		}
};

int main(){
	
	Rectangle a(10.00, 20.00), b(20.00, 30.00), c(100.00, 2.00);

	cout<<"//a\n";
	a.show();
	cout<<endl;

	cout<<"//b\n";
	b.show();
	cout<<endl;

	cout<<"//c\n";
	c.show();
	cout<<endl;

	cout<<"--------------------------------\n";
	cout<<"a < b ?\n";

	if(a<b){

		cout<<"Less than.\n";
	}else{

		cout<<"Greater than.\n";
	}

	cout<<"--------------------------------\n";
	cout<<"--------------------------------\n";
	cout<<"b <= a ?\n";

	if(b <= a){

		cout<<"Less than or equql.\n";
	}else{

		cout<<"Greater than.\n";
	}

    cout<<"--------------------------------\n";
	cout<<"--------------------------------\n";
	cout<<"b > c ?\n";

	if(b > c){

		cout<<"Greater than.\n";
	}else{

		cout<<"Less than.\n";
	}

	cout<<"--------------------------------\n";
	cout<<"--------------------------------\n";
	cout<<"a >= c ?\n";

	if(a >= c){

		cout<<"Greater than or equal.\n";
	}else{

		cout<<"Less than.\n";
	}

	cout<<"--------------------------------\n";
	cout<<"--------------------------------\n";
	cout<<"c == a ?\n";

	if(c == a){

		cout<<"Equal.\n";
	}else{

		cout<<"Not equal.\n";
	}
	cout<<"--------------------------------\n";
	cout<<"--------------------------------\n";
	cout<<"a != b ?\n";
	if(a != b){

		cout<<"Not equal.\n";
	}else{

		cout<<"equal.\n";
	}
	cout<<"--------------------------------\n";

	cout<<endl;
	cout<<"// Arr"<<endl;
	cout<<endl;

	arrRectangle *d = new arrRectangle(3);

	d->set(0, 1, 1);
	d->set(1, 2, 2);
	d->set(2, 3, 3);

	d->show();

	cout<<endl;
	cout<<"// ++"<<endl;
	cout<<endl;

	Rectangle pp, _pp;

	cout<<"//show pp"<<endl;
	pp.show();
	cout<<endl;

	cout<<"//show pp++"<<endl;
	_pp = pp++;
	pp.show();

	cout<<endl;
	cout<<"//show _pp"<<endl;
	_pp.show();

	cout<<endl;
	cout<<"//show ++pp"<<endl;
	_pp = ++pp;
	pp.show();

	cout<<endl;
	cout<<"//show _pp"<<endl;
	_pp.show();

	cout<<endl;
	cout<<"//show --"<<endl;
	cout<<endl;

	Rectangle dd(5,5), _dd;

	cout<<"//show dd"<<endl;
	dd.show();
	cout<<endl;

	cout<<"//show dd--"<<endl;
	_dd = dd--;
	dd.show();

	cout<<endl;
	cout<<"//show _dd"<<endl;
	_dd.show();

	cout<<endl;
	cout<<"//show --dd"<<endl;
	_dd = --dd;
	dd.show();

	cout<<endl;
	cout<<"//show _dd"<<endl;
	_dd.show();

	cout<<endl;
	cout<<"//show ()"<<endl;
	cout<<endl;

	pp(4, 5);
	pp.show();

	Rectangle _tt;
	arrRectangle tt(5);

	for (int i = 0; i < 5; ++i)
	{
		tt(i).set(i+1, i+2);
	}
	cout<<endl;

	cout<<"//show tt"<<endl;
	tt.show();

	_tt = tt(4);

	cout<<endl;
	cout<<"//show _tt"<<endl;
	_tt.show();

	cout<<endl;

	Rectangle ss, _ss;
	_ss = ss[5];
	cout<<"//show _ss"<<endl;
	_ss.show();

	return 0;
}
