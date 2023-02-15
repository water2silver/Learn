#include <iostream>

using namespace std;
/*任务：实现迪杰斯特拉算法求图的最短路径 Dijkstra
思路来源的文章：
http://c.biancheng.net/algorithm/dijkstra.html
这个代码是我根据他的图简单模仿出来的做法，可能不是很完美,学习一下其他的做法
1.关于路径回溯的问题：void Dijkstra_minTree(MGraph G, int v0, int p[V], int D[V]),解决的很漂亮
2.路径回溯的思路在于prevex[]数组的实现

*/
typedef struct Ma_p {
    int flag[101] = { 0 };
    int num = 0;
    int arc[101][101];
}Mymap, * PMymap;


//图的创建
void create_graph(Mymap& G);
//输出图
void Prin_map(Mymap G);
//计算
void Dijkstra(Mymap G, int v0,int* dist,int *prevex);


int main() {
    int n;
    Mymap G;
    create_graph(G);
    int dist[101] = { 0 };
    int prevex[101]={0};
    int a,b;
    cin>>a>>b;
    //Prin_map(G);
    Dijkstra(G,a,dist,prevex);
    // for (int i = 0; i <= G.num - 1; i++) {
    //     cout << dist[i] << endl;
    // }
    int final[101];int h=0;
    int temp=b;
    while(1){
        final[h++]=prevex[temp];
        if(prevex[temp]==a){
            break;
        }else{
            temp=prevex[temp];
        }
    }
    for(int i=h-1;i>=0;i--){
        cout<<final[i]<<endl;
    }
    cout<<b<<endl;


    return 0;
}
/*数据
4
0 2 10 10000
2 0 7 3
10 7 0 6
10000 3 6 0
0 2

*/
//

//v0是起点,prevex是最短路径下的，某个点的前置结点
void Dijkstra(Mymap G, int v0,int dist[],int * prevex) {
    G.flag[v0] = 1;
    int i = 0; int My_min = 10000, pos =0;
    //初始化
    for (i = 0; i <= G.num - 1; i++) {
        //dist i表示0到i的最短路径
        dist[i] = G.arc[v0][i];
        prevex[i]=v0;
        //记录最小的情况
        if (dist[i] < My_min&&dist[i]!=0) {
            My_min = dist[i];
            pos = i;
        }
    }
    G.flag[pos] = 1;//标记为1意味着已经用过了
    //计算
    //n个点,
    for (int k = 1; k <= G.num - 1; k++) {

        My_min = -1; int temp = 0;
        for (i = 0; i <= G.num - 1; i++) {

            if (G.arc[pos][i] != 10000 && dist[i] > dist[pos] + G.arc[pos][i]) {
                dist[i] = dist[pos] + G.arc[pos][i];
                prevex[i]=pos;
            }
        }
        //至此，完成了S集合+点pos的，dist最短路径

        //接下来，寻找下一个要延伸的点
        for (i = 0; i <= G.num - 1; i++) {
            if ((G.flag[i]!=1)&&(My_min==-1)) {
                My_min = dist[i];
                temp = i;
            }
            else if (G.flag[i] != 1 && dist[i] < My_min) {
                My_min = dist[i];
                temp = i;
            }
        }
        G.flag[temp] = 1;
        pos = temp;
    }
}


void create_graph(Mymap& G) {
    cin >> G.num;
    int i, j;
    for (i = 0; i <= G.num - 1; i++) {
        for (j = 0; j <= G.num - 1; j++) {
            cin >> G.arc[i][j];
        }
    }
}
void Prin_map(Mymap G) {
    for (int i = 0; i <= G.num - 1; i++) {
        for (int j = 0; j <= G.num - 1; j++) {
            cout << G.arc[i][j] << " ";
        }
        cout << endl;
    }
}