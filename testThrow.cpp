#include <iostream>
using namespace std;

class A{
	int i;

public:

	A(){
		i=0;
	}

	void f(){
		throw A();
	}

};

int main(){
	
	try{
		A a;

		a.f();
	}
	catch(A){
		cout<<"2.5"<<endl;
	}
	catch(double){
		cout<<"double"<<endl;
	}

	return 0;
}