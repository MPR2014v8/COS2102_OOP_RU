#include <iostream>
using namespace std;

class Stack{
	
	private :
		int *data;
		int size;
		static int count;
		
	public :
		Stack(){
			data=0;
			size=0;
		}
		Stack(int size){
			this->size=size-1;
			data = new int[size];
		}
		~Stack(){
			delete []data;
		}
		
		void push(int data);
		int pop();
		void isFull();
		void isEmpty();
		void show();
		static int getCount();
	
};

void Stack::push(int data){
	
	if(count>=0 && count<=size){
		this->data[count]=data;
		count++;
	}else if(count>size){
		isFull();
    }
}

int Stack::pop(){
	
	int temp=0;
	if(count!=0){
		count--;
		temp=data[count];
	    data[count]= NULL;
		
	}else if(count==0){
		isEmpty();
	}

	return temp;
}

void Stack::isFull(){
	cout<<"Stack Full!!!"<<endl;
}

void Stack::isEmpty(){
	cout<<"Stack Empty!!!"<<endl;
}

void Stack::show(){
	int num=size;
	
	for(int i=0; i<=size; i++){
		cout<<"Stack["<<num-i<<"]="<<data[num-i]<<endl;	
	}
	cout<<endl;
}

int Stack::getCount(){
	return count;
}

//stackPoint
class StackPoint{
	
	private :
		int *data;
		int size;
		static int count;
		
	public :
		Stack(){
			data=0;
			size=0;
		}
		Stack(int size){
			this->size=size-1;
			data = new int[size];
		}
		~Stack(){
			delete []data;
		}
		
		void push(int data);
		int pop();
		void isFull();
		void isEmpty();
		void show();
		static int getCount();
	
};

void Stack::push(int data){
	
	if(count>=0 && count<=size){
		this->data[count]=data;
		count++;
	}else if(count>size){
		isFull();
    }
}

int Stack::pop(){
	
	int temp=0;
	if(count!=0){
		count--;
		temp=data[count];
	    data[count]= NULL;
		
	}else if(count==0){
		isEmpty();
	}

	return temp;
}

void Stack::isFull(){
	cout<<"Stack Full!!!"<<endl;
}

void Stack::isEmpty(){
	cout<<"Stack Empty!!!"<<endl;
}

void Stack::show(){
	int num=size;
	
	for(int i=0; i<=size; i++){
		cout<<"Stack["<<num-i<<"]="<<data[num-i]<<endl;	
	}
	cout<<endl;
}

int Stack::getCount(){
	return count;
}

int Stack::count;
int StackPoint::count;

int main(){
	
	return 0;
}
