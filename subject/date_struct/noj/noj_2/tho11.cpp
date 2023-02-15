#include <bits/stdc++.h>
using namespace std;
/*
一般的队列：头出尾进
此题还要求：头进入尾巴出去

*/
typedef int DataType;

struct No_de{
    DataType data;
    struct No_de* next;
};
typedef No_de Node;
typedef No_de* PNode;

struct LinkList{
    PNode head;
    PNode tail;
};
typedef LinkList* PLinkList;

PLinkList Init_queue();
int empty(PLinkList plist);
DataType tail(PLinkList qlist);
DataType front(PLinkList qlist);
void pop(PLinkList qlist);
void push(PLinkList qlist,DataType x);
void f_push(PLinkList qlist,DataType x);
void t_pop(PLinkList qlist);

int main(){
    PLinkList qlist=Init_queue();
    int i=0;
    int n;int m;
    cin>>n>>m;int a;
    for(i=1;i<=n;i++){
        cin>>a;
        push(qlist,a);
    }
    int temp;
    for(i=1;i<=m;i++){
        temp=tail(qlist);
        t_pop(qlist);
        f_push(qlist,temp);
    }
    for(i=1;i<=n;i++){
        cout<<front(qlist)<<" ";
        pop(qlist);
    }

    return 0;
}

PLinkList Init_queue(){
    PLinkList Ptemp=(PLinkList)malloc(sizeof(PLinkList));
    Ptemp->head=NULL;
    Ptemp->tail=NULL;
    return Ptemp;
}
int queue_empty(PLinkList qlist){
    if(qlist->head==NULL){
        return 1;
    }else{
        return 0;
    }
}
void push(PLinkList qlist,DataType x){
    PNode Ptemp=(PNode)malloc(sizeof(Node));
    Ptemp->data=x;
    Ptemp->next=NULL;
    if(qlist->head==NULL){
        qlist->head=Ptemp;
        qlist->tail=Ptemp;
    }else{
        qlist->tail->next=Ptemp;
        qlist->tail=Ptemp;
    }
}

void pop(PLinkList qlist){
   if(qlist->head==NULL) return ;
   else{
       PNode Ptemp=qlist->head;
       qlist->head=qlist->head->next;
       free(Ptemp);
    }
}
void f_push(PLinkList qlist,DataType x){//往队首插入元素,指针是自左向右的
    PNode Ptemp=(PNode)malloc(sizeof(Node));
    Ptemp->data=x;
    Ptemp->next=NULL;
    if(qlist->head==NULL){
        qlist->head=Ptemp;
        qlist->tail=Ptemp;
    }else{
        Ptemp->next=qlist->head;
        qlist->head=Ptemp;
    }
}
void t_pop(PLinkList qlist){
    if(qlist==NULL) return ;
    else{
        PNode P_t=qlist->head;
        PNode Ptemp=qlist->tail;
        while(P_t->next!=qlist->tail){
            P_t=P_t->next;
        }
        qlist->tail=P_t;
        free(Ptemp);
    }
}



DataType front(PLinkList qlist){
    if(qlist->head==NULL) {
        return -1;
    }else{
        return qlist->head->data;
    }
}

DataType tail(PLinkList qlist){
    if(qlist->tail==NULL){
        return -1;
    }else{
        return qlist->tail->data;
    }
}