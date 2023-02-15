#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;/*  
任务核心：写一个哈夫曼树，存储报文


*/

//写一个链表，按照递减的顺序存储数据
typedef struct No_de {
    char name;
    int val;
    struct No_de* next;
    //得修改当前的结构
    struct No_de* parents = NULL;
    struct No_de* lchild = NULL;
    struct No_de* rchild = NULL;
}Node, * PNode;
typedef struct li_st {
    PNode head;
    PNode tail;
    int length = 0;
}LinkList, * PLinkList;

typedef struct Pa_th {
    char road[105];
    int length = 0;
}Path;


void add_small(PLinkList p, PNode s);
void Prin(PLinkList p);
void Prin_mid(PNode Proot);
void delete_list(PLinkList p);
Node huffmantree(PLinkList p);
void search(PNode Proot, char aim, PNode origin);

Path res[200];

int main() {
    //使用链表完成数据的初始化工作
    int n, i, j;
    cin >> n;
    Node data[105];
    for (i = 1; i <= n; i++) {
        cin >> data[i].name;
    }
    for (i = 1; i <= n; i++) {
        cin >> data[i].val;
    }
    char s[105]; int sym[105] = { 0 };
    cin >> s;
    LinkList p; p.head = 0; p.tail = 0;
    for (i = 1; i <= n; i++) {
        add_small(&p, &data[i]);
    }

    //哈夫曼树的建立
    Node HUF = huffmantree(&p);
    //考虑转码
    for (i = 0; i <= strlen(s) - 1; i++) {
        if (sym[s[i]] == 0) {
            search(&HUF, s[i], &HUF);
            sym[s[i]] = 1;
        }
        else if (sym[s[i]] == 1) {
        }
    }
    int h = 0; char final[1010];//把输出的字码储存起来
    for (i = 0; i <= strlen(s) - 1; i++) {
        for (j = 0; j <= res[s[i]].length - 1; j++) {
            //令人感叹，这里char会转化成整形
            cout << res[s[i]].road[j]+'0'-48;
            final[h++] = res[s[i]].road[j];
        }
    }
    cout << endl;
    //编译码
    PNode ant = &HUF;
    //左0右1
    for (i =0; i <= h-1; i++) {
        if (final[i] == 1) {
            ant = ant->rchild;
        }
        else if (final[i] == 0) {
            ant = ant->lchild;
        }
        if (ant->lchild == NULL || ant->rchild == NULL) {
            cout << ant->name;
            ant = &HUF;
        }
    }
    cout << endl;


    return 0;
}
/*
5
a b c d e 12 40 15 8 25
bbbaddeccbbb

00011111110111010110110000
bbbaddeccbbb
*/
/*
8
a b c d e f g h
5 25 3 6 10 11 36 4
bbdahhgfffe
10 10 0101 0100 0001000111 011 011 011 001
为什么会不一样呢
10 10 0111 0110 0001000111 010 010 010 001
bbdahhgfffe
*//*
*/
//打印我们所建立的链表，检查是否正确
void Prin(PLinkList p) {
    PNode Ptemp = p->head;
    while (Ptemp) {
        cout << Ptemp->name << "-" << Ptemp->val << " ";
        Ptemp = Ptemp->next;
    }
    cout << endl;
}
//打印哈夫曼树，检查我们建立的是否正确
void Prin_mid(PNode Proot) {
    if (Proot) {
        if (Proot->name != 0) {
            cout << Proot->name << "-" << Proot->val << " ";
        }
        else cout << "# ";
        Prin_mid(Proot->lchild);
        Prin_mid(Proot->rchild);
    }
}
//直接引用指针,而非再次赋值
void add_small(PLinkList p, PNode Ptemp) {

    if (p->head == NULL) {
        p->head = Ptemp;
        Ptemp->next = NULL;//最后居然是这一行没写上
        p->tail = p->head;
    }
    else if (Ptemp->val > p->head->val) {
        Ptemp->next = p->head;
        p->head = Ptemp;
    }
    else {
        PNode Pt1 = p->head; PNode Pt2 = Pt1;
        while (Pt1 && Pt1->val >= Ptemp->val) {
            Pt2 = Pt1;
            Pt1 = Pt1->next;
        }
        if (Pt1 == NULL) {
            p->tail->next = Ptemp;
            Ptemp->next = NULL;
            p->tail = Ptemp;
        }
        else {
            Ptemp->next = Pt1;
            Pt2->next = Ptemp;
        }
    }
    p->length++;
}
void delete_list(PLinkList p) {
    if (p->head == 0) { ; }
    else if (p->head == p->tail) {
       // free(p->head);
        p->head = NULL;
    }
    else {
        PNode Ptemp = p->head;
        while (Ptemp->next != p->tail) {
            Ptemp = Ptemp->next;
        }
        //free(p->tail);
        Ptemp->next = NULL;
        p->tail = Ptemp;
    }
    p->length--;
}


Node huffmantree(PLinkList p) {
    PNode Pres=(PNode)malloc(sizeof(Node));
    while (p->length > 1) {
        PNode Ptemp1 = (PNode)malloc(sizeof(Node));
        PNode Ptemp2 = (PNode)malloc(sizeof(Node));
        PNode Ptemp3 = (PNode)malloc(sizeof(Node));
        //*Ptemp1=*(p->tail) 这两者的区别在哪里？
        Ptemp1 = (p->tail);
        //Ptemp1->rchild=NULL;Ptemp1->lchild=NULL;
        Ptemp1->parents = Ptemp3;

        delete_list(p);

        Ptemp2 = (p->tail);
        //Ptemp2->rchild=NULL;Ptemp2->lchild=NULL;
        Ptemp2->parents = Ptemp3;

        delete_list(p);

        Ptemp3->name = 0; Ptemp3->val = Ptemp1->val + Ptemp2->val;
        Ptemp3->rchild = Ptemp2; Ptemp3->lchild = Ptemp1;

        add_small(p, Ptemp3);
        Pres = Ptemp3;
    }

    return *Pres;
}
//搜索所有需要出现的路径
void search(PNode Proot, char aim, PNode origin) {
    if (Proot) {
        if (Proot->name == aim) {//开始回溯
            char zimu = Proot->name;
            char temp[105]; int i = 0;
            while (1) {
                PNode Ptemp = Proot;
                Proot = Proot->parents;//parents指针
                //我的parents指针建立有问题
                if (Proot->lchild == Ptemp) {
                    temp[i++] = 0;
                }
                else temp[i++] = 1;
                if (Proot->val== origin->val) break;//为啥这俩不一样呢？
            }
            int h = 0;
            res[zimu].length = i;
            while (i >= 1) {
                res[zimu].road[h++] = temp[--i];
            }

        }
        else {
            search(Proot->lchild, aim, origin);
            search(Proot->rchild, aim, origin);
        }
    }
}