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
    //����pair����map
    m.insert(make_pair("huangyongle",5));
    m.insert(pair<string,int> ("zhangsan",1));
    m.insert(pair<string,int> ("lisi",2));
    
    //����value_type�ؼ��ֽ���Ԫ�ز���
    m.insert(std::map<string,int>::value_type ("luoxiang",3));
    //��������ķ�ʽ����Ԫ��
    m["zhaoyun"]=4;
    
    //ʹ�õ����������mapÿ��Ԫ�صļ���ֵ
    for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    // �õ����-˵��map�и��� �� �Զ���������
    // lisi 2
    // luoxiang 3
    // zhangsan 1
    // zhaoyun 4
    cout<<"---------------------------"<<endl;
    //������������
    for(map<string,int>::reverse_iterator it=m.rbegin();it!=m.rend();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    // ���
    // zhaoyun 4
    // zhangsan 1
    // luoxiang 3
    // lisi 2
    
    //find Ѱ�� �� ��Ӧ�� pair
    map<string,int>::iterator self;
    self = m.find("zhangsan");
    if(self!=m.end())
        cout<<"self->first = "<<self->first<<" self->second = "<<self->second<<endl;
    else{
        cout<<"no exist"<<endl;
    }

    //��� �� ��Ӧ��ֵ
    cout<<"after erase zhangsan"<<endl;
    m.erase("zhangsan");
    for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    //count("**")Ѱ��ĳ�������ֵĴ���
    cout<<"m.count(\"lisi\") = "<<m.count("lisi")<<endl;

    //�ı�map��ֵ����Ĺ���
    map<string, int, std::greater<std::string> >myMap{ {"C���Խ̳�",10},{"STL�̳�",20} };
    for(map<string,int>::iterator it=myMap.begin();it!=myMap.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<"map.maxsize()"<<m.max_size()<<endl;
}