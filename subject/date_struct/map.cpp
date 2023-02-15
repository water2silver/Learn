#include <bits/stdc++.h>
using namespace std;
/*图的有关内容
7.2 图的存储结构

1.邻接矩阵表示法
实现：两个数组，一个一维数据存储结点，一个二维数组存储关系


*/
#define MAX_NUMBER 200
typedef enum{DG,DN,UDG,UDN} GraphKind;
typedef struct {

}OtherInfo;
typedef char VertexData;
typedef int AdjType;//似乎是判断元素？
typedef struct ArcNode{
    AdjType adj;//对于弧的赋值
    OtherInfo info;
}ArcNode;//这是弧结点

typedef struct{
    VertexData vertex[MAX_NUMBER];//存放节点
    ArcNode arcs[MAX_NUMBER][MAX_NUMBER];//用二维数组表示弧，出了是否有外，还可以存储别的信息
    int vexnum,arcnum;
    GraphKind kind;
}AdjMatrix;


int main(){



    return 0;
}

int LocateVertex(AdjMatrix *G,VertexData v){

    int i,j=0;
    for(i=0;i<=G->verxnum-1;i++){
        if(G->vertex[i]==v){
            j=i;break;
        }
    }
    return j;//如果没有返回0
}

int CreateGN(AdjMatrix *G){
    //创建图，至少得有结点，以及节点之间的关系
    //便于输入，还最好有结点的数目，关系的数目
    //默认G已经分配好了空间
    cin>>G->arcnum>>G->vexnum;


}