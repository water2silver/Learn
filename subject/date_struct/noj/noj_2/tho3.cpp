#include <iostream>
using namespace std;
/*查找链表中的元素

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
void my_delete (PLinkList plist,int x);
int search(DataType x,PLinkList p);

int main(){
    PLinkList plist=Init();
    PLinkList p1=Init();
    PLinkList p2=Init();
    int n, m, k;
    cin >> n >> m >> k;
    int i, j; int a;
    for(i=1;i<=n;i++){
        cin>>a;
        add_big(plist,a);
    }
    for(i=1;i<=m;i++){
        cin>>a;
        add_big(p1,a);
    }
    for(i=1;i<=k;i++){
        cin>>a;
        add_big(p2,a);
    }
    PNode Ptemp=plist->head->next;
    PNode Ptemp2=Ptemp;
    while(Ptemp){
        Ptemp2=Ptemp;
        Ptemp=Ptemp->next;
        if(search(Ptemp2->data,p1)&&search(Ptemp2->data,p2)){
            my_delete(plist,Ptemp2->data);
        }
    }
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

int search(DataType x,PLinkList p){
    PNode p_1=p->head->next;
    while(p_1){
        if(p_1->data==x) return 1;
        else p_1=p_1->next;
    }
    return 0;
}
/*
8 5 6
1 2 3 4 5 6 6 7 
2 3 5 9 12
2 4 5 6 12 13


*/