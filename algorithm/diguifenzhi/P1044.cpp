#include <iostream>
/*
老难题了
采取递归化搜索
这一版做法有一个点time out了
*/
using namespace std;

long long data[20][20];
long long dfs (int a,int b);

int main(){

    int n;cin>>n;
    // data[0][1]=1;data[0][2]=2;
    // data[1][0]=1;data[1][1]=2;
    long long res=dfs(n,0); 
    cout<<res<<endl;
}

long long dfs (int a,int b){
    long long temp=0;
    //temp=data[a-1][b+1]+data[a][b-1];
    if(a>=1&&b>=1){
        temp=dfs(a-1,b+1)+dfs(a,b-1);
    }else if(a>=1&&b==0){
        temp=dfs(a-1,b+1);
    }else if(a==0&&b>=1){
        //这种情况直接结束了
        temp=1;
    }else{
        //这里return多少合适？
        temp=0;
    }
    return temp;
}