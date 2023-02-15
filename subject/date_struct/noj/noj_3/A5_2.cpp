#include <iostream>
using namespace std;
/*十字链表，拿下！
这是复杂版的
本次实现：
十字链表的初始化，数据读入，十字链表相加

改了无数bug 终于过了...

*/

typedef int ElemType;

typedef struct OLNode
{
    int  i, j;
    ElemType  elem;
    struct OLNode* right, * down;
}OLNode, * OLink;

typedef struct Cross_List
{
    OLink* rHead, * cHead;
    int  mu, nu, length;
}CrossList, * PCrossList;

void Init_putIn(CrossList* m1, CrossList* m2);//读入数据，并且初始化两个十字链表
void create_crosslist(CrossList* m1, int t1);//被上个函数调用
void Prin(CrossList m);//打印
void add_node(CrossList* final,OLink Ptemp);//给十字链表单独加入一个节点
void add_two_cross(CrossList *m1,CrossList *m2,CrossList *final);//读入
void Init_new(CrossList *final);//单个十字链表初始化

int main() {
    CrossList m1, m2;
    Init(&m1, &m2);
    CrossList final;
    final.mu=m1.mu;final.nu=m2.nu;//尚未对final的length处理
    Init_new(&final);
    add_two_cross(&m1,&m2,&final);
    //cout<<"Start to put out:"<<endl;
    Prin(final);
    return 0;
}
void add_two_cross(CrossList *m1,CrossList *m2,CrossList *final){
    int i=1,j=1;
    for(;;i++,j++){
        //测试点1 通过 第一次就陷入循环里面出不来了= =
        //cout<<"*"<<endl;
        OLink Ptemp1,Ptemp2;
        Ptemp1=m1->rHead[i];
        Ptemp2=m2->rHead[i];

        while(Ptemp1&&Ptemp2){
            //测试点2
            //cout<<"*"<<endl;
            if(Ptemp1->j==Ptemp2->j){

                int temp=Ptemp1->elem+Ptemp2->elem;
                if(temp!=0){
                    OLink Ptemp=(OLink)malloc(sizeof(OLNode));
                    Ptemp->elem=temp;
                    Ptemp->i=Ptemp1->i;Ptemp->j=Ptemp1->j;
                    //插入的时候对于Ptemp的right和down会做处理，且不涉及NULL故此处不做处理
                    //Ptemp->right=NULL;Ptemp->down=NULL;
                    add_node(final,Ptemp);
                    Ptemp1=Ptemp1->right;
                    Ptemp2=Ptemp2->right;
                }
            }else if(Ptemp1->j<Ptemp2->j){
                //Ptemp1小则插入Ptemp1
                OLink Ptemp=(OLink)malloc(sizeof(OLNode));
                Ptemp->elem=Ptemp1->elem;
                Ptemp->i=Ptemp1->i;Ptemp->j=Ptemp1->j;

                add_node(final,Ptemp);
                Ptemp1=Ptemp1->right;
            }else{
                OLink Ptemp=(OLink)malloc(sizeof(OLNode));
                Ptemp->elem=Ptemp2->elem;
                Ptemp->i=Ptemp2->i;Ptemp->j=Ptemp2->j;
                add_node(final,Ptemp);
                Ptemp2=Ptemp2->right;
            }
        }
        //测试点3 程序无法运行至此处

        //cout<<"*"<<endl;
        while(Ptemp1){
            
            OLink Ptemp=(OLink)malloc(sizeof(OLNode));
            Ptemp->elem=Ptemp1->elem;
            Ptemp->i=Ptemp1->i;Ptemp->j=Ptemp1->j;

            add_node(final,Ptemp);
            Ptemp1=Ptemp1->right;
        }
        while(Ptemp2){
            OLink Ptemp=(OLink)malloc(sizeof(OLNode));
            Ptemp->elem=Ptemp2->elem;
            Ptemp->i=Ptemp2->i;Ptemp->j=Ptemp2->j;
            add_node(final,Ptemp);
            Ptemp2=Ptemp2->right;
        }
        if(i==final->mu) break;
    }
}

void Init_new(CrossList *final){
    int m,n;
    m=final->mu;n=final->nu;
    final->rHead = (OLink*)malloc((m + 1) * sizeof(OLink));
    final->cHead = (OLink*)malloc((n + 1) * sizeof(OLink));    
    for (int i = 0; i <= m; i++) {
        final->rHead[i] = 0;
    }
    for (int i = 0; i <= n; i++) {
        final->cHead[i] = 0;
    }
}



void Init(CrossList* m1, CrossList* m2) {
    int m, n, t1, t2;
    cin >> m >> n >> t1 >> t2;
    m1->mu = m; m1->nu = n;
    m2->mu = m; m2->nu = n;
    m1->length = t1;
    m2->length = t2;
    //
    Init_new(m1,m2);
    //这跟数组也没大多区别啊...
    m1->rHead = (OLink*)malloc((m + 1) * sizeof(OLink));
    m1->cHead = (OLink*)malloc((n + 1) * sizeof(OLink));
    m2->rHead = (OLink*)malloc((m + 1) * sizeof(OLink));
    m2->cHead = (OLink*)malloc((n + 1) * sizeof(OLink));

    for (int i = 0; i <= m; i++) {
        m1->rHead[i] = 0;
    }
    for (int i = 0; i <= n; i++) {
        m1->cHead[i] = 0;
    }
    for (int i = 0; i <= m; i++) {
        m2->rHead[i] = 0;
    }
    for (int i = 0; i <= n; i++) {
        m2->cHead[i] = 0;
    }
    create_crosslist(m1, t1);
    create_crosslist(m2, t2);
}



void add_node(CrossList* final,OLink Ptemp){
//Ptemp是什么？是指针,其本身存储的位置并不重要，重要的时候他所存储的地址
//
    int a,b,c;
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
        if (final->cHead[b] == NULL || final->cHead[b]->i > a) {
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






void create_crosslist(CrossList* m1, int t1) {
    int i = 0;
    OLink Ptemp; int a, b, c;
    //Ptemp = new OLNode;
    Ptemp=(OLink)malloc(sizeof(OLNode));
    for (i = 1; i <= t1 ; i++) {//读入之后，进行 行与列 的插入
        Ptemp=(OLink)malloc(sizeof(OLNode));
        cin >> Ptemp->i >> Ptemp->j >> Ptemp->elem;
        a = Ptemp->i; b = Ptemp->j; c = Ptemp->elem;
        ///
        //cout<<"Point of Ptemp= "<<Ptemp<<endl;
        //完成行的插入
        if (m1->rHead[a] == NULL || m1->rHead[a]->j > b) {
            Ptemp->right = m1->rHead[a]; m1->rHead[a] = Ptemp;
        }
        else {
            OLink Q = m1->rHead[a];
            while ((Q->right) && Q->j < b) {
                Q = Q->right;
            }
            Ptemp->right = Q->right;
            Q->right = Ptemp;
        }
        //完成列的插入
        if (m1->cHead[b] == NULL || m1->cHead[b]->i > a) {
            Ptemp->down = m1->cHead[b]; m1->cHead[b] = Ptemp;
        }
        else {
            OLink Q = m1->cHead[b];
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
    for (i = 1; i <= m.mu ; i++) {
        OLink Ptemp = m.rHead[i];
        while (m.rHead[i]) {
            //test
            //cout<<"in Prin "<<endl;
            //printf("%p",m.rHead[i]);
            cout << Ptemp->i << " " << Ptemp->j << " " << Ptemp->elem << endl;
            if (Ptemp->right != NULL) Ptemp = Ptemp->right;
            else break;
        }
    }
}


/*
样例：
3 4 3 2
1 1 1
1 3 1
2 2 2
1 2 1
2 2 3
*/