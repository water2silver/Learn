#include <iostream>

using namespace std;
/*目标:二叉排序树*/
typedef char DataType;
//定义节点
typedef struct No_de {
    DataType data;
    int val;
    struct No_de* parent;
    struct No_de* rchild;
    struct No_de* lchild;
}Node, * PNode;

typedef struct B_T {
    int num = 0;
    PNode root=NULL;
}BinaryTree, * PBinaryTree;
//初始化二叉排序树
void Init(BinaryTree* BT);
//给二叉排序树增加一个结点
void insert_BT(BinaryTree* BT, PNode node);
//读入数据，初始化树
void input_BT(BinaryTree* BT);
//中序遍历,可以根据输入内容改变输出的子树
void inorder(PNode node);
int main() {
    BinaryTree BT;
    Init(&BT);
    input_BT(&BT);

    return 0;
}
void Init(BinaryTree* BT) {
    BT = (BinaryTree*)malloc(sizeof(BinaryTree));
    BT->num = 0;
    BT->root = NULL;
}
void insert_BT(BinaryTree* BT, PNode node) {
    //由插入函数保证node的合理性还是使用的时候就得保证合理性？
    //考虑到插入的结点未必是单一的结点,在使用的时候保证他的合理性
    if (BT->root == NULL) {
        BT->root = node;
    }
    else {
        PNode temp = BT->root;
        while (temp) {
            if (node->val < temp->val) {
                if (temp->lchild == NULL) {
                    temp->lchild = node;
                    break;
                }
                else {
                    temp = temp->lchild;
                }
            }
            else {
                if (temp->rchild == NULL) {
                    temp->rchild = node;
                    break;
                }
                else {
                    temp = temp->rchild;
                }
            }            
        }

    }
    BT->num++;
}
//8 1 2 3 4 5 6 7 8
void input_BT(BinaryTree* BT) {
    int n;//节点数目
    cin >> n;
    int a;

    for (int i = 0; i <= n - 1; i++) {
        cin >> a;
        PNode temp = (PNode)malloc(sizeof(Node));
        //初始化结点
        temp->lchild = NULL; temp->rchild = NULL;
        temp->val =a;
        insert_BT(BT, temp);
    }
}

void inorder(PNode node) {
    if (node) {

        cout << node->val << " ";
       // printf("\n%p %p", node->lchild,node->rchild);
        inorder(node->lchild);
        inorder(node->rchild);
    }
}