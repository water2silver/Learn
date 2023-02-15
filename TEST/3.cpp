#include <iostream>
/*
建议使用构造函数初始化类

*/


using namespace std;

class cublic{
public:
    int height=1;
    int width=2;
    int length=3;
    void output(){
        cout<<"height = "<<height<<endl;
        cout<<"length = "<<length<<endl;
        cout<<"width = "<<width <<endl;
    }
    cublic(){

    }
    ~cublic(){

    }
};


int main(){
    cublic a;
    a.output();


    return 0;
}