#include <string>
#include <iostream>

void Output() {
    std::cout<<std::endl;
}

template<typename First, typename ... Int>
void Output(First arg, const Int&... rest) {
    std::cout<<arg<<" ";
    Output(rest...);
}

int main() {
	std::cout<<"DDDD";
	Output();
    Output(1, 2, 3, 4, 5, 6, 7, 8, 9);
   // Output("Let's","try",1,"or",2,"digits");
    return 0;
}