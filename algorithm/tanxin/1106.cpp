#include <iostream>
#include <string>
using namespace std;
/*
样例
in:
50074897
2
out:
4897
*/
int count[10];
int main()
{
    string data;
    cin>>data;
    
    int n;
    cin>>n;
    for(int i=0;i<=data.length()-1;i++)
    {
        count[data[i]-'0']++;
    }
    int nn=n;
    int flag=-1;
    for(int i=9;i>=0;i--)
    {
        if(count[i]<=nn)
        {
            nn=nn-count[i];
            continue;
        }else if(count[i]>nn)
        {
            count[i]=count[i]-nn;
            flag=i;
            break;
        }
    }
    for(int i=0;i<=data.length()-1;i++)
    {
        if(data[i]-'0'>flag)
        {
            continue;
        }else if(data[i]==flag)
        {
            if(count[flag]!=0)
            {
                count[flag]--;
                continue;
            }
        }else//没有排除首位是0的情况。
        {
            cout<<data[i];
        }
    }


}