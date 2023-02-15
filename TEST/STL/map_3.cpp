#include <iostream>
#include <map>
using namespace std;

void test01();

int main(){
    test01();
    


    return 0;
}
void test01(){
    map<string,int> m;
    //利用pair插入map
    m.insert(make_pair("huangyongle",5));
    m.insert(pair<string,int> ("zhangsan",1));
    m.insert(pair<string,int> ("lisi",2));
    
    //利用value_type关键字进行元素插入
    m.insert(std::map<string,int>::value_type ("luoxiang",3));
    //利用数组的方式插入元素
    m["zhaoyun"]=4;
    
    //使用迭代器，输出map每个元素的键和值
    for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    // 得到输出-说明map中根据 键 自动升序排列
    // lisi 2
    // luoxiang 3
    // zhangsan 1
    // zhaoyun 4
    cout<<"---------------------------"<<endl;
    //反向迭代器输出
    for(map<string,int>::reverse_iterator it=m.rbegin();it!=m.rend();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    // 输出
    // zhaoyun 4
    // zhangsan 1
    // luoxiang 3
    // lisi 2
    
    //find 寻找 键 对应的 pair
    map<string,int>::iterator self;
    self = m.find("zhangsan");
    if(self!=m.end())
        cout<<"self->first = "<<self->first<<" self->second = "<<self->second<<endl;
    else{
        cout<<"no exist"<<endl;
    }

    //清除 键 对应的值
    cout<<"after erase zhangsan"<<endl;
    m.erase("zhangsan");
    for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    //count("**")寻找某个键出现的次数
    cout<<"m.count(\"lisi\") = "<<m.count("lisi")<<endl;

    //改变map键值排序的规则
    map<string, int, std::greater<std::string> >myMap{ {"C语言教程",10},{"STL教程",20} };
    for(map<string,int>::iterator it=myMap.begin();it!=myMap.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<"map.maxsize()"<<m.max_size()<<endl;
}