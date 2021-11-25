#include<iostream>
#include<string>
using namespace std;

const int MAX=3;

class A{
	int arr[MAX];

	public :
		A();
		int &operator[](int n){
			if(n<0 || n>=MAX){
				cout<<"Error\n";
				exit(1);
			}
			return arr[n];
		}
};
A::A(){
	for(int i=0; i<MAX; i++){
		arr[i]=0;
	}
}

int main(){

	A x,y;
	int i;
	for(i=0; i<3; i++){
		x[i]=i*2;
		cout<<"x["<<i<<"]="<<x[i]<<endl;
	}
	for(i=0; i<4; i++){
		y[i]=x[i]*3;
		cout<<"y["<<i<<"]="<<y[i]<<endl;
	}
	cout<<"XXXXXXXXXXX\n";
	return 0;
}