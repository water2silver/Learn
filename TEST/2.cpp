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
        sample(){
            cout<<"sample"<<endl;
            a=1;
            b=1;
            c=1;
            d=666;
        }
        ~sample(){
            cout<<"~sample"<<endl;
        }
        // void output(){
        //     cout<<"a="<<a<<endl;
        //     cout<<"b="<<b<<endl;
        //     cout<<"c="<<c<<endl;
        // }
        //
        // void operator+=(const sample &s) {
        //     this->a += s.a;
        //     this->b += s.b;
        //     this->c += s.c;
        // }
        //
        // void sum(int temp_a){
        //     cout<<"temp_a = "<<temp_a<<endl;
        // }        
        // void sum(int temp_a,int temp_b){
        //     cout<<"temp_a+temp_b = "<<temp_a+temp_b<<endl;
        // }
};

sample operator+(sample a,sample b) {
    sample c;
    c.d=a.d*b.d;
    return c;
}


int main(){
    
    //展示private pubulic protected
    sample p1;
    //sample();
    //~sample();
    //cout<<"p1.d = "<<p1.d<<endl;
    //printf("%d",10);
    int a=1,b=2;
    a+=b;//= a=a+b
    sample p1,p2;
    p1+=p2;


    //你会发现你输入 "p1." 之后，不会出现a,b,c 只会提示你d

    //展示函数重载
    // p1.sum(6);
    // p1.sum(6,6);


    // //演示重载运算符
    // sample t1,t2;
    // t1+=t2;

    // t1.output();

    return 0;
}




int sum(int a,int b,int c){
    return a+b+c;
}