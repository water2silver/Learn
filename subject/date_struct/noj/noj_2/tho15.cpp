#include <bits/stdc++.h>
using namespace std;
//2022.4.22
/*对于像这样的二叉树的输入，如何建立二叉树？
A(B(#,D),C(E(#,F),#))
分析：
    1.像一个复杂多情况的递归
通过多if分支解决了问题，但是感觉解法不是很优美，有没有更漂亮的解法？

*/
typedef char DataType;

typedef struct tno_de{
    DataType data;
    struct tno_de *Lnode,*Rnode;
}TNode,*PTNode;

void create_node(PTNode &p);
void preorder(PTNode root);

int main(){
    PTNode Root;//声明一个根节点
    create_node(Root);

    preorder(Root);

    return 0;
}

void create_node(PTNode &p){//我应该怎么写这个函数阿...
    char c=getchar();//读入一个字母，这个字母是干啥的？
    if(c>='A'&&c<='Z'){
        p=(PTNode)malloc(sizeof(TNode));
        p->data=c;//要对p的左右子树进行操作吗
        p->Lnode=NULL;p->Rnode=NULL;

        create_node(p);
    }else if(c=='('){
        create_node(p->Lnode);
        create_node(p->Rnode);
    }else if(c==','){//对于), 连接的情况 如何写？
        if(p==NULL){
            create_node(p);
        }
    }else if(c==')'){
        return ;
    }else if(c=='#'){
        p=(PTNode)malloc(sizeof(TNode));
        p->data=c;//要对p的左右子树进行操作吗
        p->Lnode=NULL;p->Rnode=NULL;

        create_node(p);
    }
}

void preorder(PTNode root){
    if(root!=NULL){
        cout<<root->data;
        preorder(root->Lnode);
        preorder(root->Rnode);
    }
    return ;
}