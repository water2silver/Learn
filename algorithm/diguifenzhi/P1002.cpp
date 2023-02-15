#include <iostream>
/*
在有障碍地图中寻找去往终点路线数目的问题
此做法为深搜，超时

*/
using namespace std;
int Bx,By;
int Mx,My;
int data[25][25];
int res=0;
int dir1[9]={-2,-2,-1,-1,1,1,2,2,0};
int dir2[9]={-1,1,-2,2,-2,2,-1,1,0};
void dfs(int a,int b);
int check_Ma(int x,int y);

int main(){
    cin>>Bx>>By;
    cin>>Mx>>My;

    dfs(0,0);
    cout<<res<<endl;

    return 0;
}

void dfs(int a,int b){
    if(a==Bx&&b==By){
        res++;
        return ;
    }else if(check_Ma(a,b)==0){

        return ;
    }

    if(a<Bx&&b<By){  
        dfs(a+1,b);
        dfs(a,b+1);
    }
    else if(a<Bx&&b==By){
        dfs(a+1,b);

    }
    else if(a==Bx&&b<By){
        dfs(a,b+1);
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