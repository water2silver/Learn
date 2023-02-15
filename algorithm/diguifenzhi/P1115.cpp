#include <iostream>
/*
最大子段和
这个写法有点贪心的意思
当前的累计和>=0，我继续要，不然就丢掉，用一个max保存最大值，注意max最好取一个很大的负数或者取-a_1
*/
using namespace std;

int main(){
    long long n,max=-1<<30; long long sum =0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {   
        int a;
        cin>>a;
        sum=sum>=0?sum:0;
        sum+=a;
        if(sum>max){
            max=sum;
        }
        
    }
    cout<<max<<endl;

    return 0;
}