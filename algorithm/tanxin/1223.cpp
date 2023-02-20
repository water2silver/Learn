#include <iostream>
#include <map>
#include <algorithm>
/*
比较典型的贪心问题。
*/
using namespace std;
class Node
{
    public :
        long long t;
        int c;
    Node operator =(const Node &nn)
    {
        this->t=nn.t;
        this->c=nn.c;
        return *this;
    }
};

bool comp(Node a,Node b)
{
    return a.t<b.t;
}
int main()
{
    int n;
    cin>>n;
    Node data[1010];
    long long dd[1010];

    for(int i=1;i<=n;i++)
    {
        cin>>data[i].t;
        data[i].c=i;
    }
    sort(data+1,data+n+1,comp);
    dd[1]=data[1].t;
    for(int i=2;i<=n;i++)
    {
        dd[i]=dd[i-1]+data[i].t;
    }
    double sum=0;
    for(int i=2;i<=n;i++)
    {   
        //+号后面隐藏着数据类型转换不当的问题
        sum=sum*(i-1)/(double)i+dd[i-1]/(double)i;
        //sum+=dd[i-1];
        //cout<<"前"+to_string(i)+"个人平均等待时间 = "<<sum<<endl;
    }
    //sum/=n;

    //真实排列
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<data[i].t<<" ";
    // }cout<<endl;

    for(int i=1;i<=n;i++)
    {
        cout<<data[i].c<<" ";
    }cout<<endl;
    printf("%.2lf",sum);
    return 0;
}