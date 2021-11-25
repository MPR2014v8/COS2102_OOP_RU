class Rectangle{
	
	private :
		double Width;
		double Length;
		static int count;
		
	public :
	//constructor 	
		Rectangle(){
			Width=0;
			Length=0;
			count++;
			//cout << "Object=" << count <<endl;
			//cout<<endl;
		}
		
		Rectangle(double Width){
			this->Width=Width;
			Length=0;
			count++;
			//cout << "Object=" << count <<endl;
			//cout<<endl;
		}		
		
		Rectangle(double Width, double Length){
			this->Width=Width;
			this->Length=Length;
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
		
		//void show(void);
}; 
//show
/*void Rectangle::show(){
	
	if(Length==0){
		cout << "            _Square_" <<endl;
		cout << " Width=" << Width <<endl;
		cout << " Length=" << Length <<endl;
		cout << " Perimeter=" << (4*Width) <<endl;
		cout << "---------------------------------" <<endl;
	}else
	
	if(Width!=0 && Length!=0){
		cout << "            _Rectangle_" <<endl;
		cout << " Width=" << Width <<endl;
		cout << " Length=" << Length <<endl;
		cout << " Perimeter=" << (2*Width)+(2*Length) <<endl;
		cout << "---------------------------------" <<endl;
	}else
	
	if(Width==0 && Length==0){
		cout << "            _Square_" <<endl;
		cout << " Width=" << Width <<endl;
		cout << " Length=" << Length <<endl;
		cout << " Perimeter=" << (4*Width) <<endl;
		cout << "---------------------------------" <<endl;
	}
}

int Rectangle::count;*/

