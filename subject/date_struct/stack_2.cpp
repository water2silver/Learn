#include <bits/stdc++.h>
using namespace std;

typedef  int  DataType ;	// 定义栈中元素类型为整型，
struct  Node			
{
	DataType info;
	struct Node  *link;
};
typedef Node* PNode;
typedef struct LinkStack		/* 链接栈类型定义 */
{
	struct Node  *top;	/* 指向栈顶结点 */
}LinkStack, *PLinkStack;

//typedef LinkStack* PLinkStack;
/*
初始化，push，pop，top，empty
c++中，通过s.pop(),等操作来实现stack内容，所以stack更像一个类？

*/
PLinkStack Init_LS();
int my_empty(PLinkStack head);
void my_push(PLinkStack head,DataType x);
DataType my_top(PLinkStack head);
void my_pop(PLinkStack head);

int main(){
    PLinkStack head=Init_LS();
    if(my_empty(head)) {
        cout<<"stack is empty!"<<endl;
    }
    my_push(head,1);
    my_push(head,2);
    my_push(head,3);
    //cout<<my_top(head)<<" ";

    while(head->top){
        cout<<my_top(head)<<" ";
        my_pop(head);
    }


    return 0;
}
PLinkStack Init_LS(){
    PLinkStack head=(PLinkStack)malloc(sizeof(LinkStack));
    head->top=NULL;
    return head;
}

int my_empty(PLinkStack head){
    if(head->top==NULL) {
        //cout<<"stack is empty!"<<endl;
        return 1;
    }else{
        return 0;
    }
}

void my_push(PLinkStack head,DataType x){
    PNode Ptemp=(PNode)malloc(sizeof(Node));
    Ptemp->info=x;
    Ptemp->link=head->top;
    head->top=Ptemp;
}
DataType my_top(PLinkStack head){
    if(head->top!=NULL){
        return head->top->info;
    }else{
        cout<<"stack is empty"<<endl;
        return 0;
    }
}
void my_pop(PLinkStack head){
    if(head->top==NULL){
        cout<<"empty!"<<endl;
    }else {
        PNode Ptemp=head->top;//先记录，后释放
        head->top=head->top->link;
        free(Ptemp);
    }
}