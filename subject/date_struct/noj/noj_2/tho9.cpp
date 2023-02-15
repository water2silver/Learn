#include <iostream>
#include <stdio.h>
using namespace std;

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
    int length=0;
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
    int i,n,a;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a;
        push(qlist,a);
    }
    char s[10];
    scanf("%s",s);
    cin>>a;
    int m;
    while(1){
        m=front(qlist);
        pop(qlist);
        if(m==a) break;
    }
    PNode Ptemp=qlist->head;
    
    while(Ptemp){
        cout<<Ptemp->data<<" ";
        Ptemp=Ptemp->next;
    }
    cout<<"\n"<<front(qlist);
    return 0;
}

PLinkList Init_queue(){
    PLinkList Ptemp=(PLinkList)malloc(sizeof(PLinkList));
    Ptemp->head=NULL;
    Ptemp->tail=NULL;
    return Ptemp;
}
int empty(PLinkList qlist){
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
    qlist->length++;
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
       qlist->length--;
    }
}