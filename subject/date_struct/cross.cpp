#include <iostream>
using namespace std;

/*稀疏矩阵
1.普通的
2.十字链表
3.广义表（再一层的抽象？）


十字链表
1.每行的第一个元素的节点
2.每行的最后一个元素的节点


函数内容：
1.加法（减法）
2.乘法

辅助函数：
1.判断某个位置是否有非零元素


*/

typedef struct OL_node{
    int row,int col;
    int data;
    struct OL_node *right,*down;
}OLnode,*POLnode;
typedef struct {
    POLnode r[1000];c[2000];
    int mu,nu,tu;
}crosslist;


int main(){

    return 0;
}