#include <iostream>
#include <iomanip>
using namespace std;

int Prime [10010];
int visit [10010];

void Search_Prime();
void Show_Prime(int num);

int main()
{
    Search_Prime();
    Show_Prime(100);


    return 0;
}
void Search_Prime()
{   int h=0;
    for(int i=2;i<=10000;i++)
    {
        if(visit[i]==0)
        {
            Prime[++h]=i;
        }
        for(int j=1;j<=h&&Prime[j]*i<=10000;j++)
        {
            visit[Prime[j]*i]=1;
            if(i%Prime[j]==0)
            {
                break;
            }
        }
    }
}
void Show_Prime(int num)
{
    for(int i=1;i<=num;i++)
    {
        cout<<setw(6)<<Prime[i];
        if(i%10==0)
        {
            cout<<endl;
        }
    }
}