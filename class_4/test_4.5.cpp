#include <iostream>
using namespace std;

class Point {

	private :
		double x, midpointX;
		double y, minpointY;
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
		
		void setMidpointX(double x){
			this->midpointX=x;
		}
		
		void setY(double y) {
			this->y = y;
		}
		
		void setMidpointY(double y){
			this->minpointY=y;
		}
		void setName(string name) {
			this->name=name;;
		}
		
		//getter
		double getX() {
			return x;
		}
		double getMidpointX(){
			return midpointX;
		}

		double getY() {
			return y;
		}
		double getMidpointY(){
			return minpointY;
		}
		
		string getName(){
			return this->name;
		}
		double dot(Point& y);
		Point midpoint(Point& x, Point& y); 
		
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
	temp.setMidpointX(tempX);
	temp.setMidpointY(tempY);
	
	return temp;
}
//static variable
int Point::count; 

//stackPoint
class StackPoint{
	
	private :
		Point *data;
		int size;
	    int count;
		
	public :
		StackPoint(){
			data=0;
			size=0;
		}
		StackPoint(int size){
			this->size=size;
			data = new Point[size];
		}
		~StackPoint(){
			delete []data;
		}
		
		void push(Point& data);
		Point pop();
		void isFull();
		void isEmpty();
		void show();
		int getCount();
	
};

void StackPoint::push(Point& data){
	
	cout<<"Push"<<endl;
	cout<<"count="<<count<<endl;
	if(count>=0 && count<=size){
		this->data[count]=data;
		count++;
	}else if(count>size){
		isFull();
    }
}

Point StackPoint::pop(){
	
	Point temp; int num=count-1;
	if(count!=0){
		count--;
		temp=data[num];
	    data[num]=NULL;
		
	}else if(count==0){
		isEmpty();
	}

	return temp;
}

void StackPoint::isFull(){
	cout<<"Stack Full!!! //s_p"<<endl;
}

void StackPoint::isEmpty(){
	cout<<"Stack Empty!!!"<<endl;
}

int StackPoint::getCount(){
	return count;
}
void StackPoint::show(){
	cout<<"//show stack Point"<<endl;
	for(int i=0; i<count; i++){
		cout<<"//Obj["<<i<<"]"<<endl;
		cout<<"x="<<data[i].getX()<<endl;
		cout<<"y="<<data[i].getY()<<endl;
		cout<<"name="<<data[i].getName()<<endl;
		cout<<"--------------------------"<<endl;
	}
}

int main(){

	StackPoint a(2);
	Point aP(2,8,"A"), bP(1,2,"B");
	
	a.push(aP);
	a.push(bP);
	
	a.show();	
	cout<<"pop"<<endl;
	a.pop();
	a.show();

return 0;
	
}
