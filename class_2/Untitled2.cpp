#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
 
class Timer{
    using clk = chrono::steady_clock;
    clk::time_point begin;
    clk::time_point end;
public:
    void clear(){begin = end = clk::now();}
    void start(){begin = clk::now();}
    void stop(){end = clk::now();}
    friend ostream& operator<<(ostream& o, Timer& timer){
        return o << timer.sec();
    }
    double sec() const{
        if(end <= begin) return 0.0;
        auto d = chrono::duration_cast<chrono::microseconds>(end - begin);
        return d.count() / 1000000.0;
    }  
};
int array_size = 100000;
void static_array(){
    static int a[100000];
}
void heap_array(){
    int* a = new int[array_size];
}
void stack_array(){
    int a[array_size];
}
 
int main(){
    int loop_times = 100000;
    Timer timer;
    timer.start();
    for(int i=0;i<loop_times;i++){
        stack_array();
    }
    timer.stop();
    cout<<"stack_array() : "<<timer<<" secons."<<endl;
    timer.clear();
    timer.start();
    for(int i=0;i<loop_times;i++){
        heap_array();
    }
    timer.stop();
    cout<<"heap_array() : "<<timer<<" secons."<<endl;
    timer.clear();
    timer.start();
    for(int i=0;i<loop_times;i++){
        static_array();
    }
    timer.stop();
    cout<<"static_array() : "<<timer<<" secons."<<endl;
    return 0;
}
