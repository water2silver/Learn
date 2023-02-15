#include <iostream>
/*迷宫寻找可行的路径有多少
这个做法错误，不建议观看
*/
using namespace std;
int data[15][15];
//某个点到终点的方案数目
int solution[15][15];

int dir1[4]={-1,0,0,1};
int dir2[4]={0,-1,1,0};
int x_s,y_s,x_end,y_end;
void dfs(int a,int b);
//查看边界
void output(int a,int b);
//查看solution矩阵
void output2(int a,int b);
int main(){
    //数据读入
    int m,n,t;
    cin>>m>>n>>t;
    
    cin>>x_s>>y_s>>x_end>>y_end;

    //终点端默认是0吧
    solution[x_end][y_end]=0;
    //初始化solution[][]
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            //-1表示还未被计算
            solution[i][j]=-1;
        }
    }
    //初始化图
    for(int i=1;i<=t;i++){
        int a,b;
        cin>>a>>b;
        data[a][b]=1;
        //为0，即为不可到达
        solution[a][b]=0;
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
    output(m+1,n+1);
    

    dfs(x_s,y_s);
    output2(m,n);
    cout<<solution[x_s][y_s]<<endl;
    
    return 0;
}
void output(int a,int b){
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            cout<<data[i][j]<<" ";
        }cout<<endl;
    }
}
void output2(int a,int b){
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            cout<<solution[i][j]<<" ";
        }cout<<endl;
    }
}

void dfs(int a,int b){
    if(a==x_end&&b==y_end){
        solution[a][b]=1;
    }
    int sum=0;
    for(int i=0;i<=3;i++){
        if(data[a+dir1[i]][b+dir2[i]]==0){
            data[a][b]=1;
            if(solution[a+dir1[i]][b+dir2[i]]==-1){
                dfs(a+dir1[i],b+dir2[i]);
                sum=sum+1+data[a+dir1[i]][b+dir2[i]];
            }else{
                sum=sum+data[a+dir1[i]][b+dir2[i]];
            }
        }else{
            //啥都不干
        }
    }
    solution[a][b]=sum;
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