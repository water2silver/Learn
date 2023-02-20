#include <iostream>
#include <queue>
//#include <vector>
using namespace std;
/*
使用优先队列解决问题
算法思路：尽量先合并重量小的，重量大的最后合并。
*/
priority_queue <int,vector<int>,greater<int> > q;
int main()
{
    int n;
    int a;int sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        q.push(a);
    }
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        a=q.top();q.pop();
        b=q.top();q.pop();
        sum+=a+b;
        q.push(a+b);
    }
    cout<<sum<<endl;

    return 0;
}
