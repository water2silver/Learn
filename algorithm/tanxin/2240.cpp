#include <iostream>
#include <algorithm>
using namespace std;
/*2023.2.18
假背包，根据性价比选择最高的宝藏，依次纳入即可
考察一些C++的使用，比如 sort ,类内加法
*/
class solve{
public:
    double  m;
    double  v;
    double  p;
    solve &operator =(const solve &s)
    {
        this->m=s.m;
        this->v=s.v;
        this->p=s.p;
        return *this;
    }
};
bool comp(solve a,solve b)
{
    return a.p>b.p;
}
int main()
{   
    int N,T;
    solve data[110];
    cin>>N>>T;
    for(int i=1;i<=N;i++)
    {
        cin>>data[i].m>>data[i].v;
        data[i].p=data[i].v/data[i].m;
    }
    sort(data+1,data+N+1,comp);
    
    double sum=0;
    for(int i=1;i<=N;i++)
    {
        if(T>data[i].m)
        {
            T=T-data[i].m;
            sum+=data[i].v;
        }else if(T<=data[i].m)
        {
            sum+=T*data[i].p;
            break;
        }
    }
    printf("%.2lf",sum);

    return 0;
}