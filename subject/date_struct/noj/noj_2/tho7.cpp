#include <bits/stdc++.h>
#include <string.h>
using namespace std;

typedef  char  DataType ;	// 定义栈中元素类型为整型，
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

PLinkStack Init_LS();
int my_empty(PLinkStack head);
void my_push(PLinkStack head,DataType x);
DataType my_top(PLinkStack head);
void my_pop(PLinkStack head);
int main(){
    PLinkStack head=Init_LS();
    char data[1010];
    cin>>data;
    int i;
    for(i=0;i<=strlen(data)-1;i++){
        if(data[i]=='(') my_push(head,data[i]);
        else if(data[i]=='[') my_push(head,data[i]);
        else if(data[i]=='{') my_push(head,data[i]);
        else if(data[i]=='}'){
            if(!my_empty(head)&&my_top(head)=='{'){
                my_pop(head);
            }else{
                cout<<"no"<<endl;
                break;
            }
        }else if(data[i]==']'){
            if(!my_empty(head)&&my_top(head)=='['){
                my_pop(head);
            }else{
                cout<<"no"<<endl;
                break;
            }
        }else if(data[i]==')'){
            if(!my_empty(head)&&my_top(head)=='('){
                my_pop(head);
            }else{
                cout<<"no"<<endl;
                break;
            }
        }else{

        }
        if((i==strlen(data)-1)&&my_empty(head)) cout<<"yes"<<endl;
        
    }

    return 0;
}
//[5+(6-3)]-(2+3)]
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