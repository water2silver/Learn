#include <iostream>
/*
思路是抄的，代码自己实现，思路要学习
据说可以动态规划？
*/
using namespace std;
int n;
int data[20][20];
int f[12][12][12][12];
int dfs(int a,int b,int x,int y);

int main(){
    //数据读入

    cin>>n;
    while(1){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==b&&b==c&&c==0){
            break;
        }else{
            data[a][b]=c;
        }
    }
    //初始化为 -1
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                for(int l=1;l<=n;l++){
                    f[i][j][k][l]=-1;
                }
            }
        }
    }
    int res=dfs(1,1,1,1);
    cout<<res+data[1][1]<<endl;

    return 0;
}

int dfs(int a,int b,int x,int y){
    if(a==n&&b==n){
        return 0;
    }
    if(f[a][b][x][y]!=-1){
        return f[a][b][x][y];
    }

    int sum=0;
    //可以都往下走
    if(a<n&&x<n){
        sum=dfs(a+1,b,x+1,y)+data[a+1][b]+data[x+1][y]-((a+1)==(x+1)&&y==b)*data[a+1][b];
    }
    if(b<n&&y<n){
        sum=max(sum,dfs(a,b+1,x,y+1)+data[a][b+1]+data[x][y+1]-((b+1)==(y+1)&&a==x)*data[a][b+1]);
    }
    if(a<n&&y<n){
        sum=max(sum,dfs(a+1,b,x,y+1)+data[a+1][b]+data[x][y+1]-((a+1==x)&&(b==y+1))*data[a+1][b]);
    }
    if(b<n&&x<n){
        sum=max(sum,dfs(a,b+1,x+1,y)+data[a][b+1]+data[x+1][y]-((a==x+1)&&(b+1==y))*data[a][b+1]);
    }
    f[a][b][x][y]=sum;
    return sum;


}