#include <iostream>
/*
重载，类的初始化
*/
using namespace std;
class People{
public:
    int age;
    double height;
    int money;
    //基础构造，析构函数
    People(){
        cout<<"People 构造函数"<<endl;
        age=0;
        height=0.5;
        money=99;
    }

    ~People(){
        cout<<"People 析构函数"<<endl;
    }
    // //构造函数重载
    // People(int t_age,int t_height){
    //     age=t_age;
    //     height=t_height;
    // }
    //类内加法重载
    People operator+(const People &temp){
        People res;
        res.money=this->money+temp.money;
        return res;
    }

    //重载加法运算符

protected:
    long long phone_number;
private:
    bool Have_lover;
};
//在类外写People类的加法重载:
// People operator+(const People &temp1,const People &temp2){
//     People res;
//     res.money=temp1.money+temp2.money;
//     return res;
// }


int sum(int a,int b);
int sum(int a,int b,int c);

int main(){
    People zhangsan;
    People lisi;
    People luoxiang=zhangsan+lisi;

    cout<<"zhangsan.money = "<<zhangsan.money<<endl;
    cout<<"lisi.money = "<<lisi.money<<endl;
    cout<<"luoxiang.money = "<<luoxiang.money<<endl;



    return 0;
}

int sum(int a,int b){
    return a+b;
}
int sum(int a,int b,int c){
    return a+b+c;
}
