#include<bits/stdc++.h>
using namespace std;
/*bfs实例1
针对问题：从迷宫的某个点到另一处，1表示可走，0表示不可走
实现特点：
1.改实现采用了while循环与queue队列
2.可记录过程中到达每个点的最小步数
3.貌似回溯路径会比较困难
思路：
1.初始化，将起始点入栈
2.过程：（每次循环开始检查合法性）将栈中的头点进行遍历展开，依次入队
3.while结束条件 找到目标点或者队列为空,设置标志位检查

*/
int a[100][100];//a[i][j]=1表示是空地可以走，为0表示不是空地
int v[100][100];//v[i][j]=1表示已经被访问了，为0表示未被访问

struct point{
	int x;
	int y;
	int step;//每一个point的step表示从某个点到达此处所需要的步数
};
queue<point> r;//用队列存储将来要访问的节点

//如何比较便捷地访问 右下左上四个点
int dx[4]={0,1,0,-1}; //left;down;right;up
int dy[4]={1,0,-1,0};

int m,n;

int main() {
	//input
	int n,m,startx,starty,p,q;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d%d%d%d",&startx,&starty,&p,&q);

	//BFS
	point start;
	//初始化开始 
	start.x = startx;
	start.y = starty;
	start.step = 0;
	//初始化结束
	r.push(start);//将起点入队 
	v[startx][starty] = 1 ;
	
	int flag = 0;

	while(!r.empty()){//不为空，循环进行广度搜索
    //每次while循环，拓展一个节点
        int x = r.front().x;
		int y = r.front().y;
		if(x==p && y==q){// arrive destinationa 
			flag = 1;
			cout<<r.front().step;
			break;
		}

		//for循环实现右下左上地遍历
        //这个地方需要注意对于数组越界的检查
		for(int k = 0 ; k < 3 ; k++){
			int tx,ty;
			tx = x + dx[k];
			ty = y + dy[k];
            //这里必须检查tx，ty的合法性
			if (tx<=n&&tx>=1&&ty>=1&&ty<=m&&a[tx][ty]==1 && v[tx][ty]==0){//如果是空地 并且 未被访问过 
				//入队
				point temp;//把拓展的点放到temp里
				temp.x = tx;
				temp.y = ty;
				temp.step = r.front().step + 1 ;
				r.push(temp);
				v[tx][ty] = 1; //设置为已访问 
			}		
		}
		r.pop();//拓展完了需要将队首元素出队
	}
	if(flag==0)//没找到 
	cout<<"no answer"; 
	return 0;
}/*
5 4 
	1 1 0 1 
	1 1 1 1
	1 1 0 1 
	1 0 1 1 
	1 1 1 0
1 1 4 3
*//*
3 3
1 0 1
1 0 0
1 1 1
1 1 1 3
*/