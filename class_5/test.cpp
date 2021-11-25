#include <iostream>
using namespace std;

int main(){
	int *a,*a1,*a2;
	int b=4,c=5;
	
	a=&b;
	a1=&c;
	a2=a;
	
	cout<<"a="<<a<<endl;
	cout<<"a1="<<a1<<endl;
	cout<<"a2="<<*a2<<endl;
	return 0;
}
