#include <bits/stdc++.h>
#include <string.h>
using namespace std;
/*题目：逆波兰式 考虑 + - * / 但是不考虑括号
导致a+b*c与(a+b)*c的输出结果是一样的


*/

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
    PLinkStack s1=Init_LS();
    PLinkStack s2=Init_LS();
    char data[1010];
    scanf("%s",data);
    int i;
    for(i=0;i<=strlen(data)-1;i++){
        if(data[i]<='z'&&data[i]>='a'){
            my_push(s1,data[i]);
            if(!my_empty(s2)){//s2非空
                DataType   temp1=my_top(s1);
                my_pop(s1);
                if(!my_empty(s1)){
                    DataType   temp2=my_top(s1);my_pop(s1);
                    cout<<temp2<<temp1<<my_top(s2);
                }
                else{
                    cout<<temp1<<my_top(s2);
                }
                my_pop(s2);
            }
        }
        else if(data[i]=='+'||data[i]=='-'||data[i]=='*'||data[i]=='/'){
            my_push(s2,data[i]);
        }

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