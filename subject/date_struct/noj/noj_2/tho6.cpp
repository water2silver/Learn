#include <iostream>
#include <math.h>
using namespace std;
/*
双向链表加定位次数统计

*/

typedef char DataType;

struct DNo_de {
    DataType data;
    struct DNo_de* last;
    struct DNo_de* next;
    int freq=0;
};
typedef struct DNo_de DNode;
typedef struct DNo_de* PDNode;

struct DLinkList{
    PDNode head;
    PDNode tail;
    int length;
};
typedef DLinkList* PDLinkList;

PDLinkList Init();
void add_double(PDLinkList plist,DataType x);
void locate_swap(PDLinkList plist,DataType x);
void Prin (PDLinkList plist);

int main(){
    PDLinkList plist=Init();
    char c;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c;
        add_double(plist,c);
    }
    for(int i=1;i<=m;i++){
        cin>>c;
        locate_swap(plist,c);
    }

    Prin(plist);

    return 0;
}

PDLinkList Init(){
    PDLinkList Ptemp=(PDLinkList)malloc(sizeof(DLinkList));
    Ptemp->head=NULL;
    Ptemp->tail=NULL;
    Ptemp->length=0;
    return Ptemp;
}

void add_double(PDLinkList plist,DataType x){
    //create
    PDNode Ptemp=(PDNode)malloc(sizeof(DNode));
    Ptemp->data=x;
    Ptemp->next=NULL;
    Ptemp->last=NULL;

    if(plist->head==NULL){//非空
        plist->head=Ptemp;
        plist->tail=Ptemp;

    }else{
        PDNode P_te =plist->head;
        while(P_te->next){
            P_te=P_te->next;
        }
        P_te->next=Ptemp;
        Ptemp->last=P_te;
        plist->tail=Ptemp;

    }
    plist->length++;    
}

void locate_swap(PDLinkList plist,DataType x){
    PDNode Ptemp=plist->head;
    if(Ptemp==NULL) return ;
    while(Ptemp){
        if(Ptemp->data==x) {
            Ptemp->freq++;
            while(Ptemp->last&&Ptemp->freq>Ptemp->last->freq){//双向链表的好处
                if((Ptemp->last==plist->head)&&(Ptemp->next==NULL)){
                    Ptemp->next=Ptemp->last;
                    Ptemp->last->last=Ptemp;
                    Ptemp->last->next=NULL;
                    Ptemp->last=NULL;
                    //
                    plist->head=Ptemp;
                    plist->tail=Ptemp->next;

                }else if(Ptemp->last==plist->head){//是头节点的前结点/////////////
                    plist->head->last=Ptemp;
                    plist->head->next=Ptemp->next;
                    Ptemp->next->last=plist->head;
                    Ptemp->next=plist->head;
                    Ptemp->last=NULL;
                    //最后修改头节点
                    plist->head=Ptemp;
                }else if(Ptemp->next==NULL){
                    PDNode t_l=Ptemp->last->last;
                    t_l->next=Ptemp;
                    Ptemp->last->last=Ptemp;
                    Ptemp->last->next=NULL;
                    Ptemp->next=Ptemp->last;
                    Ptemp->last=t_l;

                    plist->tail=Ptemp->next;

                }else{
                    PDNode t_l=Ptemp->last->last;
                    PDNode t_A=Ptemp->last;
                    Ptemp->last->next=Ptemp->next;
                    Ptemp->last->last=Ptemp;
                    t_l->next=Ptemp;
                    Ptemp->last=t_l;
                    Ptemp->next->last=t_A;
                    Ptemp->next=t_A;
                }
            }
        }
        Ptemp=Ptemp->next;
    }
}
void locate__swap(PDLinkList plist,DataType x){//这是老函数，能用，针对两个元素是有漏洞
    PDNode Ptemp=plist->head;
    if(Ptemp==NULL) return ;
    while(Ptemp){
        if(Ptemp->data==x) {
            Ptemp->freq++;
            while(Ptemp->last&&Ptemp->freq>Ptemp->last->freq){//双向链表的好处
                if(Ptemp->last==plist->head){//是头节点的前结点/////////////
                    plist->head->last=Ptemp;
                    plist->head->next=Ptemp->next;
                    Ptemp->next->last=plist->head;
                    Ptemp->next=plist->head;
                    Ptemp->last=NULL;
                    //最后修改头节点
                    plist->head=Ptemp;
                }else if(Ptemp->next==NULL){
                    PDNode t_l=Ptemp->last->last;
                    t_l->next=Ptemp;
                    Ptemp->last->last=Ptemp;
                    Ptemp->last->next=NULL;
                    Ptemp->next=Ptemp->last;
                    Ptemp->last=t_l;

                    plist->tail=Ptemp->next;

                }else{
                    PDNode t_l=Ptemp->last->last;
                    PDNode t_A=Ptemp->last;
                    Ptemp->last->next=Ptemp->next;
                    Ptemp->last->last=Ptemp;
                    t_l->next=Ptemp;
                    Ptemp->last=t_l;
                    Ptemp->next->last=t_A;
                    Ptemp->next=t_A;
                }
            }
        }
        Ptemp=Ptemp->next;
    }
}
void Prin (PDLinkList plist){//打印函数
    PDNode temp=plist->head;
    while(temp){
        cout<<temp->data<<" ";
        if(temp->next==NULL) break;
        else temp=temp->next;
    }
}
