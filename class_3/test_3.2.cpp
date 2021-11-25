#include <iostream>
using namespace std;

class Stack{
	
	private :
		int *data;
		int size;
		int count;
		
	public :
		Stack(){
			data=0;
			size=0;
		}
		Stack(int size){
			this->size=size;
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
		int getCount();
	
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
	
	int temp=0,num=count-1;
	if(count!=0){
		count--;
		temp=data[num];
	    data[num]= NULL;
		
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

//int Stack::count;

int main(){
	
	Stack a(6);
	a.push(151);
	a.push(152);
	a.push(153);
	a.push(154);
	a.push(155);
	a.push(156);
	a.push(157);
	a.push(158);
	
	a.show();
	
	cout<<"------"<<endl;
	cout<<"count="<<a.getCount()<<endl;
	cout<<"------"<<endl;
	
	cout<<"POP="<<a.pop()<<endl;
	a.show();
	
	cout<<"------"<<endl;
	cout<<"count="<<a.getCount()<<endl;
	cout<<"------"<<endl;
	
	cout<<"POP="<<a.pop()<<endl;
	a.show();
	
	cout<<"------"<<endl;
	cout<<"count="<<a.getCount()<<endl;
	cout<<"------"<<endl;
	
	cout<<"POP="<<a.pop()<<endl;
	a.show();
	
	cout<<"------"<<endl;
	cout<<"count="<<a.getCount()<<endl;
	cout<<"------"<<endl;
	
	cout<<"POP="<<a.pop()<<endl;
	a.show();
	
	cout<<"------"<<endl;
	cout<<"count="<<a.getCount()<<endl;
	cout<<"------"<<endl;
	
	cout<<"POP="<<a.pop()<<endl;
	a.show();
	
	cout<<"------"<<endl;
	cout<<"count="<<a.getCount()<<endl;
	cout<<"------"<<endl;

	cout<<"POP="<<a.pop()<<endl;
	a.show();
	
	cout<<"------"<<endl;
	cout<<"count="<<a.getCount()<<endl;
	cout<<"------"<<endl;
	
	cout<<"POP="<<a.pop()<<endl;
	a.show();
	
	cout<<"------"<<endl;
	cout<<"count="<<a.getCount()<<endl;
	cout<<"------"<<endl;
	
	return 0;
}
