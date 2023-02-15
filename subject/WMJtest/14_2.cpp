#include <iostream>
#include <queue>
/*
利用队列实现广度优先搜索 
*/

//"@" 代表道路，"a" 代表公主，"r" 代表骑士，"x" 代表守卫, "#" 代表墙壁。
using namespace std;
typedef struct No_de{
    int x,y;
}Node;
Node r,a;//a公主，r骑士
queue <Node> s;
char data[210][210];
bool visit[210][210]={0};//标志数组
int step[210][210]={0};
int m,n;

int main(){

    cin>>m>>n;
    int i,j,k;int num=0;
    // 图的读入
    for(i=0;i<=m-1;i++){
        cin>>data[i];
    }
    for(i=0;i<=m-1;i++){
        for(j=0;j<=n-1;j++){
            if(data[i][j]=='a'){//寻找公主
                a.x=i;
                a.y=j;
            }
            if(data[i][j]=='r'){//寻找骑士
                r.x=i;
                r.y=j;
            }
        }
    }
    s.push(r);//把骑士r入栈
    visit[r.x][r.y]=1;
    int expand[4][2]={-1,0,0,1,+1,0,0,-1};//便于扩散
    int flag=0;//记得修改flag
    Node temp;//temp用来临时存放一个坐标
    Node res;

    //考虑，这是路最近的写法，题目要求的是消耗体力最少的写法
    while(1){
        Node t;
        if(!s.empty()){
            t=s.front();//栈首元素拿出来
            s.pop();//不能忘记弹出
        }else{
            break;
        }
        //检查四个方向的结点
        for(k=0;k<=3;k++){
            //temp记录发散的结点
            temp.x=t.x+expand[k][0];
            temp.y=t.y+expand[k][1];
            char L=data[temp.x][temp.y];
            //这个临时性可能有发散意义的结点是否有效以及是否被访问
            //标志数组好像用处不大了
            if(0<=temp.x&&temp.x<=m-1&&temp.y>=0&&temp.y<=n-1&&(visit[temp.x][temp.y]==0)){
            //if(0<=temp.x&&temp.x<=m-1&&temp.y>=0&&temp.y<=n-1&&(visit[temp.x][temp.y]==0||step[t.x][t.y]<step[temp.x][temp.y]-1)){//检查发散的结点是否合法
                if(L=='@'){
                    step[temp.x][temp.y]=step[t.x][t.y]+1;
                    visit[temp.x][temp.y]=1;
                    s.push(temp);
                }else if(L=='#'){
                    //此路不通
                }else if(L=='x'){
                    step[temp.x][temp.y]=step[t.x][t.y]+2;
                    visit[temp.x][temp.y]=1;
                    s.push(temp);
                }else if(L=='a'){
                    step[temp.x][temp.y]=step[t.x][t.y]+1;
                    flag++;
                    res=temp;
                    if(flag==1)break;
                }
            }
        }
            
        if(flag>=10||s.empty()){
            break;
        }
        //是否有一些东西是无论合法与不合法都要做的？
        
    }
    if(flag){
        //最后为啥有问题呢，我没有修改输出内容的位置
        cout<<step[res.x][res.y]<<endl;
    }else{
        cout<<"Impossible"<<endl;
    }

    return 0;
}
/*
4 4
ra##
@@@@
@@##
@@##
*/