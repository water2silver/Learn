#include <iostream>
#include <queue>
using namespace std;
/*最早最晚问题

*/
queue <int> q;
int n;
int g[101][101];
int s[101];//集合
int ind[101];
int ee[101];//每个事件的最早开始时间
int le[101];//每个事件的最晚开始时间
int t[101];

void init();
void input();
void toposort();
void Output();
void Critical_path();

int main(){
    input();
    init();
    toposort();
    Critical_path();//关键路径
    Output();
    return 0;
}

void toposort(){
    int u;int i;
    int  cnt=0;
    while(!q.empty()){
        //1.从队列面取出一个入读为0的结点u
        u=q.front();q.pop();
        //2.输出结点 u
        //cout<<u<<" ";
        //记录关键路径
        t[cnt]=u;
        cnt++;//

        //3.删除所有u发出的边（一旦出现了入度为0的点，加入队列）
        for(i=0;i<=n-1;i++){
            if(g[u][i]<10000){
                ind[i]--;
                if(ind[i]==0){
                    q.push(i);
                }
            }
        }
        //4.删除u---老师删除了这一步
        //s[u]=0;

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
        if(ind[i]=0){
            q.push(i);
        }
    }
}
void Critical_path(){
    int i,j;int u;
    //1.求出所有点的最早开始时间
    for(i=0;i<n;i++){
        u=t[i];//用u去更新其他的所有点
        for(j=0;j<n;j++){
            if(g[u][j]<10000){//这里是为什么？
                if(ee[u]+g[u][j]>ee[j]){
                    ee[j]==ee[u]+g[u][j];
                }
            }
        }
    }
    //2.
    //3.

}


void Output(){
    int i;
    for(i=0;i<=n-1;i++){
        cout<<ee[i]<<" ";
    }
}