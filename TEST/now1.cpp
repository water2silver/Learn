#include <iostream>
/*
演示类
*/
using namespace std;

class sample{


    private:
        int a;
        int b;
        int c;
    public:
        int d;
        int e;
        int f;
};

void fun1();

int main(){
    sample test1;
    test1.e=7;
    test1.d=6;
    test1.f=8;
    cout<<test1.d;
    //test1.a; 错误
    fun1();

    return 0;
}
void fun1(){
    
}