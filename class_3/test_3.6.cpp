#include <iostream>
using namespace std;

//Rectangle
class Rectangle{
	
	private :
		double Width;
		double Length;
		double total;
		static int count;
		
	public : //constructor 	
		Rectangle(){
			
			Width=0;
			Length=0;
			total=0;
			
			count++;
			//cout << "Object=" << count <<endl;
			//cout<<endl;
		}
		
		Rectangle(double Width){
			
			this->Width=Width;
			total=Width*4;
			Length=0;
			
			count++;
			//cout << "Object=" << count <<endl;
			//cout<<endl;
		}		
		
		Rectangle(double Width, double Length){
			
			this->Width=Width;
			this->Length=Length;
			total=(Width*2)+(Length*2);
			
			count++;
			//cout << "Object=" << count << endl;
			//cout<<endl;
		}
		
		~Rectangle(){
			
			//cout << "Bye!. Object=" << count <<endl;
			count--;
			//cout << "Object=" << count <<endl;
			//cout<<endl;
		}
	
	//setter
		void set(double Width, double Length){
			this->Width=Width;
			this->Length=Length;
			total=(Width*2)+(Length*2);
		}
		
		void setWidth(double Width){
			this->Width=Width;
			total=Width*4;
		}
		
		void setLength(double Length){
			this->Length=Length;
			total=Length*4;
		}
		
		//getter
		double getWidth(){
			return Width;
		}
		
		double getLength(){
			return Length;
		}
		
		double getTotal(){
			return total;
		}

};

//MyRect
class MyRect{
	
	private :
		int row, col;
		Rectangle **a;
		
	public :
		MyRect(){
			
			a=0;
			row=0;
			col=0;
		}
		
		int getRow(){
			return row;
		}
		
		int getColum(){
			return col;
		}
		
		MyRect(int r, int c);
		~MyRect();
		void reset(int,int);
		void showRect(void);
		void setRect(void);
		void setRectTo(void);
		Rectangle **getRect();
		Rectangle getRectTo(int,int);

};

MyRect::MyRect(int r, int c){
	
	row=r;
	col=c;
	a=new Rectangle *[row];
	
	for(int i=0; i<row; i++){
		a[i]=new Rectangle[col];
	}
}

MyRect::~MyRect(){
	
	if(a != 0){
		
		for(int i=0; i<row; i++){
			
			delete[] a[i];
			
		}
		delete[] a;
	}
}

void MyRect::reset(int r, int c){
	
	if(a != 0){
		
		for(int i=0; i<row; i++){
			
			delete[] a[i];
			
		}
		delete[] a;
	}
	row=r;
	col=c;
	a=new Rectangle *[row];
	
	for(int i=0; i<row; i++){
		a[i]=new Rectangle[col];
	}

}

void MyRect::showRect(){
	
	Rectangle **temp=a;
	for(int i=0; i<row; i++){
		cout<<"--------------------------------"<<endl;
		cout<<"#Array <"<<i<<">"<<endl;
		cout<<"--------------------------------"<<endl;
		for(int j=0; j<col;j++){
			
			cout<<"_a["<<i<<"]["<<j<<"]_"<<endl;
			cout<<endl;
			cout<<"Width="<<temp[i][j].getWidth()<<endl;
			cout<<"Length="<<temp[i][j].getLength()<<endl;
			cout<<"total="<<(2*temp[i][j].getLength())+(2*temp[i][j].getWidth())<<endl;		
			cout<<endl;	
		}
		cout<<"--------------------------------"<<endl;
		cout<<endl;
	}
	
}

void MyRect::setRect(){
	
 	cout<<"//setRect"<<endl;
 	for(int i=0; i<row; i++){
 		
 		for(int j=0; j<col; j++){
 			
 			int w,l;
 			cout<<"#Object["<<i<<"]["<<j<<"]"<<endl;
 			cout<<"Put Width => Length :"; cin>>w>>l; 
 			a[i][j].set(w,l);
		 }
	 }
}

void MyRect::setRectTo(){
	
	cout<<"//setRectTo"<<endl;
	int w,l,i,j;
	cout<<"Put Object => [][] :"; cin>>i>>j;
	cout<<endl;
	
	cout<<"#Object["<<i<<"]["<<j<<"]"<<endl;
	cout<<"Put Width => Length :"; cin>>w>>l; 
	
	a[i][j].set(w,l);
}

Rectangle **MyRect::getRect(){
	
	return a;
}

Rectangle MyRect::getRectTo(int r,int c){
	return a[r][c];
}

int Rectangle::count;

int main(){
	
	cout<<"__Obj-A__"<<endl;
	MyRect aNew(2,3);
	aNew.showRect();
	cout<<endl;
	
	aNew.setRect();
	aNew.showRect();
	cout<<endl;
	
	cout<<"//Reset"<<endl;
	aNew.reset(3,4);
	aNew.showRect();
	aNew.setRectTo();
	
	cout<<"--------------------------------"<<endl;
	cout<<"//getRect"<<endl;
	cout<<"--------------------------------"<<endl;	
	Rectangle **temp=aNew.getRect();
	for(int i=0; i<aNew.getRow(); i++){
		cout<<"--------------------------------"<<endl;
		cout<<"#Array <"<<i<<">"<<endl;
		cout<<"--------------------------------"<<endl;
		for(int j=0; j<aNew.getColum();j++){
			
			cout<<"_a["<<i<<"]["<<j<<"]_"<<endl;
			cout<<endl;
			cout<<"Width="<<temp[i][j].getWidth()<<endl;
			cout<<"Length="<<temp[i][j].getLength()<<endl;
			cout<<"total="<<(2*temp[i][j].getLength())+(2*temp[i][j].getWidth())<<endl;		
			cout<<endl;	
		}
	cout<<"--------------------------------"<<endl;
	cout<<endl;
	}	
	
	cout<<"--------------------------------"<<endl;
	cout<<"//getRectTo"<<endl;
	cout<<"--------------------------------"<<endl;	
	cout<<"_a[1][2]_"<<endl;
	cout<<endl;
	Rectangle tempTo=aNew.getRectTo(1,2);
	cout<<"Width="<<tempTo.getWidth()<<endl;
	cout<<"Length="<<tempTo.getLength()<<endl;
	cout<<"Total="<<tempTo.getTotal()<<endl;	
	cout<<endl;	
	cout<<"--------------------------------"<<endl;
	cout<<endl;
	
	return 0;
}
