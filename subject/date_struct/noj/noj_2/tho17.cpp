#include <iostream>
using namespace std;
//2022.4.22
/*
建立二叉树存储输入的表达式，注意输入的式子是先序输入的，同时以#表示空指针扩展
然后中序输出即可
*/
typedef char DataType;

typedef struct tno_de{
    DataType data;
    struct tno_de *Lnode,*Rnode;
}TNode,*PTNode;

void create_node(PTNode &p);
void inorder(PTNode roof);

int main(){
    PTNode PRoot;
    create_node(PRoot);
    inorder(PRoot);

    return 0;
}
//*+a(###b#)##c##

void create_node(PTNode &p){//引用传递yyds

    char c=getchar();
    if(c=='#') p=NULL;
    else {
        p=(PTNode)malloc(sizeof(TNode));
        p->data=c;p->Lnode=NULL;p->Rnode=NULL;
        create_node(p->Lnode);
        create_node(p->Rnode);
    }
}

void inorder(PTNode roof){//典型的中序遍历
    if(roof!=NULL){
        inorder(roof->Lnode);
        cout<<roof->data;
        inorder(roof->Rnode);
    }
}