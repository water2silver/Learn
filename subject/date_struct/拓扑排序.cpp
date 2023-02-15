#include <iostream>
#include <queue>
using namespace std;
/*
思考 拓扑路径唯一否

*/
int n;
int g[101][101];
int s[101];//集合
int ind[101];
queue <int> q;

void init();
void input();
void toposort();

int main(){
    input();
    init();
    toposort();
    return 0;
}/*4
0 1 1 0
0 0 0 1
0 0 0 1
0 0 0 0

*//*
12
0 1 1 1 0 0 0 0 0 0 0 1
0 0 1 0 0 0 0 0 0 0 0 0
0 0 0 0 1 0 1 1 0 0 0 0
0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0 0

0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 1 1 1
0 0 0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0



*/

void toposort(){
    int u;int i;
    while(!q.empty()){
        //1.从队列面取出一个入读为0的结点u
        u=q.front();q.pop();
        //2.输出结点 u
        cout<<u+1<<" ";
        //3.删除所有u发出的边（一旦出现了入度为0的点，加入队列）
        for(i=0;i<=n-1;i++){
            if(g[u][i]==1){
                ind[i]--;
                if(ind[i]==0){
                    q.push(i);
                }
            }
        }
        //4.删除u---老师删除了这一步
        s[u]=0;

    }

}
void input(){
    cin>>n;
    int i,j;
    for(i=0;i<=n-1;i++){
        for(j=0;j<=n-1;j++){
            cin>>g[i][j];
            if(g[i][j]==1) ind[j]++;//j的入读增加
        }
    }
}

void init(){
    //1.找到所有入读为0的结点 ，加入队列中
    int i;
    //2.找出所有入读为0的点
    for(i=0;i<n;i++){
        if(ind[i]==0){
            q.push(i);
        }
    }
}