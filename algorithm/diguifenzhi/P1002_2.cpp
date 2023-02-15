#include <iostream>
#include <iomanip>
/*
记忆化搜索升级，最后却在条件判断的地方写错了代码，很令人生气

*/
using namespace std;
int Bx,By;
int Mx,My;
long long data[25][25];
int res=0;
int dir1[9]={-2,-2,-1,-1,1,1,2,2,0};
int dir2[9]={-1,1,-2,2,-2,2,-1,1,0};
void dfs(int a,int b);
int check_Ma(int x,int y);
void output(int m,int n);

int main(){
    
    cin>>Bx>>By;
    cin>>Mx>>My;
    for(int i=0;i<=Bx;i++){
        for(int j=0;j<=By;j++){
            data[i][j]=-1;
        }
    }

    dfs(0,0);   
    //output(Bx,By);
    cout<<data[0][0]<<endl;

    return 0;
}

void dfs(int a,int b){
    
    if(check_Ma(a,b)==0){
        //遇到马则方法为0
        data[a][b]=0;
        return ;
    }else if(a>Bx||b>By){
        data[a][b]=0;
        return ;
    }else if(a==Bx&&b==By){
        data[a][b]=1;
        return ;
    }

    if(a<Bx&&b<By){
        if(data[a+1][b]==-1){
            dfs(a+1,b);
        }
        if(data[a][b+1]==-1){
            dfs(a,b+1);
        }
        data[a][b]=data[a+1][b]+data[a][b+1];
    }else if(a==Bx){
        if(data[a][b+1]==-1){
            dfs(a,b+1);
        }
        data[a][b]=data[a][b+1];
    }else if(b==By){//这里我把By写成了Bx，导致出错
        if(data[a+1][b]==-1){
            dfs(a+1,b);
        }
        data[a][b]=data[a+1][b];
    }
}
void output(int m,int n){
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            cout<<setw(4)<<data[i][j];
        }cout<<endl;
    }
}

int check_Ma(int x,int y){
    int flag=1;
    for(int i=0;i<=8;i++){
        if(x-dir1[i]==Mx&&y-dir2[i]==My){
            flag=0;
            break;
        }
    }
    return flag;
}