#include <iostream>
using namespace std;
//2022.4.22
/*建立二叉链表方式存储的二叉树
统计这样的二叉树中叶子节点的数目
*/
typedef char DataType;

typedef struct tno_de{
    DataType data;
    struct tno_de *Lnode,*Rnode;
}TNode,*PTNode;

void create_node(PTNode &p);
int cent(PTNode p);

int main(){
    PTNode PRoot;
    create_node(PRoot);
    int res=cent(PRoot);
    cout<<res<<endl;
    return 0;
}
// ABD##EH###CF#I##G##
void create_node(PTNode &p){//引用传递yyds
    char c=getchar();
    if(c=='#') p=NULL;
    else if(c>='A'&&c<='Z'){
        p=(PTNode)malloc(sizeof(TNode));
        p->data=c;p->Lnode=NULL;p->Rnode=NULL;
        create_node(p->Lnode);
        create_node(p->Rnode);
    }
}
int cent(PTNode p){
    int res=0;
    if(p==NULL) return 0;
    if(p->Lnode==NULL&&p->Rnode==NULL){
        return 1;
    }else{
        res+=cent(p->Lnode);
        res+=cent(p->Rnode);
    }

    return res;
}