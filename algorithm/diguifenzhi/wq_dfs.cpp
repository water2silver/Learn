#include <iostream>

using namespace std;
int m,n;int res=10000000;

void dfs(int num,int u);

int main(){
    cin>>m>>n;
    dfs(m,0);
    cout<<res<<endl;

    return 0;
}

void dfs(int num,int u){
    if(num>n){
        return ;
    }else if(num==n){
        res=min(res,u);
    }else if(num==1){
        dfs(num+1,u+1);
        dfs(num*2,u+1);
    }else {
        dfs(num+1,u+1);
        dfs(num*2,u+1);
        dfs(num*num,u+1);
    }

}

