#include <iostream>
using namespace std;
/*两个递增链表 归并成为递减链表
单链表的倒置问题？

*/
typedef int DataType;

struct No_de {
    int data;
    struct No_de* next;
};
typedef struct No_de Node;
typedef struct No_de* PNode;

struct LinkList{
    PNode head;
};
typedef LinkList* PLinkList;

void add_big(PLinkList plist,int x);
void Prin (PLinkList plist);
void my_delete (PLinkList plist,int x);
void add_small(PLinkList plist,int x);
PLinkList Init();
PNode find_last(PLinkList plist);
void abondon_tail(PLinkList plist);


int main(){
    PLinkList p1=Init(),p2=Init();
    PLinkList plist=Init();
    int m,n;
    cin>>m>>n;
    int i;int a;
    for(i=1;i<=n;i++){
        cin>>a;
        add_big(p1,a);
    }
    for(i=1;i<=m;i++){
        cin>>a;
        add_big(p2,a);
    }
    PNode pt1=p1->head->next;
    PNode pt2=p2->head->next;
    while(pt1){
        add_small(plist,pt1->data);
        pt1=pt1->next;
    }
    while(pt2){
        add_small(plist,pt2->data);
        pt2=pt2->next;
    }

    Prin(plist);
    return 0;
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
void add_small(PLinkList plist,int x){//插入序列是，选择合适的位置
    //新节点的建立
    PNode Ptemp=(PNode)malloc(sizeof(Node));
    Ptemp->data=x;
    Ptemp->next=NULL;
    //针对空链表，创建头节点
    if(plist->head->next==NULL){
        plist->head->next=Ptemp;
    }else{//😂
        PNode P_te=plist->head->next;
        if(x>=P_te->data){//特判第一个
            Ptemp->next=P_te;
            plist->head->next=Ptemp;
        }else{
            PNode t=P_te;
            while(x<=P_te->data&&P_te->next!=NULL){
                t=P_te;
                P_te=P_te->next;
            }
            if(P_te->next==NULL&&x<P_te->data){//当x大于最后一个元素时，新节点插入尾端
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

void my_delete (PLinkList plist,int x){
    PNode Ptemp=plist->head->next;
    if(Ptemp==NULL) return ;
    else{
        PNode P1=Ptemp;
        if(Ptemp->data==x) {
            plist->head->next=Ptemp->next;
            free(Ptemp);
            return ;
        }
        while(Ptemp&&Ptemp->data!=x){
            P1=Ptemp;
            Ptemp=Ptemp->next;
        }//寻找x
        if(Ptemp==NULL) {
            cout<<"no such x in the list!"<<endl;
        }else{
            if(Ptemp->next==NULL){
                free(Ptemp);
                P1->next=NULL;
            }else{
                PNode P2=Ptemp;
                P1->next=Ptemp->next;
                free(P2);
            }
        }

    }

}
PLinkList Init(){
    PLinkList Ptemp=(PLinkList)malloc(sizeof(LinkList));//我给了
    Ptemp->head=(PNode)malloc(sizeof(Node));//head and next
    Ptemp->head->next=NULL;//这个地方考虑啊，你是想head成为头节点，还是head->next成为？
    return Ptemp;
}
PNode find_last(PLinkList plist){

    PNode p=plist->head->next;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}
void abondon_tail(PLinkList plist){
    PNode p=plist->head;
    if(p==NULL) return ;
    else p=p->next;//p是首元素了
    if(p->next==NULL) plist->head=NULL;
    else{
        while(p->next->next!=NULL){
            p=p->next;
        }
        p->next=NULL;
    }
}
