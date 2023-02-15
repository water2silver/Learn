#include<iostream>
using namespace std;

class Person
{
	//濮撳悕  鍏?鍏辨潈闄?
public:
	string m_Name;

	//姹借溅  淇濇姢鏉冮檺
protected:
	string m_Car;

	//閾惰?屽崱瀵嗙爜  绉佹湁鏉冮檺
private:
	int m_Password;

public:
	void func()
	{
		m_Name = "张三";
		m_Car = "asd";
		m_Password = 123456;
	}
};

int main() {

	Person p;
	p.m_Name = "李四";
	//p.func();
    cout<<p.m_Name<<endl;

	return 0;
}