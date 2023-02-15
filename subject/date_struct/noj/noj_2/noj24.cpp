#include<iostream>

using namespace std;
/*二叉排序树的判别
实现：利用递归实现对于合理输入，建立二叉排序树
1.Prin中序遍历打印
2.check检查是否为合理的二叉排序树
*/
typedef struct no_de{
    int data;
    struct no_de* lchild;
    struct no_de* rchild;
}Node;
typedef Node* PNode;

void create_l(PNode& p);
void Prin(PNode p);
int check(PNode head);

//最好是递归建立二叉排序树
int main(){
    PNode head;
    head=(PNode)malloc(sizeof(Node));
    create_l(head);
    //Prin(head);
    if(check(head)){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
    return 0;
}
int check(PNode head){
    int res=1;
    if(head!=NULL){
        if(head->lchild!=NULL){
            if(head->lchild->data<head->data){
                res=res&&1;
            }else{
                res=res&&0;
            }
        }
        if(head->rchild!=NULL){
            if(head->rchild->data>head->data){
                res=res&&1;
            }else{
                res=res&&0;
            }
        }
    }else{
        //这个地方不加这个else，可能会出现空指针->空指针的无效死递归。
        return res;
    }
    if(res==1){
        res=check(head->lchild)&&check(head->rchild);
    }
    return res;
}


void Prin(PNode p){
    if(p!=NULL){
        PNode temp=p;
        cout<<p->data<<" ";
        Prin(p->lchild);
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