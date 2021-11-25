#include <iostream>
using namespace std;

class Rectangle{
	
	private :
		double Width;
		double Length;
		double total;
		static int num;
		
	public :
	//constructor 	
		Rectangle(){
			Width=0;
			Length=0;
			total=0;
			num++;
			/*cout << "Object=" << count <<endl;
			cout<<endl;*/
		}
		
		Rectangle(double Width){
			this->Width=Width;
			total=Width*4;
			Length=0;
			num++;
			/*cout << "Object=" << count <<endl;
			cout<<endl;*/
		}		
		
		Rectangle(double Width, double Length){
			this->Width=Width;
			this->Length=Length;
			total=(Width*2)+(Length*2);
			num++;
		/*	cout << "Object=" << count << endl;
			cout<<endl;*/
		}
		
		~Rectangle(){
			
			cout << "Bye!. Object=" << num <<endl;
			num--;
		/*	cout << "Object=" << count <<endl;
			cout<<endl;*/
		}
	
	//setter
		void setWidth(double Width){
			this->Width=Width;
		}
		
		void setLength(double Length){
			this->Length=Length;
		}
		
		//getter
		double getWidth(){
			return Width;
		}
		
		double getLength(){
			return Length;
		}
		
		static int Count(){
			return num;
		}
		
		void show(void);
};
//show
void Rectangle::show(){
	
	if(Length==0){
		cout << "            _Square_" <<endl;
		cout << " Width=" << Width <<endl;
		cout << " Length=" << Length <<endl;
		cout << " Perimeter=" << total <<endl;
		cout << "---------------------------------" <<endl;
	}else
	
	if(Width!=0 && Length!=0){
		cout << "            _Rectangle_" <<endl;
		cout << " Width=" << Width <<endl;
		cout << " Length=" << Length <<endl;
		cout << " Perimeter=" << total <<endl;
		cout << "---------------------------------" <<endl;
	}else
	
	if(Width==0 && Length==0){
		cout << "            _Square_" <<endl;
		cout << " Width=" << Width <<endl;
		cout << " Length=" << Length <<endl;
		cout << " Perimeter=" << total <<endl;
		cout << "---------------------------------" <<endl;
	}
}

int Rectangle::num;

int main(){
	
	cout  <<"Object=" << Rectangle::Count() << endl;
	Rectangle aBox;
	aBox.show();
	cout  <<"Object=" << Rectangle::Count() << endl;
	Rectangle bBox(10);
	bBox.show();
	cout  <<"Object=" << Rectangle::Count() << endl;
	Rectangle cBox(10,2);
	cBox.show();
	cout  <<"Object=" << Rectangle::Count() << endl;
	Rectangle dBox;
	dBox.setWidth(20);
	dBox.show();
	cout  <<"Object=" << Rectangle::Count() << endl;
	Rectangle eBox;
	eBox.setWidth(40); eBox.setLength(10.5);
	eBox.show();
	cout  <<"Object=" << Rectangle::Count() << endl;
	Rectangle fBox;
	fBox.setWidth(80); fBox.setLength(10);
		cout << "            _Rectangle_" <<endl;
		cout << " Width=" << fBox.getWidth() <<endl;
		cout << " Length=" << fBox.getLength() <<endl;
		cout << " Perimeter=" << (2*fBox.getWidth())+(2*fBox.getLength()) <<endl;
		cout << "---------------------------------" <<endl;
	cout  <<"Object=" << Rectangle::Count() << endl;
	Rectangle gBox;
	gBox.setWidth(80);
		cout << "            _Square_" <<endl;
		cout << " Width=" << gBox.getWidth() <<endl;
		cout << " Length=" << gBox.getLength() <<endl;
		cout << " Perimeter=" << (4*gBox.getWidth()) <<endl;
		cout << "---------------------------------" <<endl;
	cout  <<"Object=" << Rectangle::Count() << endl;
	cout << endl;
	
	return 0;
}
