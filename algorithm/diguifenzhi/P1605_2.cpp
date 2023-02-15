#include <iostream>
/*迷宫寻找可行的路径有多少
这个题目比较阴损的地方是障碍可能会设置在终点，导致结果为0，需要在dfs检验的顺序考虑

*/
using namespace std;
int data[15][15];
int res;
int dir1[4]={-1,0,0,1};
int dir2[4]={0,-1,1,0};
int x_s,y_s,x_end,y_end;
void dfs(int a,int b);
//查看边界
void output(int a,int b);

int main(){
    //数据读入
    int m,n,t;
    cin>>m>>n>>t;
    
    cin>>x_s>>y_s>>x_end>>y_end;
    
    //初始化图
    for(int i=1;i<=t;i++){
        int a,b;
        cin>>a>>b;
        data[a][b]=1;
        
        //为0，即为不可到达
    }
    //边界处理
    for(int j=0;j<=m+1;j++){
        data[j][0]=1;
        data[j][n+1]=1;
    }
    for(int j=0;j<=n+1;j++){
        data[0][j]=1;
        data[m+1][j]=1;
    }
    dfs(x_s,y_s);
    cout<<res<<endl;
    return 0;
}
void output(int a,int b){
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            cout<<data[i][j]<<" ";
        }cout<<endl;
    }
}


void dfs(int a,int b){
    if(data[a][b]==0){
        if(a==x_end&&b==y_end){
            res++;
            return ;
        }else {
            if(data[a][b]==1){
                return ;
            }else{
                data[a][b]=1;
                for(int i=0;i<=3;i++){
                    dfs(a+dir1[i],b+dir2[i]);
                }
                data[a][b]=0;
            }

        }
    }
}
/*通过
3 3 3
1 1 3 3
1 2 
1 3
3 1
*//*
3 3 1
1 1 3 3
2 2


*/