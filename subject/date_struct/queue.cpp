#include <bits/stdc++.h>
using namespace std;
/*
queue
功能：push，front，tail，pop，empty
习题：小熊挑水果
优先队列：

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

int main(){
    PLinkList qlist=Init_queue();

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
void pop(PLinkList qlist){
   if(qlist->head==NULL) return ;
   else{
       PNode Ptemp=qlist->head;
       qlist->head=qlist->head->next;
       free(Ptemp);
    }
}