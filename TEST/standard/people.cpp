#include <iostream>
#include "people.hpp"
//
People::People(){
    std::cout<<"People ���캯��"<<std::endl;
    age=0;
    height=0.5;
    money=99;
}

People::~People(){
    std::cout<<"People ��������"<<std::endl;
}

People::People(int t_age,int t_height){
    age=t_age;
    height=t_height;
}

// People People::operator+(const People &temp){
//     People res;
//     res.money=this->money+temp.money;
//     return res;
// }