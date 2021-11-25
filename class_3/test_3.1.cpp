#include <iostream>
using namespace std;

class Vector{
	
	private :
		int size;
		int *point;
		
	public :
		Vector(){
			size=0;
			point=0;
		}
		Vector(int y){
			set(y);
		}
		
		~Vector(){
			delete []point;
		}
		
		void set(int y){
			size=y;
			point = new int [size];
		}
		
		void setValue();
		void show();
};

void Vector::setValue(){
	
	for(int i=0; i<size; i++){
		cout<<"point["<<i<<"]=";
		cin>>point[i];
	}	
}

void Vector::show(){
	
	for(int i=0; i<size; i++){
		cout<<"point["<<i<<"]="<<point[i]<<endl;
	}	
}

main(){
	Vector a(2);
	cout<<"//setValue"<<endl;
	a.setValue();
	cout<<endl;
	
	cout<<"//show"<<endl;
	a.show();
	cout<<endl;
	
	cout<<"//set"<<endl;
	int i;
	cout<<"size="; cin>>i;	
	a.set(i);
	cout<<endl;
	
	cout<<"//setValue"<<endl;
	a.setValue();
	cout<<endl;
	
	cout<<"//show"<<endl;
	a.show();
	
}
