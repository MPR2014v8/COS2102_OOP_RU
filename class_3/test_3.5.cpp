#include <iostream>
using namespace std;

class Point {

	private :
		double x;
		double y;
		string name;
	    static int count;

	public :
		
		//constuctor
		Point(){
			x=0;
			y=0;
			name="noname";
			count++;
		}	
		
		Point(double x, double y, string name){
			this->x=x;
			this->y=y;
			this->name=name;
			count++;	
		}
		
		Point(string name){
			x=0;
			y=0;
			this->name=name;
			count++;
		}
		
		Point(double x){
			this->x=x;
			y=0;
			this->name="noname";
			count++;
		}
		
		Point(double x, double y){
			this->x=x;
			this->y=y;
			this->name="noname";
			count++;
		}
		
		~Point(){
			count--;
		}
		
        //setter 
        void setter(double x, double y,string name) {
			this->x = x;
			this->y = y;
			this->name=name;;
		}
		
		void setX(double x) {
			this->x = x;
		}
		
		void setY(double y) {
			this->y = y;
		}
		
		void setName(string name) {
			this->name=name;;
		}
		
		//getter
		double getX() {
			return x;
		}

		double getY() {
			return y;
		}
		
		string getName(){
			return this->name;
		}
};

//static variable
int Point::count;

class MyPoint{
	
	private :
		Point *a;
		int size;
		
	public :
		MyPoint(){
			size=0;
			a=0;
		}
		
		void setSize(int s){
			size=s;
		}
		
		int getSize(){
			return size;
		}
		
		MyPoint(int s);
		~MyPoint();
		void setPoint();
		Point getPoint(int i);
		void show();
		void reset();
};

MyPoint::MyPoint(int s){
	
	setSize(s);	
	a = new Point [size];
}

MyPoint::~MyPoint(){
	delete[] a;
}

void MyPoint::setPoint(){
	
	double x; double y; string name;
	
	for(int i=0; i<size; i++){
		
		cout<<"x to Point["<<i<<"]=";cin>>x;
		cout<<"y to Point["<<i<<"]=";cin>>y;
		cout<<"name to Point["<<i<<"]=";cin>>name;
		a[i].setter(x,y,name);
	}
}

Point MyPoint::getPoint(int i){
	return a[i];
}

void MyPoint::show(){
	
	for(int i=0; i<size; i++){
		cout << "X :" << a[i].getX() << endl;
		cout << "Y :" << a[i].getY() << endl;
		cout << "Name :" << a[i].getName() << endl;
		cout <<"---------------------------------------------"<< endl;
		cout << endl;	
	}
}

void MyPoint::reset(){
	
	//delete
	delete[] a;
	
	//set
	int s;
	
	cout<<"Size="; cin>>s;
	setSize(s);
	a = new Point[size];
	setPoint();
	
}

main(){
	
	MyPoint a(2);
	a.setPoint();
	a.show();
	cout<<"--------------"<<endl;
	a.reset();
	cout<<"--------------"<<endl;
	a.show();
}
