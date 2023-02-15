#include <bits/stdc++.h>
using namespace std;
/*二叉树的输入与三序遍历

*/

typedef char DataType;

struct bitreenode{
    DataType data;
    struct bitreenode* lchild;
    struct bitreenode* rchild;
};
typedef struct bitreenode bitreenode;
typedef struct bitreenode* Pbitreenode;

Pbitreenode createbitree();
void preorder(Pbitreenode t);
void inorder(Pbitreenode t);
void postorder(Pbitreenode t);
int node_number(Pbitreenode t);
int leaf_number(Pbitreenode t);
Pbitreenode create_second();
//A(B(#,D),C(E(#,F),#))
int main(){
    //建立
    //Pbitreenode t=createbitree();
    //建立2
    Pbitreenode t=create_second();
    //输出
    preorder(t);
    cout<<endl;
    inorder(t);
    cout<<endl;
    //输出数目

//ABD##E##C#F##
    return 0;
} 
Pbitreenode createbitree(){//先序遍历对应的输入法
    DataType temp;
    cin>>temp;
    if(temp=='#'){
        return NULL;
    }else{
        Pbitreenode Ptemp=(Pbitreenode)malloc(sizeof(bitreenode));
        Ptemp->data=temp;
        Ptemp->lchild=createbitree();
        Ptemp->rchild=createbitree();
        return Ptemp;
    }
}
Pbitreenode create_second(){//括号插入法
    DataType ch;
    Pbitreenode Ptemp=(Pbitreenode)malloc(sizeof(bitreenode));
    cin>>ch;
    if(ch==','){//避免),相连的特殊情况
        cin>>ch;
    }
    if(ch=='#') {
        cin>>ch;
        free(Ptemp);
        return NULL;
    }
    else if(ch<='Z'&&ch>='A'){
        Ptemp->data=ch;
        cin>>ch;
        if(ch=='('){
            Ptemp->lchild=create_second();
            Ptemp->rchild=create_second();
        }else if(ch==')'){

        }else if(ch==','){

        }
    }
    return Ptemp;
}

void preorder(Pbitreenode t){
    if(t!=NULL){
        cout<<t->data;
        preorder(t->lchild);
        preorder(t->rchild);
    }
}



void inorder(Pbitreenode t){//中序遍历
    if(t!=NULL){
        inorder(t->lchild);
        cout<<t->data;
        inorder(t->rchild);
    }
}

void postorder(Pbitreenode t){//后序遍历
    if(t!=NULL){
        postorder(t->lchild);
        postorder(t->rchild);
        cout<<t->data;
    }
}

int node_number(Pbitreenode t){
    Pbitreenode Ptemp=t;
    int res=0;
    if(t!=NULL){
        res++;
        if(t->lchild!=NULL){
            res=res+node_number(Ptemp->lchild);
        }
        if(t->rchild!=NULL){
            res=res+node_number(Ptemp->rchild);
        }
    }
    return res;
}

int leaf_number(Pbitreenode t){//判断叶子节点数目
    int res=0;
    if(t!=NULL){
        if(t->lchild==NULL&&t->rchild==NULL){

        }

    }
    return res;
}