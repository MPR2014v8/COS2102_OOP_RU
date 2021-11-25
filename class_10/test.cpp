#include <iostream>
using namespace std;

template <class t>

void findMax(t a, t b, t c){
	
	t MAX;
	
	if(a>=b && a>=c){
		MAX=a;
	}else
	if(b>=a && b>=c){
		MAX=b;
	}else
	if(c>=a && c>=b){
		MAX=b;
	}
	
	cout<<"MAX="<<MAX<<endl;
}

int main(){
	
	cout<<"//int"<<endl;
	int a[3]={1,55,6};
	findMax(a[0],a[1],a[2]);
	
	cout<<endl;
	
	cout<<"//float"<<endl;
	float b[3]={1.03,505.0,600.33};
	findMax(b[0],b[1],b[2]);
	
	cout<<endl;
	
	cout<<"//double"<<endl;
	double c[3]={78.3,5.02,0.6};
	findMax(c[0],c[1],c[2]);
	
	return 0;
}
