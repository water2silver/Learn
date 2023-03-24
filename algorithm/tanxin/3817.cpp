#include <iostream>
using namespace std;
/*
2.21 比较基础的贪心，便利数量数组
因为 a[1]+a[2]<=x 所以要最优先处理a[2]，如果不行，再处理a[1]
后面同理
*/
int main()
{
    int n,x;
    cin>>n>>x;
    int data[100010];long long sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>data[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        if(data[i]+data[i+1]<=x) continue;
        else if(data[i]>=x)
        {
            sum+=(long long)(data[i+1]+data[i]-x);
            data[i]=x;
            data[i+1]=0;
        }else if(data[i]+data[i+1]>x)
        {
            sum+=(long long)(data[i]+data[i+1]-x);
            data[i+1]=x-data[i];
        }

    }
    cout<<sum<<endl;
    return 0;
}