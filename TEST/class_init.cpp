#include <iostream>
/*
���أ���ĳ�ʼ��
*/
using namespace std;
class People{
public:
    int age;
    double height;
    int money;
    //�������죬��������
    People(){
        cout<<"People ���캯��"<<endl;
        age=0;
        height=0.5;
        money=99;
    }

    ~People(){
        cout<<"People ��������"<<endl;
    }
    // //���캯������
    // People(int t_age,int t_height){
    //     age=t_age;
    //     height=t_height;
    // }
    //���ڼӷ�����
    People operator+(const People &temp){
        People res;
        res.money=this->money+temp.money;
        return res;
    }

    //���ؼӷ������

protected:
    long long phone_number;
private:
    bool Have_lover;
};
//������дPeople��ļӷ�����:
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
