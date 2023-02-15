#include <stdio.h>
#include <ctype.h>
#define check(x,y) (x>0&&x<=n&&y>0&&y<=n)
#define nx (x+dx[i])
#define ny (y+dy[i]) 
/*dfs
题目：01迷宫
这个问题貌似bfs也能写？既然找到了这个答案，就先记录学习下

知识点：dfs 连通块
相邻的01块，拥有相同的结果，所以考虑 以块为单位，遍历全局，然后输出？

*/
char a[1005][1005]; int f[1005][1005]; bool v[1005][1005];
int n,m,dx[]={1,0,-1,0},dy[]={0,1,0,-1},now;
int ans[1000005][2],Count; //变量定义防止太长压了行
//
void dfs(int x,int y){
    now++;
    //ans的作用是什么？继续now增加时，所走过的每一个块的位置，这些块都有相同的所求结果
    //可以在main函数看到对于ans所记录数据的处理
    ans[now][0]=x,ans[now][1]=y;

    for(int i=0;i<4;i++){
        if(check(nx,ny)&&!v[nx][ny]&&a[x][y]!=a[nx][ny]){
            v[nx][ny]=true;
            dfs(nx,ny);
        }
    }
}
int res;
char ch;
inline int read(){
    res=0;
    while(isspace(ch=getchar()));
    do res=res*10+ch-'0'; while(isdigit(ch=getchar()));
    return res;
}
inline void write(int n){
    if(n==0) return;
    write(n/10);
    putchar(n%10+'0');
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) if(!v[i][j]){
            v[i][j]=true;now=0;
            dfs(i,j);
            for(int i=1;i<=now;i++) f[ans[i][0]][ans[i][1]]=now; 
        }
    register int x,y;
    for(int i=1;i<=m;i++){
        x=read();y=read();
        write(f[x][y]);
        putchar('\n');
    }
    return 0;
} 