#include<iostream>
using namespace std;
/*01迷宫 bfs 解决问题




*/
char map[1001][1001];
int n,m,sx,sy,book[1001][1001],next[4][2]={1,0,0,1,-1,0,0,-1};
struct p1141{int x,y;}p[1000001];
void bfs(int x,int y)//基本的bfs，可以不用函数，个人习惯
{
    //内部循环实现bfs,这里相当于初始化循环的初始条件
	int ans=1,h=0,t=1,tx,ty;
	p[h].x=x;
	p[h].y=y;
	book[x][y]=1;
    //h,当前正在展开的节点的在p中的序号，t，h
	while(h<t)
	{
		for(int k=0;k<=3;k++)
		{
			tx=p[h].x+next[k][0];
			ty=p[h].y+next[k][1];
			if(tx<1||ty<1||tx>n||ty>n||book[tx][ty]!=0||map[p[h].x][p[h].y]==map[tx][ty]) continue;
			p[t].x=tx;
			p[t].y=ty;
			book[tx][ty]=1;
			ans++;
			t++;
		}
		h++;
	}
    //
	for(int j=0;j<t;j++)//将队列中的所有联通块染色，我原来写成j<=t了，所以就WA了。。。
	    book[p[j].x][p[j].y]=ans;
	return;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		    cin>>map[i][j];//读图
	for(int i=1;i<=m;i++)
	{
	    cin>>sx>>sy;//询问
		if(book[sx][sy]!=0) cout<<book[sx][sy]<<endl;//如果是查找过的联通块就直接输出
		else 
		{
			bfs(sx,sy);
			cout<<book[sx][sy]<<endl;
		}
	}
	return 0;
}