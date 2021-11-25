#include <typeinfo>
#include <iostream>
#include <string>
using namespace std;

class Box{};
class BAMM{};

int main(){
char r;
	int a; 
	double b;
	Box c;
	BAMM d;
	string e, f="5555";
/*
	cout<<"a type : "<< typeid(a).name()<<endl;
	cout<<"b type : "<<typeid(b).name()<<endl;
	cout<<"BOX type : "<<typeid(c).name()<<endl;
	cout<<"BAMM type : "<<typeid(d).name()<<endl;
	cout<<"e type : "<< typeid(e).name()<<endl;
	cout<<"f type : "<< typeid(f).name()<<endl;
*/
	if(typeid(e).name() == typeid(f).name()) cout<<typeid(r).name()<<endl;

	return 0;
}