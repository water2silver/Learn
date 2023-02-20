#include<iostream>
using namespace std;

class Person
{
	//姓名  �?共权�?
public:
	string m_Name;

	//汽车  保护权限
protected:
	string m_Car;

	//银�?�卡密码  私有权限 
private:
	int m_Password;

public:
	void func()
	{
		m
		m_Name = "����";
		m_Car = "asd";
		m_Password = 123456;
	}
};

int main() {

	Person p;
	p.m_Name = "����";
	//p.func();
    cout<<p.m_Name<<endl;

	return 0;
}