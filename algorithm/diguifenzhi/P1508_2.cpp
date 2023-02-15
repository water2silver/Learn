#include <iostream>
/*
正确做法，思路是从n-1行网上开始构造，每一行都构造最合理的取值

*/
using namespace std;

int n,m;
int food[205][205];
int res[205][205];
int flag[205][205];

int dir[4]={0,-1,0,1};
int check(int a,int b);
void solve();

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>food[i][j];
        }
    }
    res[n][(m+1)/2-1]=food[n][(m+1)/2-1];
    flag[n][(m+1)/2-1]=1;
    res[n][(m+1)/2]=food[n][(m+1)/2];
    flag[n][(m+1)/2]=1;
    res[n][(m+1)/2+1]=food[n][(m+1)/2+1];
    flag[n][(m+1)/2+1]=1;

    solve();

    int final=res[1][(m+1)/2+1];
    for(int i=1;i<=m;i++){
        if(flag[1][i])
            final=max(res[1][i],final);
    }
    
    cout<<final<<endl;
    return 0;
}

void solve(){
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=3;k++){
                if(check(i+1,j+dir[k])&&flag[i+1][j+dir[k]]){
                    if(flag[i][j]==0){
                        res[i][j]=food[i][j]+res[i+1][j+dir[k]];
                        flag[i][j]=1;
                    }else{
                        res[i][j]=max(res[i][j],food[i][j]+res[i+1][j+dir[k]]);
                    }
                }
            }

        }
    }

}

int check(int a,int b){
    if(a>=1&&b>=1&&a<=n&&b<=m){
        return 1;
    }else{
        return 0;
    }
}