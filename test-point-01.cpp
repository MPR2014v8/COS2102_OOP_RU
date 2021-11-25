/* va_arg example */
#include <stdio.h>      /* printf */
#include <stdarg.h>     /* va_list, va_start, va_arg, va_end */
#include <iostream>
#include <string>

using namespace std;

class A
{
	private :
		int num;
		int *a;

	public :

		A(){
			a=0;
		}

		A(int n, int x, ...){

			va_list vl;

			va_start(vl, x);

			num = n;
			a = new int[num];

			for (int i = 0; i < num; ++i)
			{	
				a[i] = va_arg(vl, int);
				cout<<a[i]<<endl;
			}

			va_end(vl);

		}
};

int main ()
{
	A aBOX(7, 2, 8, 2, 10, 5, 8, 44, 55);

  	return 0;
}