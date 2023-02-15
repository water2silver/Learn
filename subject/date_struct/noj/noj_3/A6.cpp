#include <iostream>
using namespace std;
/*十字链表 乘法

*/
typedef int ElemType;
typedef struct OL_Node
{
    int  i, j;
    ElemType  elem;
    struct OL_Node* right, * down;
}OLNode, * OLink;

typedef struct Cross_List
{
    OLink* rHead, * cHead;
    int  mu, nu, length;
}CrossList, * PCrossList;

//打印
void Prin(CrossList m);

//在十字链表中加入一个节点
void add_node(CrossList* final, OLink Ptemp);//给十字链表单独加入一个节点

//初始化一个十字链表
void Init_new(CrossList* final);//单个十字链表初始化

//读入，创建链表
void putIn(CrossList* m1, CrossList* m2);

//十字链表相乘
void mul_cross(CrossList m1, CrossList m2, CrossList* final);

int main() {
    CrossList m1, m2, final;
    putIn(&m1, &m2);

    //final的初始化要根据两次m和n
    //Init_new(&final);
    final.mu = m1.mu;
    final.nu = m2.nu;

    Init_new(&final);
    mul_cross(m1, m2, &final);//在这个函数内部 RE了

    Prin(final);
    
    return 0;
}

void putIn(CrossList* m1, CrossList* m2) {
    int m, n;
    int a, b, c;
    cin >> m >> n;
    m1->mu = m; m1->nu = n;
    Init_new(m1);
    while (1) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) {
            break;
        }
        else {
            OLink Ptemp = (OLink)malloc(sizeof(OLNode));
            Ptemp->i = a; Ptemp->j = b; Ptemp->elem = c;
            add_node(m1, Ptemp);
        }
    }
    cin >> m >> n;
    m2->mu = m; m2->nu = n;
    Init_new(m2);
    while (1) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) {
            break;
        }
        else {
            OLink Ptemp = (OLink)malloc(sizeof(OLNode));
            Ptemp->i = a; Ptemp->j = b; Ptemp->elem = c;
            add_node(m2, Ptemp);
        }
    }
}

void mul_cross(CrossList m1, CrossList m2, CrossList* final) {
    int i, j; int res = 0;
    for (i = 1; i <= final->mu; i++) {
        for (j = 1; j <= final->nu; j++) {
            OLink rPtemp = m1.rHead[i];
            OLink cPtemp = m2.cHead[j];
            int temp = 0;
            while (1) {//注意循环结束条件

                if (rPtemp == 0 || cPtemp == 0) {
                    break;
                }
                //此处，没有检查rPtemp cPtemp 的合法性
                if (rPtemp->j == cPtemp->i) {
                    temp = (rPtemp->elem) * (cPtemp->elem);
                    res += temp; temp = 0;
                    rPtemp = rPtemp->right;
                    cPtemp = cPtemp->down;
                }
                else if (rPtemp->j > cPtemp->i) {
                    cPtemp = cPtemp->down;
                }
                else if (rPtemp->j < cPtemp->i) {
                    rPtemp = rPtemp->right;
                }
                //此处，放到while的头部更加合适
                if (rPtemp == 0 || cPtemp == 0) {
                    break;
                }
            }
            if (res != 0) {
                OLink Newnode = (OLink)malloc(sizeof(OLNode));
                Newnode->elem = res; res = 0;
                Newnode->i = i; Newnode->j = j;
                add_node(final, Newnode);//这里应该没啥问题
            }
        }
    }
}

void Init_new(CrossList* final) {
    int m, n;
    m = final->mu; n = final->nu;
    //这样的初始化方式，避免了一次性申请很大的空间
    final->rHead = (OLink*)malloc((m + 1) * sizeof(OLink));
    final->cHead = (OLink*)malloc((n + 1) * sizeof(OLink));
    for (int i = 0; i <= m; i++) {
        final->rHead[i] = 0;
    }
    for (int i = 0; i <= n; i++) {
        final->cHead[i] = 0;
    }
}

void add_node(CrossList* final, OLink Ptemp) {
    //Ptemp是什么？是指针,其本身存储的位置并不重要，重要的时候他所存储的地址
    //
    int a, b, c;
    a = Ptemp->i; b = Ptemp->j; c = Ptemp->elem;
    {
        if (final->rHead[a] == NULL || final->rHead[a]->j > b) {
            Ptemp->right = final->rHead[a]; final->rHead[a] = Ptemp;
        }
        else {
            OLink Q = final->rHead[a];
            while ((Q->right) && Q->j < b) {
                Q = Q->right;
            }
            Ptemp->right = Q->right;
            Q->right = Ptemp;
        }
        //完成列的插入
        if (final->cHead[b] == NULL || final->cHead[b]->i > a) {//why ?
            Ptemp->down = final->cHead[b]; final->cHead[b] = Ptemp;
        }
        else {
            OLink Q = final->cHead[b];
            while ((Q->down) && Q->i < a) {
                Q = Q->down;
            }
            Ptemp->down = Q->down;
            Q->down = Ptemp;
        }
    }

}


void Prin(CrossList m) {
    int i = 0;
    for (i = 1; i <= m.mu; i++) {
        OLink Ptemp = m.rHead[i];
        while (m.rHead[i]) {
            cout << Ptemp->i << " " << Ptemp->j << " " << Ptemp->elem << endl;
            if (Ptemp->right != NULL) Ptemp = Ptemp->right;
            else break;
        }
    }
}
/*部分测试数据*/
/*
    3 3
    1 1 1
    2 2 2
    2 3 4
    3 1 -4
    0 0 0
    3 3
    1 3 -2
    2 3 -5
    3 1 8
    3 2 -6
    0 0 0
    */
    /*第二组数据
    3 2
    1 1 1
    2 1 1
    2 2 1
    3 1 2
    0 0 0
    2 3
    1 1 1
    1 2 2
    1 3 5
    2 1 3
    2 2 4
    2 3 6
    0 0 0

    */

    /*

    1 3
    1 1 1
    1 2 1
    1 3 1
    0 0 0
    3 1
    1 1 1
    2 1 2
    3 1 3
    0 0 0
    1 1 6*/
    /*让我找到问题的数据
    3 3
    1 1 1
    0 0 0
    3 3
    1 1 2
    1 2 2


    */