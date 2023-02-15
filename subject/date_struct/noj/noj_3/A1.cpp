#include <iostream>
using namespace std;
/*对于两个单向链表，使用归并排序（增序）
之前写过add_big(),即按照不减的方式给链表插入元素
mergeLists中对于while的写法很漂亮
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

PLinkList Init();
void add_big(PLinkList plist,int x);
void Prin (PLinkList plist);
void get_input(PLinkList p1,PLinkList p2);
void mergeLists(PLinkList p1,PLinkList p2,PLinkList p3);
void add_big_2(PLinkList plist,int x);

int main(){
    PLinkList p1=Init();
    PLinkList p2=Init();
    PLinkList p3=Init();
    get_input(p1,p2);
    //Prin(p1);
    //Prin(p2);
    mergeLists(p1,p2,p3);
    Prin(p3);


    return 0;
}
void mergeLists(PLinkList p1,PLinkList p2,PLinkList p3){
    PNode pt1=p1->head->next;
    PNode pt2=p2->head->next;
    while(pt1&&pt2){
        if(pt1->data>pt2->data){
            add_big_2(p3,pt2->data);
            pt2=pt2->next;
        }else{
            add_big_2(p3,pt1->data);
            pt1=pt1->next;            
        }
    }
    while(pt1){
        add_big_2(p3,pt1->data);
        pt1=pt1->next;
    }
    while(pt2){
        add_big_2(p3,pt2->data);
        pt2=pt2->next;
    }    

}



void get_input(PLinkList p1,PLinkList p2){
    int m,n,i;
    cin>>n;int temp;
    for(i=1;i<=n;i++){  
        cin>>temp;
        add_big_2(p1,temp);
    }
    cin>>m;
    for(i=1;i<=m;i++){
        cin>>temp;
        add_big_2(p2,temp);
    }
}


PLinkList Init(){
    PLinkList Ptemp=(PLinkList)malloc(sizeof(LinkList));//我给了
    Ptemp->head=(PNode)malloc(sizeof(Node));//head and next
    Ptemp->head->next=NULL;//这个地方考虑啊，你是想head成为头节点，还是head->next成为？
    return Ptemp;
}
void add_big_2(PLinkList plist,int x){//插入序列是，选择合适的位置
    //新节点的建立
    PNode Ptemp=(PNode)malloc(sizeof(Node));
    Ptemp->data=x;
    Ptemp->next=NULL;
    //针对空链表，创建头节点
    if(plist->head->next==NULL){
        plist->head->next=Ptemp;
    }else{//
        PNode P_te=plist->head->next;
        if(x<=P_te->data){//特判第一个
            Ptemp->next=P_te;
            plist->head->next=Ptemp;
        }else{
            PNode t=P_te;
            //t永远记录上一个
            while(P_te&&P_te->data<x){
                t=P_te;
                P_te=P_te->next;
            }
            Ptemp->next=P_te;
            t->next=Ptemp;
        }
    }
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
        cout<<temp->data<<endl;
        if(temp->next==NULL) break;
        else temp=temp->next;
    }
}/*
3
1 3 7
5
2 4 6 8 10
*/