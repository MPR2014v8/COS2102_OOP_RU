#include <iostream>
#include <string.h>
using namespace std;

class Point {

	private :
		double x;
		double y;
		char name[100];
	    static int count;

	public :
		
		//constuctor
		Point(){
			x=0;
			y=0;
			strcpy(name,"noname");
			count++;
			
			cout << "Object="<<count<<endl;;
			cout << "Hello. " << this->name <<endl;
			cout<<endl;
		}	
		
		Point(double x, double y, char *name){
			this->x=x;
			this->y=y;
			strcpy(this->name,name);
			count++;
			
			cout << "Object="<<count<<endl;;
			cout << "Hello. " << this->name <<endl;
			cout<<endl;	
		}
		
		Point(char *name){
			x=0;
			y=0;
			strcpy(this->name,name);
			count++;
			cout << "Object="<<count<<endl;;
			cout << "Hello. " << this->name <<endl;
			cout<<endl;
		}
		
		Point(double x){
			this->x=x;
			y=0;
			strcpy(name,"noname");
			count++;
			cout << "Object="<<count<<endl;;
			cout << "Hello. " << this->name <<endl;
			cout<<endl;
		}
		
		Point(double x, double y){
			this->x=x;
			this->y=y;
			strcpy(name,"noname");
			count++;
			cout << "Object="<<count<<endl;;
			cout << "Hello. " << this->name <<endl;
			cout<<endl;
		}
		
		~Point(){
			cout << "Bye Bye. " << this->name << endl;
			count--;
			cout << "Object="<<count<<endl;
			cout <<"---------------------------------------------"<< endl;
			cout << endl;
		}
		
        //setter 
        void setter(double x, double y,char* name) {
			this->x = x;
			this->y = y;
			strcpy(this->name,name);
		}
		
		void setX(double x) {
			this->x = x;
		}
		
		void setY(double y) {
			this->y = y;
		}
		
		void setName(char* name) {
			strcpy(this->name,name);
		}
		
		//getter
		double getX() {
			return x;
		}

		double getY() {
			return y;
		}
		
		char* getName(){
			return this->name;
		}
		
		void show(void);
};
//show
void Point::show() {

	cout << "X :" << x << endl;
	cout << "Y :" << y << endl;
	cout << "Name :" << this->name << endl;
	cout <<"---------------------------------------------"<< endl;
	cout << endl;
}
//static variable
int Point::count;

class Matrix{
	private :
		int row, col;
		int **a;
		
	public :
		Matrix(){
			a=0;
			row=col=0;
		}
		
		//set
		void setRow(int r){
			row=r;
		}
		void setCol(int c){
			col=c;
		}
		void setSize(int r, int c){
			row=r;
			col=c;
		}
		
		//get
		int getRow(){
			return row;
		}
		int getCol(){
			return col;
		}
	
		Matrix(int r,int c);
		~Matrix();
		void set();
		void reset(int r, int c);
		void show();
};

Matrix::Matrix(int r, int c){
	row=r;
	col=c;
	a=new int *[row];
	
	for(int i=0; i<row; i++){
		a[i]=new int[col];
	}
}

Matrix::~Matrix(){
	if(a!=0){
		for(int i=0; i<row; i++){
			delete[] a[i];
		}
		delete[] a;
	}
}

void Matrix::set(){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cout<<"Input a["<<i<<"]["<<j<<"]=";
			cin>>a[i][j];
		}
	}
}

void Matrix::reset(int r, int c){
	
	setRow(r); setCol(c);
	
	//delete 
	if(a!=0){
		
		for(int i=0; i<row; i++){
			delete[] a[i];
		}
		delete[] a;
	}
	
	//set
	a = new int *[row];
	for(int i=0; i<row; i++){
		a[i] = new int [col];
	}
}

void Matrix::show(){
	
	for(int i=0; i<row; i++){
		
		for(int j=0; j<col; j++){
			
			cout<<"data["<<i<<"]["<<j<<"]="<<a[i][j]<<endl;
			
		}
		
	}
	
}

main(){
	Matrix aBox(2,3);
	
	aBox.set();
	aBox.show();
	
}
