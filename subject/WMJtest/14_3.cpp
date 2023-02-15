#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
#define ll long long
#define mem(s, i) memset(s, i, sizeof(s))
#define INF 0x3f3f3f3f;
using namespace std;
int n, m;
char p[205][205];
int vim[205][205]; 
int a, b;
int d[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};
struct node
{
	int x, y; //点的坐标
	int len;  //起点到该点的距离
}head, tail;
bool check(int x, int y){//判断该点是否在地图范围内且不为城墙
	if(x >= 1&&x <= n&&y >= 1&&y <= m&&p[x][y]!='#')return true;
	return false;
}
void bfs(int xx, int yy, int l)
{
	queue<node> q;
	head.x = xx, head.y = yy, head.len = l;
	vim[xx][yy] = 1;//该点初始都为1
	q.push(head);
	while(!q.empty()){
		tail = q.front();
		q.pop();
		/*这个循环里面我们用的head是之前的head，也就是每次while循环开始时的q的队首
		head元素,而循环内的head我们会重新压入队列给后续while循环使用，直到队空，我
		们bfs每次都是先遍历到离他最近的位置的情况*/
		for(int i = 0;i < 4;i++){
			head.x = tail.x+d[0][i];
			head.y = tail.y+d[1][i];
			if(check(head.x,head.y)){
				if(p[head.x][head.y] == 'x'){//守卫时间需要多+1
					head.len = tail.len+2;
				}
				else{
					head.len = tail.len+1;
				}
				if(vim[head.x][head.y]&&head.len>=vim[head.x][head.y]){
					//如果该点已被计算过并且到这个点的距离比之前记录的要大那么我们就跳过
					continue;
				}
				vim[head.x][head.y] = head.len;//更新时间
				q.push(head);//重新压入队列，以便后续使用
			}
		}
	}
}
void solve()
{
	cin >> n >> m;
	int x, y;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> p[i][j];
			if (p[i][j] == 'r')
				x = i, y = j; // qidian
			if (p[i][j] == 'a')
				a = i, b = j; // zhongdian
		}
	}
	bfs(x, y, 0);//起始时间我们从0开始
	if (vim[a][b])cout<<vim[a][b]<<endl;
	else cout << "Impossible" << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
