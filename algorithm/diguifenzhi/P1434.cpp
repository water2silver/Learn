#include <iostream>
/*
4 6 测试点没过
笑拉了，Max_length从0改成1就AC了
核心：记忆化深搜
*/
using namespace std;
int R,C;

int Max_length=1;
int data[110][110];
int height[110][110];
int dir1[4]={-1,0,0,1};
int dir2[4]={0,-1,1,0};
int check_xy(int x,int y);
void dfs(int x,int y);


int main(){
    cin>>R>>C;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin>>data[i][j];
            height[i][j]=-1;
        }
    }
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            dfs(i,j);
        }
    }
    cout<<Max_length<<endl;
    


    return 0;
}

void dfs(int x,int y){
    if(height[x][y]!=-1){
        return ;
    }
    int flag=0;
    for(int i=0;i<=3;i++){
        if(check_xy(x+dir1[i],y+dir2[i])){
            if(data[x][y]>data[x+dir1[i]][y+dir2[i]]){
                flag=1;
                if(height[x+dir1[i]][y+dir2[i]]==-1){
                    dfs(x+dir1[i],y+dir2[i]);
                }
                height[x][y]=max(height[x][y],1+height[x+dir1[i]][y+dir2[i]]);
                if(height[x][y]>Max_length){
                    Max_length=height[x][y];
                }
            }
        }
    }
    if(flag==0){
        height[x][y]=1;
    }

}

int check_xy(int x,int y){
    if(x>=1&&x<=R&&y>=1&&y<=C){
        return 1;
    }else{
        return 0;
    }

}