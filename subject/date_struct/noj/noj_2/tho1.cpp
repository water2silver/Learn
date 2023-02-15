#include <iostream>
using namespace std;

/*实现一个数据不减的列表add_big
n
a1 a2 ... an
anew
*/
struct No_de{
    int data;
    struct No_de* next;
};
typedef No_de Node;
typedef No_de* PNode;

struct LinkList{
    PNode head;
};
typedef LinkList* PLinkList;

PLinkList Init();//初始化数据，注意对于指针变量，先分配空间，在对其内容操作
void add_big(PLinkList plist,int x);
void Prin (PLinkList plist);

int main(){
    PLinkList plist=Init();
    int n,i,j;
    cin>>n;
    for(i=1;i<=n;i++){
        int a;
        cin>>a;
        add_big(plist,a);
    }
    cin>>j;
    add_big(plist,j);
    Prin(plist);
    return 0;
}
PLinkList Init(){
    PLinkList Ptemp=(PLinkList)malloc(sizeof(LinkList));//我给了
    Ptemp->head=(PNode)malloc(sizeof(Node));//head and next
    Ptemp->head->next=NULL;//这个地方考虑啊，你是想head成为头节点，还是head->next成为？
    return Ptemp;
}


void add_big(PLinkList plist,int x){//插入序列是，选择合适的位置
    //新节点的建立
    PNode Ptemp=(PNode)malloc(sizeof(Node));
    Ptemp->data=x;
    Ptemp->next=NULL;
    //针对空链表，创建头节点
    if(plist->head->next==NULL){
        plist->head->next=Ptemp;
    }else{//😂
        PNode P_te=plist->head->next;
        if(x<=P_te->data){//特判第一个
            Ptemp->next=P_te;
            plist->head->next=Ptemp;
        }else{
            PNode t=P_te;
            while(x>=P_te->data&&P_te->next!=NULL){
                t=P_te;
                P_te=P_te->next;
            }
            if(P_te->next==NULL&&x>P_te->data){//当x大于最后一个元素时，新节点插入尾端
                P_te->next=Ptemp;
            }else{//其他情况如此
                Ptemp->next=t->next;
                t->next=Ptemp;
            }
        }
    }
}

void Prin (PLinkList plist){//打印函数
    PNode temp=plist->head->next;
    while(temp){
        cout<<temp->data<<" ";
        if(temp->next==NULL) break;
        else temp=temp->next;
    }
}
