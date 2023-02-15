#include <iostream>

using namespace std;
/*任务：实现迪杰斯特拉算法求图的最短路径 Dijkstra
思路来源的文章：
http://c.biancheng.net/algorithm/dijkstra.html
这个代码是我根据他的图简单模仿出来的做法，可能不是很完美,学习一下其他的做法
1.关于路径回溯的问题：void Dijkstra_minTree(MGraph G, int v0, int p[V], int D[V]),解决的很漂亮


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
void Dijkstra(Mymap G, int* dist);
//这算写法是从网上找的，写法大同小异
//void Dijkstra_minTree(MGraph G, int v0, int p[V], int D[V]);

int main() {
    int n;
    Mymap G;
    create_graph(G);
    int dist[101] = { 0 };
    //Prin_map(G);
    Dijkstra(G, dist);
    for (int i = 0; i <= G.num - 1; i++) {
        cout << dist[i] << endl;
    }


    return 0;
}
/*数据
6
0 1 4 10000 10000 10000
1 0 2 7 5 10000
4 2 0 10000 1 10000
10000 7 10000 0 3 2
10000 5 1 3 0 6
10000 10000 10000 2 6 0
*/
//0 1 3 7 4 9

void Dijkstra(Mymap G, int dist[]) {
    G.flag[0] = 1;
    int i = 0; int My_min = 10000, pos =0;
    //初始化
    for (i = 0; i <= G.num - 1; i++) {
        //dist i表示0到i的最短路径
        dist[i] = G.arc[0][i];
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
/*
void Dijkstra_minTree(MGraph G, int v0, int p[V], int D[V]) {
    int final[V];//为各个顶点配置一个标记值，用于确认该顶点是否已经找到最短路径
    //对各数组进行初始化
    for (int v = 0; v < G.vexnum; v++) {
        final[v] = 0;
        D[v] = G.arcs[v0][v];
        p[v] = 0;
    }
    //由于以v0位下标的顶点为起始点，所以不用再判断
    D[v0] = 0;
    final[v0] = 1;
    int k = 0;
    for (int i = 0; i < G.vexnum; i++) {
        int min = 10000;
        //选择到各顶点权值最小的顶点，即为本次能确定最短路径的顶点
        for (int w = 0; w < G.vexnum; w++) {
            if (!final[w]) {
                if (D[w] < min) {
                    k = w;
                    min = D[w];
                }
            }
        }
        //设置该顶点的标志位为1，避免下次重复判断
        final[k] = 1;
        //对v0到各顶点的权值进行更新
        for (int w = 0; w < G.vexnum; w++) {
            if (!final[w] && (min + G.arcs[k][w] < D[w])) {
                D[w] = min + G.arcs[k][w];
///////////////////////////////////////////////////////////////////////////////////
                //这个地方思路好，每个结点只需要记录他所在最短路径的上一个结点即可
                p[w] = k;//记录各个最短路径上存在的顶点
            }
        }
    }
}
*/

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