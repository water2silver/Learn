#include <iostream>
#include <vector>
/*
vector STL演示
*/

//使用vector的时候需要包含头文件

using namespace std;

class Box{
    public:
        int weight;

};

void print(vector<int> a);

int main(){
    //定义一个存放整数元素地vector
    vector<int> v1;
    //甚至可以用你自定义的元素
    vector<Box> v2;
    
    if(v1.empty()){
        cout<<"v1 is empty"<<endl;
    }

    for(int i=0;i<=4;i++){
        v1.push_back(i);
    }

    cout<<"v1'size = "<<v1.size()<<endl;

    //尝试遍历输出一下
    for(int i=0;i<=4;i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;

    //使用了vector类的构造函数,把v1复制给v3
    vector<int> v3(v1);
    cout<<"print v3"<<endl;
    print(v3);

    cout<<"v3.size() = "<<v3.size()<<endl;
    cout<<"v3.capacity() = "<<v3.capacity()<<endl;
    v3.resize(10);
    print(v3);
    cout<<"after resize()"<<endl;
    cout<<"v3.size() = "<<v3.size()<<endl;
    cout<<"v3.capacity() = "<<v3.capacity()<<endl;

    v3.push_back(6);
    cout<<"after push_back"<<endl;
    cout<<"v3.size() = "<<v3.size()<<endl;
    cout<<"v3.capacity() = "<<v3.capacity()<<endl;
    print(v3);

    // cout<<v3[15];



    return 0;
}

void print(vector<int> a){
    //迭代器
    //v0 v1 v2 v3 v4 v5
    //[)
    for(vector<int>::iterator i=a.begin();i!=a.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
}