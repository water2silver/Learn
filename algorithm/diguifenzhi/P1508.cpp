#include <iostream>
/*
Q题: Time Late
暴力深搜 寄了

*/
using namespace std;

int n,m;
int food[205][205];
int res[205][205];

int check(int a,int b);
void solve(int a,int b);

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>food[i][j];
        }
    }

    solve(n+1,(m+1)/2);
    int final=0;
    for(int i=1;i<=m;i++){
        final=max(res[1][i],final);
    }
    cout<<final<<endl;

}

void solve(int a,int b){

    if(check(a-1,b-1)){
        res[a-1][b-1]=max(res[a][b]+food[a-1][b-1],res[a-1][b-1]);
        solve(a-1,b-1);
    }
    if(check(a-1,b)){
        res[a-1][b]=max(res[a][b]+food[a-1][b],res[a-1][b]);
        solve(a-1,b);
    }
    if(check(a-1,b+1)){
        res[a-1][b+1]=max(res[a][b]+food[a-1][b+1],res[a-1][b+1]);
        solve(a-1,b+1);
    }
}

int check(int a,int b){
    if(a>=1&&b>=1&&a<=n&&b<=m){
        return 1;
    }else{
        return 0;
    }
}