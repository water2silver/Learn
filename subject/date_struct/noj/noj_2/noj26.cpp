#include<iostream>

using namespace std;
/*归并两个二叉排序树
难度不大
*/
typedef struct no_de{
    int data;
    struct no_de* lchild;
    struct no_de* rchild;
}Node;
typedef Node* PNode;

//采用递归的方式，创建二叉排序树，优点：递归结束，树的建立自然结束
void create_l(PNode& p);
//按照中序遍历的方式输出树
void Prin(PNode p);
//归并两棵树，单实际上第二棵树并没有被归并到第一棵树上，额外创造了多个节点
void and_two(PNode head,PNode p);
//把某个元素插入到排序二叉树上
void Myadd(PNode head,int data);

//最好是递归建立二叉排序树
int main(){
    PNode head;PNode head2;
    head=(PNode)malloc(sizeof(Node));
    create_l(head);
    head2=(PNode)malloc(sizeof(Node));
    create_l(head2)
    PNode temp=head2;
    and_two(head,head2);
    Prin(head);
/*
12 8 4 -1 -1 10 -1 -1 16 13 -1 -1 18 -1 -1
17 6 2 -1 -1 9 -1 -1 24 19 -1 -1 26 -1 -1
*/
}
void and_two(PNode head,PNode p){
    if(head!=NULL)
        Myadd(head,p->data);
    if(p->lchild!=NULL){
        and_two(head,p->lchild);
    }
    if(p->rchild!=NULL){
        and_two(head,p->rchild);
    }
}


void Myadd(PNode head,int data){
    PNode temp=head;
    if(data>temp->data){
        if(head->rchild==NULL){
            PNode Ptemp=(PNode)malloc(sizeof(Node));
            Ptemp->data=data;
            Ptemp->lchild=NULL;Ptemp->rchild=NULL;
            head->rchild=Ptemp;
        }else{
            Myadd(head->rchild,data);
        }
    }else if(data<temp->data){
        if(head->lchild==NULL){
            PNode Ptemp=(PNode)malloc(sizeof(Node));
            Ptemp->data=data;
            Ptemp->lchild=NULL;Ptemp->rchild=NULL;
            head->lchild=Ptemp;
        }else{
            Myadd(head->lchild,data);
        }

    }
}


void Prin(PNode p){
    if(p!=NULL){
        PNode temp=p;
        
        Prin(p->lchild);
        cout<<p->data<<" ";
        Prin(p->rchild);
    }
}
// 12 8 4 -1 -1 10 -1 -1 16 13 -1 -1 18 -1 -1


void create_l(PNode& p){
    //p进入函数的时候就是合理的
    //
    int temp;
    cin>>temp;
    if(temp!=-1){
        p->data=temp;
        p->lchild=(PNode)malloc(sizeof(Node));
        p->rchild=(PNode)malloc(sizeof(Node));
        create_l(p->lchild);
        create_l(p->rchild);
    }else{
        p=NULL;
    }
}