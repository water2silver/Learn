#include <iostream>

using namespace std;

class animal{
    public:
        void sleep(){
            cout<<"sleep zzz..."<<endl;
        }
        void eat(){
            cout<<"zhen xiang!"<<endl;
        }
};
//pubclic 

class cat:public animal{
    public:
        void miaomiao(){
            cout<<"miao miao ..."<<endl;
        }
};
class dog:public animal{
    public:
        void wangwang(){
            cout<<"wang wang ..."<<endl;
        }
};

int main(){
    cat sx;
    dog cz;
    sx.miaomiao();
    sx.sleep();
    sx.eat();
    cout<<"------------"<<endl;
    cz.wangwang();
    cz.sleep();
    cz.eat();

    return 0;
}