#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

class A{

	int x;
	int y;
	string name;

	public : 

		A(){
			x = 0;
			y = 0;
			name ="";
		}

		A(int i, int j, string k){
			x = i;
			y = j;
			name = k;
		}

		void setA(int i, int j, string k){
			x = i;
			y = j;
			name = k;
		}

		int getX(){
			return x;
		}

		int getY(){
			return y;
		}

		string getName(){
			return name;
		}

		bool operator == (A t){
			return (( (x + y) == (t.x +  t.y)) ? true : false);
		}

		bool operator < (A t){
			return (( (x + y) < (t.x +  t.y)) ? true : false);
		}

		bool operator <= (A t){
			return (( (x + y) <= (t.x +  t.y)) ? true : false);
		}

		bool operator > (A t){
			return (( (x + y) > (t.x +  t.y)) ? true : false);
		}

		bool operator >= (A t){
			return (( (x + y) >= (t.x +  t.y)) ? true : false);
		}

		friend ostream& operator << (ostream& os, A& r);

};
ostream& operator << (ostream& os, A& r){

	os<<"Name : "<< r.name <<endl;
	os<<"X : "<< r.x <<endl;
	os<<"Y : "<< r.y <<endl;
	os<<"X * Y : "<< (r.x * r.y) <<endl;
	cout<<endl;

	return os;
}

template <class T>

T findMAX(T a, T b, T c){

	T x, y, z;
	x=a; y=b; z=c;

  // cout<<"T = "<< typeid(x).name()<<endl;

	if(typeid(x).name() == typeid(int).name() ||
	   typeid(y).name() == typeid(int).name() ||
	   typeid(z).name() == typeid(int).name() ) throw 0;

	if(typeid(x).name() == typeid(double).name() || 
	   typeid(y).name() == typeid(double).name() || 
	   typeid(z).name() == typeid(double).name() ) throw 3.1;


	T MAX;

	if(a > b && a > c) MAX=a;
	if(b > a && b > c) MAX=b;
	if(c > a && c > b) MAX=c;

	return MAX;

}

int main(){

	try{

		A x(10, 20, "x"), y(48, 56, "y"), z(7, 9, "z");
/*
		cout<<"//show\n";
		cout<<x;
		cout<<y;
		cout<<z;
*/
		//cout<<"-------------------------"<<endl;

		findMAX(0.5,0.5,0.5);

	}

	catch(int){
		cout<<"Exception : int\n";
	}

	catch(double){
		cout<<"Exception : double\n";
	}

	catch(...){
		cout<<"Other Exception\n";
	}

	return 0;
}