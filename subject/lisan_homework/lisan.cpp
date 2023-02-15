#include <iostream>
#include <fstream>
#include <string>
using namespace std;
# define MAX 1<<20;
# define POS_NUM 29
/*离散数学大作业
目标：从西安到苏州 从所挑选的城市中选择一条最短的路线。

*/
/*
西安 铜川 渭南 商洛 安康 南阳 郑州 焦作 开封 许昌 驻马店 毫州 商丘 阜阳 蚌埠 宿州 杭州 宿迁 盐城 泰州 南京 常州 嘉兴 杭州 芜湖 合肥 宣城 苏州            阜阳 蚌埠 宿州 杭州 宿迁 盐城 泰州 南京 常州 嘉兴 杭州 芜湖 合肥 宣城 苏州
1      2     3      4      5      6     7      8      9      10    11      12    13   14    15    16    17   18    19    20   21   22    23    24   25     26   27    28
*/

typedef struct Ma_p {
    int flag[101] = { 0 };
    int num = 0;
    double arc[101][101];
}Mymap, * PMymap;


//图的创建
void create_graph(Mymap& G);
//输出图
void Prin_map(Mymap G);
//计算
void Dijkstra(Mymap G, int v0,double* dist,int *prevex);


int main() {
    char City[][20]={"none","Xian","TongChuan","Weinan","Shangluo","Ankang","Nanyang","Zhengzhou","Jiaozuo","Kaifeng","Xuchang","Zhumadian","Haozhou","Shangqiu","Fuyang","Bengbu","Su__zhou","Hangzhou","Suqian","Yancheng","Taizhou","Nanjing","Changzhou","Jiaxing","Hangzhou","Wuhu","Hefei","Xuancheng","Suzhou"};
    int n;
    Mymap G;
    create_graph(G);
    double dist[101] = { 0 };
    for(int m=0;m<=100;m++){
        dist[m]=0;
    }
    int prevex[101]={0};
    int a=1,b=28;
    Dijkstra(G,a,dist,prevex);
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
    double sum_test=0;
    for(int i=h-1;i>=0;i--){
        cout<<final[i]<<" ";
    }
    cout<<b<<endl;
    for(int i=h-1;i>=0;i--){
        if(i!=0){
            cout<<G.arc[final[i]][final[i-1]]<<" ";
            sum_test+=G.arc[final[i]][final[i-1]];
        }
    }
    cout<<G.arc[final[0]][b]<<endl;
    sum_test+=G.arc[final[0]][b];
    cout<<"sum_test="<<sum_test<<endl;

    
    for(int i=h-1;i>=0;i--){
        //cout<<final[i]<<" ";
        cout<<City[final[i]]<<" ";
    }
    cout<<City[b]<<endl;
    cout<<"The distance Xian to Suzhou = "<<dist[28]<<endl;
    system("pause");
    return 0;
}

//v0是起点,prevex是最短路径下的，某个点的前置结点
void Dijkstra(Mymap G, int v0,double dist[],int * prevex) {
    G.flag[v0] = 1;
    int i = 0; int My_min = 1<<20, pos =0;
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

            if (G.arc[pos][i] != (1<<20) &&(dist[i] > dist[pos] + G.arc[pos][i])) {
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
    G.num=POS_NUM;
    int i, j;
    for (i = 0; i <= G.num - 1; i++) {
        for (j = 0; j <= G.num - 1; j++) {
            G.arc[i][j]=MAX;
        }
    }
    ifstream fin("data.txt");
    int a,b;
    double num;
    while(fin>>a>>b>>num){
        G.arc[a][b]=num;
        G.arc[b][a]=num;
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