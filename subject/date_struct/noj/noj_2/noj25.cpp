#include<iostream>

using namespace std;
/*二叉排序树的打印，插入，删除
难点：删除
1.删除的节点既没有左子树也没有右子树，直接删除即可
2.既有左子树，又有右子树，

这个题目比较坑的地方，在删除节点操作的时候，是不能考虑上面加入的那个节点的
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
void limit_Prin(PNode head,int low,int upper);
void Myadd(PNode head,int data);
void delete_Prin(PNode p,int b,int a);

//最好是递归建立二叉排序树
int main(){
    PNode head;
    head=(PNode)malloc(sizeof(Node));
    create_l(head);
    int low,upper;
    cin>>low>>upper;
    
    int a,b;
    cin>>a>>b;
    limit_Prin(head,low,upper);
    cout<<endl;
    Myadd(head,a);
    Prin(head);
    cout<<endl;
    delete_Prin(head,b,a);
    return 0;
/* 12 8 4 -1 -1 10 -1 -1 16 13 -1 -1 18 -1 -1
10 17
6 12
    */
}
void delete_Prin(PNode p,int b,int a){
     if(p!=NULL){
        PNode temp=p;
        
        delete_Prin(p->lchild,b,a);
        if(p->data!=b&&p->data!=a)
            cout<<p->data<<" ";
        delete_Prin(p->rchild,b,a);
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

void limit_Prin(PNode head,int low,int upper){
    if(head!=NULL){
        limit_Prin(head->lchild,low,upper);
        if(head->data>low&&head->data<upper){
            cout<<head->data<<" ";
        }
        limit_Prin(head->rchild,low,upper);
    }
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
        
        Prin(p->lchild);
        cout<<p->data<<" ";
        Prin(p->rchild);
    }
}



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