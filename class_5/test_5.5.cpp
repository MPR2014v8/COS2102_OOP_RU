#include <iostream>
#include <string>
#include <cmath>

//const int sizeCircle=100;

using namespace std;

class Circle;
class Point {

	private :
		double x;
		double y;
		string name;
	
	public :
		
		//constuctor
		Point(){
			//cout<<"Hello Point"<<endl;
			x=0;
			y=0;
			name="noname";
		}	
		
		Point(double x, double y, string name){
			//cout<<"Hello Point"<<endl;
			this->x=x;
			this->y=y;
			this->name=name;

		}
		
		Point(string name){
			//cout<<"Hello Point"<<endl;
			x=0;
			y=0;
			this->name=name;
		
		}
		
		Point(double x){
			//cout<<"Hello Point"<<endl;
			this->x=x;
			y=0;
			this->name="noname";
		
		}
		
		Point(double x, double y){
			//cout<<"Hello Point"<<endl;
			this->x=x;
			this->y=y;
			this->name="noname";

		}
		
		~Point(){
			//cout<<"/Point/ Bye Bye "<<name<<"."<<endl;
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
		friend bool check(Point, Circle);
		 
};

double Point::dot(Point& y){
	
	return this->x*y.getX()+this->y*y.getY();
	
}

Point Point::midpoint(Point& x, Point& y){
	
	double tempX, tempY;
	
	tempX=x.getX()+y.getX();
	tempX=tempX/2;
	
	tempY=x.getY()+y.getY();
	tempY=tempY/2;
	
	Point temp;
	temp.setX(tempX);
	temp.setY(tempY);
	
	return temp;
}

class Circle{
	
	private:
		
		double radius;
		Point center;
		
	public:
		
		Circle(double r,Point& c){
			//cout<<"Hello Circle"<<endl;
			radius=r;
			center=c;
			center.setName("center");
		}
		
		Circle();
		Circle(double r);
		
		~Circle(){
			//cout<<"/Circle/ Bye Bye."<<endl;
		}
		
		void set(double r, Point& c){
			radius=r;
			center=c;
		}
	
		void setRadius(double r){
			radius=r;
			
			int n;
			n=radius/2;
			center.setX(n);
			center.setY(n);
		}
		
		void setCenterP(Point& c){
			center=c;
		}
		
		void setCenter(double x, double y){
			center.setX(x);
			center.setY(y);
		}
		
		double getRadius(){
			return radius;
		}
		
		Point getCenter(){
			return center;
		}
		
	//	friend bool check(Point, Circle);
		void show();
		
};
Circle::Circle(){
	//cout<<"Hello Circle"<<endl;
	radius=0;
	center.setX(0);
	center.setY(0);
	center.setName("center");
}

Circle::Circle(double r){
	radius=r;
	int n;
	n=radius/2;
	
	center.setX(n);
	center.setY(n);
	center.setName("center");
}

void Circle::show(){
	
	cout<<"//Circle"<<endl;
	cout<<"Radius="<<radius<<endl;
	cout<<"center="<<center.getX()<<","<<center.getY()<<endl;
	
}

bool check(Point p, Circle c){
//c no friend
Point y=c.getCenter();

double distance;

	distance=((p.x-y.getX())*(p.x-c.getCenter().x))+((p.y-y.getY())*(p.y-y.getY()));
	distance=sqrt(distance);
	
	cout<<"distance="<<distance<<endl;
	
	if(distance <= c.getRadius()){
			
		cout<<"Ture"<<endl;
		return true;
		
	}else{
		cout<<"False"<<endl;
		return false;
	}
	}

int main(){
	
	Circle abox(3);
	abox.setCenter(4,5);
	Point a(10,5), b(5,5), c(4,5), d(1,20), e(2,3);
	
	cout<<"Radius="<<abox.getRadius()<<endl;
	cout<<endl;
	
	cout<<"a("<<a.getX()<<","<<a.getY()<<")=>";
	check(a,abox);
	cout<<endl;
	
	cout<<"b("<<b.getX()<<","<<b.getY()<<")=>";
	check(b,abox);
	cout<<endl;
	
	cout<<"c("<<c.getX()<<","<<c.getY()<<")=>";
	check(c,abox);
	cout<<endl;
	
	cout<<"d("<<d.getX()<<","<<d.getY()<<")=>";
	check(d,abox);
	cout<<endl;
	
	cout<<"e("<<e.getX()<<","<<e.getY()<<")=>";
	check(e,abox);
	cout<<endl;
	
	return 0;
}
