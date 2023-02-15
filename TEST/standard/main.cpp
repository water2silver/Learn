#include <iostream>
#include "people.hpp"

using namespace std;
int main(){
    People zhangsan;
    People lisi;
    //People luoxiang=zhangsan+lisi;
    cout<<"zhangsan.money = "<<zhangsan.money<<endl;
    cout<<"lisi.money = "<<lisi.money<<endl;
    //cout<<"luoxiang.money = "<<luoxiang.money<<endl;
    return 0;
}
