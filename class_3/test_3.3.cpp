#include <iostream>
using namespace std;

class Queue{
	
private :
		int *data;
		int size;
		int count;
		int n_remove=0;
		
	public :
		Queue(){
			data=0;
			size=0;
		}
		Queue(int size){
			this->size=size;
			data = new int[size];
		}
		~Queue(){
			delete []data;
		}
		
		void insert(int);
		int remove();
		void isFull();
		void isEmpty();
		void show();
		int getCount();
	
};

void Queue::insert(int data){
	
	if(count>=0 && count<=size){
		this->data[count]=data;
		count++;
	}else if(count>size){
		isFull();
    }
}

int Queue::remove(){
	
	int temp=0,num=count-1;
	if(count!=0){
		count--;
		num=(num+n_remove)-num;
		temp=data[num];
	    data[num]= NULL;
		num++; n_remove++;
	}else if(count==0){
		isEmpty();
	}
	

	return temp;
}

void Queue::isFull(){
	cout<<"Queue Full!!!"<<endl;
}

void Queue::isEmpty(){
	cout<<"Queue Empty!!!"<<endl;
}

void Queue::show(){
	
	for(int i=0; i<=size; i++){
		cout<<"Queue["<<i<<"]="<<data[i]<<endl;	
	}
	cout<<endl;
}

int Queue::getCount(){
	return count;
}

main(){
	Queue a(3);
	
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	
	a.show();
	cout<<"------------"<<endl;
	
	cout<<"remove="<<a.remove()<<endl;
	a.show();
	cout<<"remove="<<a.remove()<<endl;
	a.show();
	cout<<"remove="<<a.remove()<<endl;
	a.show();
	cout<<"remove="<<a.remove()<<endl;
	a.show();
	
}
