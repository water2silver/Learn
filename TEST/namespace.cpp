#include <iostream>

using namespace std;

namespace cat{
    void output(){
        cout<<"cat namespace "<<endl;
    }
}

namespace dog{
    void output(){
        cout<<"dog namespace "<<endl;
    }
}

int main(){
    //output();
    //只使用output会报错，而使用dog::而不会。
    dog::output();

    cat::output();
    return 0;
}
//
