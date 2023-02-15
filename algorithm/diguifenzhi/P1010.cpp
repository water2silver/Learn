#include <iostream>
/*
数字拆分问题，标准深搜
*/
using namespace std;
int n;

void solve(int a);
int main()
{
    cin>>n;
    solve(n);

    return 0;
}

void solve(int a)
{   
    int flag=0;
    int data[30]={0};
    int t=a;int h=0;
    while(t)
    {   
        data[h++]=t%2;
        t=t/2;
    }
    //最高位一定是1
    for(int i=h-1;i>=0;i--)
    {
        if(data[i])
        {
            if(i==1)
            {   
                if(flag==0)
                {
                    flag=1;
                }else
                {
                    cout<<"+";
                }
                cout<<2;
                
            }else if(i==0)
            {
                if(flag==0)
                {
                    flag=1;
                }else
                {
                    cout<<"+";
                }
                cout<<2<<"(0)";
            }else{
                if(flag==0)
                {
                    flag=1;
                }else
                {
                    cout<<"+";
                }
                cout<<2<<"(";
                solve(i);
                cout<<")";
            }
        }
    }
}
//1315
//2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
//2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)