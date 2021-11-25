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
		int get(int i){
			return point[i];
		}
		int getSize(){
			return size;
		}
		Vector minus(Vector& x, Vector& y);
		Vector plus(Vector& x, Vector& y);
		void setValue(int i,int item);
		void show();
};

void Vector::setValue(int i,int item){
	
	point[i]=item;
}

void Vector::show(){
	
	for(int i=0; i<size; i++){
		cout<<"point["<<i<<"]="<<point[i]<<endl;
	}	
}

Vector Vector::minus(Vector& x, Vector& y){
	
	Vector temp(x.getSize()); int num;
	
	for(int i=0; i<x.getSize(); i++){
		
		num=x.get(i)-y.get(i);
		temp.setValue(i,num);
		//cout<<"temp["<<i<<"]="<<temp.get(i)<<endl;
	}
	return temp;
}
Vector Vector::plus(Vector& x, Vector& y){
	
	Vector temp(x.getSize()); int num;
	
	for(int i=0; i<x.getSize(); i++){
		
		num=x.get(i)+y.get(i);
		temp.setValue(i,num);
		//cout<<"temp["<<i<<"]="<<temp.get(i)<<endl;
	}
	return temp;
}

int main(){
	
	Vector a(3),b(3),temp;
	a.setValue(0,1);
	a.setValue(1,2);
	a.setValue(2,3);
	
	b.setValue(0,4);
	b.setValue(1,5);
	b.setValue(2,6);
	
	cout<<"//Minus"<<endl;
	temp=a.minus(a,b);
	temp.show();
	cout<<"----------------"<<endl;
	cout<<"//Plus"<<endl;
	temp=a.plus(a,b);
	temp.show();	

	return 0;
}
