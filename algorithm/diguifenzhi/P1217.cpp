#include <iostream>
#include <vector>
/*
回文素数，我的思路是先把所有素数找到，然后挨个判断是否是回文数
欧拉筛的关键在于基础当前遍历的数字，对其的质数倍进行否行，从而简化判断过程
*/
#define n 100000000
//#define n 20000000
//提交洛谷的时候，n设置为这么大正好可以通过题目，但是如果设置的太大，会给RE的错误
using namespace std;
int a,b;
int h;

vector<int> res;
int prime[1000000];
bool visit[n];
int cnt=0;
void isPrime();
void output();
bool check_huiwen(int a);

int main(){
    cin>>a>>b;  
    isPrime();
    //cout<<cnt<<endl;
    //output();
    for(int i=1;i<=cnt;i++){
        if(a<=prime[i]&&prime[i]<=b){
            if(check_huiwen(prime[i])){
                cout<<prime[i]<<endl;
            }
        }else if(prime[i]<a){

        }else if(prime[i]>b) break;
        
    }

    



    return 0;
}
bool check_huiwen(int a){
    int temp=0;
    int t=a;
    while(t){
        temp=temp*10+t%10;
        t=t/10;
    }
    if(temp==a) return 1;
    else return 0;

}

void output(){
    for(int i=1;i<=cnt;i++){
        cout<<prime[i]<<" ";
    }

}
//
void isPrime(){
    
    //注意从2开始    
    for(int i=2;i<=n;i++){
        if(!visit[i]) prime[++cnt]=i;
        for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
            //这一步vist实际上是最主要的筛选过程
            visit[i*prime[j]]=1;
            //
            if(i%prime[j]==0){
                break;
            }

        }
    }
}