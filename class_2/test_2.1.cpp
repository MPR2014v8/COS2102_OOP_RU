#include<iostream>
#include<string.h>
using namespace std;

class Point {

	private :
		double x;
		double y;
		char name[100];
	    static int count;

	public :
		
		//constuctor
		Point(){
			x=0;
			y=0;
			strcpy(name,"noname");
			count++;
			
			cout << "Object="<<count<<endl;;
			cout << "Hello. " << this->name <<endl;
			cout<<endl;
		}	
		
		Point(double x, double y, char *name){
			this->x=x;
			this->y=y;
			strcpy(this->name,name);
			count++;
			
			cout << "Object="<<count<<endl;;
			cout << "Hello. " << this->name <<endl;
			cout<<endl;	
		}
		
		Point(char *name){
			x=0;
			y=0;
			strcpy(this->name,name);
			count++;
			cout << "Object="<<count<<endl;;
			cout << "Hello. " << this->name <<endl;
			cout<<endl;
		}
		
		Point(double x){
			this->x=x;
			y=0;
			strcpy(name,"noname");
			count++;
			cout << "Object="<<count<<endl;;
			cout << "Hello. " << this->name <<endl;
			cout<<endl;
		}
		
		Point(double x, double y){
			this->x=x;
			this->y=y;
			strcpy(name,"noname");
			count++;
			cout << "Object="<<count<<endl;;
			cout << "Hello. " << this->name <<endl;
			cout<<endl;
		}
		
		~Point(){
			cout << "Bye Bye. " << this->name << endl;
			count--;
			cout << "Object="<<count<<endl;
			cout <<"---------------------------------------------"<< endl;
			cout << endl;
		}
		
        //setter 
        void setter(double x, double y,char* name) {
			this->x = x;
			this->y = y;
			strcpy(this->name,name);
		}
		
		void setX(double x) {
			this->x = x;
		}
		
		void setY(double y) {
			this->y = y;
		}
		
		void setName(char* name) {
			strcpy(this->name,name);
		}
		
		//getter
		double getX() {
			return x;
		}

		double getY() {
			return y;
		}
		
		char* getName(){
			return this->name;
		}
		
		void show(void);
};
//show
void Point::show() {

	cout << "X :" << x << endl;
	cout << "Y :" << y << endl;
	cout << "Name :" << this->name << endl;
	cout <<"---------------------------------------------"<< endl;
	cout << endl;
}
//static variable
int Point::count;

int main() {

	Point a(102.22,11.2,"Wachira");
	
	a.setter(10.2,12.3,"Wachira");
	a.show();
	
	Point b(10.330,120.24,"Minomoto");
	b.setX(10.330);
	b.setY(120.24);
	b.setName("Minomoto");
	b.show();
	
	Point c(1025.5,124.6,"Sakuraki");
	c.setter(1025.5,124.6,"Sakuraki");
	cout << "X :"<< c.getX() << endl;
	cout << "Y :"<< c.getY() << endl;
	cout << "Name :"<< c.getName() << endl;
	cout <<"---------------------------------------------"<< endl;
	cout << endl;
	
	Point d(111.11,2.2222,"Mimamushi");
	d.setX(111.11);
	d.setY(2.2222);
	d.setName("Mimamushi");
	cout << "X :"<< d.getX() << endl;
	cout << "Y :"<< d.getY() << endl;
	cout << "Name :"<< d.getName() << endl;
	cout <<"---------------------------------------------"<< endl;
	cout << endl;
	
	Point e;
	e.show();
	
	Point g(10.33 );
	g.show();
	
	Point f(15.55,78.22);
	f.show();
	
	Point h("Dorotee");
	h.show();
	
	Point i(1555.02,1456.55,"Yuri");
	i.show();
	
	return 0;
}
