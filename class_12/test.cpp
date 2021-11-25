#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	double x1,x2, y1,y2, d;
	
	
	x1=2, 
	y1=3;
	
	x2=2;
	y2=4;
	
	d=((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2));
	d=sqrt(d);
	
	double b;
	b=4;
	
	b=sqrt(b);
	
	cout<<"b="<<b<<endl;;
	cout<<"d="<<d<<endl;;
	
	
	return 0;
}
