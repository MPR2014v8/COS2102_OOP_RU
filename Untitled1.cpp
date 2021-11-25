#include<iostream>
using namespace std;

class A {
	int w, h;
	int are;

public : 

	A() {

		w = 0;
		h = 0;
		are = 0;
	}

	A(int i) {

		are = i;
		w = 1;
		h = 1;
	}

	A(int i, int j) {

		w = i;
		h = j;
		are = w * h;
	}

	A operator++() {

		return A(w+1, h+1);
	}

	operator int() {
		cout << "int\n";
		return are;
	}

};

int main() {

	int _a,b;
	A c(10, 20),d(45,54);
	
//	cout << "a=" << _a << endl;
	_a = int(c);
	cout << "a=" << _a << endl;

	cout << "b=" << b << endl;
	//b = d;
	cout << "b=" << b << endl;
	
	system("pause");
	return 0;
}
