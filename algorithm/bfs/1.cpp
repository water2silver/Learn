#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
/*
洛谷：01迷宫

*/

using namespace std;
bool s[1010][1010]={0};
int m,n;//全局变量？ 
int res=0;//
bool t[1010][1010]={0};


typedef struct node{
    int x,y;
}node;
queue<node> q;
void bfs(int a,int b);

int main(){
    int i,j,a,b;
    cin>>n>>m;
    //读入
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            char c=getchar();
            if(c!='0'&&c!='1') c=getchar();//输入有效
            if(c!='0'&&c!='1') c=getchar();//输入有效
            if(c!='0'&&c!='1') c=getchar();//输入有效

            s[i][j]=c-'0';
        }
    }
    //
    int final[100010];int h=0;
    for(i=1;i<=m;i++){
        node temp;
        //
        res=0;
        scanf("%d %d",&temp.x,&temp.y);
        memset(t,0,sizeof(t));
        bfs(temp.x,temp.y);
        final[h++]=res-1;
    }
    
    for(i=0;i<=h-1;i++){
        cout<<final[i]<<endl;
    }

    return 0;
}
void bfs(int a,int b){
    
    if(a>=1&&a<=n&&b<=n&&b>=1){//判断是否合法

        //res++放到哪里更合适？
        res++;
        node temp1,temp2,temp3,temp4;

        //四个if是什么，判断某个点周围的点是否有资格进入栈
        if((s[a+1][b]!=s[a][b])&&t[a+1][b]==0){
            temp1.x=a+1;temp1.y=b;
            q.push(temp1);
            t[a+1][b]=1;
            
        }
        if((s[a-1][b]!=s[a][b])&&t[a-1][b]==0){
            temp2.x=a-1;temp2.y=b;
            q.push(temp2);
            t[a-1][b]=1;
            
        }
        if((s[a][b+1]!=s[a][b])&&t[a][b+1]==0){
            temp3.x=a;temp3.y=b+1;
            q.push(temp3);
            t[a][b+1]=1;

        }
        if((s[a][b-1]!=s[a][b])&&t[a][b-1]==0){
            temp4.x=a;temp4.y=b-1;
            q.push(temp4);
            t[a][b-1]=1;

        }
    }
    if(q.empty()!=1){
        node w=q.front();q.pop();
        bfs(w.x,w.y);
    }
}