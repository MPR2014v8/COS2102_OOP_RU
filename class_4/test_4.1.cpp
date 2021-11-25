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
        void set(double x, double y,string name) {
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
		double dot(Point& y);
		Point midpoint(Point& x, Point& y); 
		
};

double Point::dot(Point& y){
	
	return this->x*y.x+this->y*y.getY();
	
}

Point Point::midpoint(Point& x, Point& y){
	
	double tempX, tempY;
	
	tempX=x.getX()+y.getX();
	tempX=tempX/2;
	
	tempY=x.getY()+y.getY();
	tempY=tempY/2;
	
	setX(tempX);
	setY(tempY);
	
	return *this;
}

//static variable
int Point::count; 

int main(){
	
	Point x(2,1,"x"),y(3,2,"y"), midpoint, z;
	
	cout<<"dot="<<x.dot(y)<<endl;
	z.midpoint(x,y); 
	cout<<"z midpoint=("<<z.getX()<<","<<z.getY()<<")"<<endl;
	
	return 0;
}
