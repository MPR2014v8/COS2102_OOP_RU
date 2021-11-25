#include <iostream>
using namespace std;


int main(){
	
	int sum, i;
	i=0;
	
	while(i<5){
		sum= sum + i;
		cout<<i<<", sum="<<sum<<endl;
		i=i+1;
	}
	
	return 0;
}
