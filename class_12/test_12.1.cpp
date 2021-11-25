#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

class Rectangle
{
	private:
		
		double width;
		double height;
		double r_area;
		
	public:
		
		Rectangle()
		{
			width =0;
			height =0;
			r_area =0;
		}
		
		Rectangle(double w, double h)
		{
			if(w == 0 || h == 0 )
			{
				throw 0;
			}

			if(w < 0 || h< 0)
			{
				throw 0.2;
			}

			width = w;
			height = h;
			r_area = width * height;
		}

		void set(double w, double h)
		{
			if(w == 0 || h == 0 )
			{
				throw 0;
			}

			if(w < 0 || h< 0)
			{
				throw "string";
			}

			width = w;
			height = h;
			r_area = width * height;
		}
		
		void setWidth(double w)
		{
			if(w == 0)
			{
				throw 0;
			}

			if(w < 0)
			{
				throw "string";
			}

			width = w;
			r_area = width * height;
		}
		
		void setHeight(double h)
		{
			if(h == 0 )
			{
				throw 0;
			}

			if(h< 0)
			{
				throw "string";
			}

			height = h;
			r_area = width * height;
		}
		
		double getWidth(){
			return width;
		}
		
		double getHeight(){
			return height;
		}
		
		double getArea(){
			return r_area;
		}

		friend ostream& operator << (ostream& os, Rectangle& r);
};

ostream& operator << (ostream& os, Rectangle& r){

	os<<"width : "<< r.width <<endl;
	os<<"height : "<< r.height <<endl;
	os<<"area : "<< r.r_area <<endl;

	return os;
}

int main(){
	try{

		Rectangle a(-5, 20), b(40, 50), c(1, 2);

		cout<<"//a\n";
		cout<<a;
		cout<<endl;

        cout<<"//b\n";
		cout<<b;
		cout<<endl;

        cout<<"//c\n";
		cout<<c;
	}

	catch(int){
		cout<<"Exception : Zero\n";
	}

	catch(double){
		cout<<"Exception : less than Zero\n";
	}

	catch(...){
		cout<<"Other Exception\n";
	}

	return 0;
}
