#include <iostream>
#include <string.h>
#define MAX 200
using namespace std;
/*这是我仿照的noj21_ans所写的，
1.我感觉这个题目最值得学习的地方是处理字符串时候所采用的优先级计算方法，
既实现了对于字符串的全局统筹，又找到了分割字符串构造树的方法，同时经过
我的修改之后，可以消除()。

*/
//构成NewString结点的子节点
typedef struct node {
    int tag = 0;//tag=1,表示符号，0表示参运算的字母
    char elem;//存放具体元素
    int weight;//表示某个运算符的优先级，越高，则先算。对树而言，优先级低的符号应该在上方
}Node;

//NewString是输入字符串进行特殊处理后存储处理信息的结构,主要信息存储在Node中
typedef struct newstring {
    Node data[MAX + 2];
    int length;
}NewString;

//树的结点，改问题的实质是二叉树的后序遍历
typedef struct binTreeNode {
    char elem;
    struct binTreeNode* right, * left;
}BinTreeNode;
//处理字符串
void InitString(NewString* S);
//创建二叉树
void CreateTree(BinTreeNode* T, NewString* S);
//找到优先级最低的运算符的位置 i
int find_min(NewString S);
//后续遍历二叉树
void Output(BinTreeNode* T);

int main() {

    NewString* S;
    S = (NewString*)malloc(sizeof(NewString));
    S->length = 0;
    InitString(S);
    BinTreeNode* T;
    T = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    CreateTree(T, S);
    Output(T);


    return 0;
}


void Output(BinTreeNode* T) {
    if (T == NULL ) {
        return;
    }
    else {
        Output(T->left);
        Output(T->right);
        cout << T->elem;
    }
}


void CreateTree(BinTreeNode* T, NewString* S) {

    //保证T的合法性
    int len, mid;
    if (S->length == 1) {
        T->elem = S->data[0].elem;
        T->left = NULL;
        T->right = NULL;
    }
    else {
        mid = find_min(*S);
        //左右子树，对应字符串申请
        //BinTreeNode *left,*right;
        T->left = (BinTreeNode*)malloc(sizeof(BinTreeNode));//////////
        T->right = (BinTreeNode*)malloc(sizeof(BinTreeNode));

        NewString* Rs, * Ls;
        Rs = (NewString*)malloc(sizeof(NewString));
        Ls = (NewString*)malloc(sizeof(NewString));
        //分割字符串，作为左右子树
        for (int i = 0; i <= mid - 1; i++) {
            Ls->data[i] = S->data[i];
        }
        Ls->length = mid;
        for (int i = mid + 1; i <= S->length - 1; i++) {
            Rs->data[i - mid - 1] = S->data[i];
        }
        Rs->length = S->length - mid - 1;
        //处理当前结点的元素
        T->elem = S->data[mid].elem;
        //处理他的左右节点
        CreateTree(T->left, Ls);
        CreateTree(T->right, Rs);

    }

}
int find_min(NewString S) {
    int temp_min = 999; int pos = 0;
    for (int i = 0; i <= S.length - 1; i++) {
        if (S.data[i].tag == 1 && S.data[i].weight <= temp_min) {
            temp_min = S.data[i].weight;
            pos = i;
        }
    }
    return pos;
}


void InitString(NewString* S) {
    //处理
    //设置h的目的：i遍历str,h用以存储有效的运算符或者字母
    char str[MAX + 2];
    cin >> str;
    int length = strlen(str);
    int baseweight = 0; int other = 0; int h = 0;
    for (int i = 0; i <= length - 1; i++) {
        if (str[i] == '(') {
            baseweight += 2;
            other++;
        }
        else if (str[i] == ')') {
            baseweight += -2;
            other++;
        }
        else if (str[i] == '+' || str[i] == '-') {
            S->data[h].weight = 1 + baseweight;
            S->data[h].elem = str[i];
            S->data[h].tag = 1;
            h++;
        }
        else if (str[i] == '*' || str[i] == '/') {
            S->data[h].weight = 2 + baseweight;
            S->data[h].elem = str[i];
            S->data[h].tag = 1;
            h++;
        }
        else {
            //变量一般会被归到这里
            S->data[h].elem = str[i];
            S->data[h].tag = 0;
            h++;
        }
    }
    //没有把括号赋值过来
    S->length = length - other;
}