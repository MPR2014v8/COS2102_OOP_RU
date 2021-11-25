#include <iostream>
#include <cstring>
using namespace std;

class A{

	char str[100];

	public :

		A(){
			strcpy(str,"None");
		}

		A(char* i){
			strcpy(str,i);
		}

		bool operator <(A);
		bool operator ==(A);
};

bool A::operator <(A x){
	return (strlen(str) < strlen(x.str)) ? true : false;
}

bool A::operator ==(A x){
	return (strcmp(str, x.str)==0) ? true : false;
}

int main(){

	A x("COS2102"), y("COS2102");

	if(x==y){
		cout<<"equal\n";
	}else{
		cout<<"not equal\n";
	}

	if(x<y){
		cout<<"true\n";
	}else{
		cout<<"false\n";
	}
	
	system("pause");
	return 0;
}