#include <iostream>
#include <algorithm>
using namespace std;
/*
23.2.19
*/
bool comp(pair<int,int> a,pair<int,int> b)
{
    return a.second<b.second;
}
int main()
{
    int n;
    //如果是 1000010 本地编译出的文件无法顺利执行。
    pair<int,int> data[1000010];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>data[i].first>>data[i].second;
        
    }
    sort(data+1,data+n+1,comp);
    int sum=0;
    int last=0;
    for(int i=1;i<=n;i++)
    {
        if(data[i].first>=last)
        {
            last=data[i].second;
            sum++;
        }
    }
    cout<<sum<<endl;
    return 0;
}