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
            while(P_te&&P_te->data>=x){
                t=P_te;
                P_te=P_te->next;
            }
            Ptemp->next=P_te;
            t->next=Ptemp;
            }
        }
    }
}