#include <iostream>
#include <string.h>
using namespace std;
/*理论noj18
题目要求：根据先序遍历和中序遍历建立树
方法：建立递归函数，函数的参数划分字符串，实现递归计算
    要注意递归结束和继续的条件，避免死循环
灵感来自于：零星的听课感受与手写计算的感受

*/
typedef struct no_de{
    char data;
    struct no_de * lchild;
    struct no_de * rchild;
}Node;
typedef Node* PNode;
char in[102];
char mid[102];
void func(PNode head,int a,int b,int x,int y);
void postorder(PNode head);

int main(){
    
    cin>>in>>mid;
    PNode head;
    head=(PNode)malloc(sizeof(Node));
    //
    //cout<<strlen(in)-1<<endl;
    func(head,0,strlen(in)-1,0,strlen(mid)-1);
    postorder(head);
/*
ABDFGCEH
BFDGACEH
*/
    return 0;
}

void postorder(PNode head){
    if(head!=NULL){
        postorder(head->lchild);
        postorder(head->rchild);
        cout<<head->data;
    }
}

void func(PNode head,int a,int b,int x,int y){
    int i=x;
    //左子树长度和右子树长度
    while(mid[i]!=in[a]){
        i++;
    }
    int d=i-x;
    int m=y-i;
    //对于这个点本身的修正
    head->data=in[a];
    //递归部分的思路:
    //左侧部分有内容
    if(d!=0){
        head->lchild=(PNode)malloc(sizeof(Node));
        func(head->lchild,a+1,a+d,x,i-1);
    }else{
        head->lchild=NULL;
    }
    if(m!=0){
        head->rchild=(PNode)malloc(sizeof(Node));
        func(head->rchild,a+d+1,b,i+1,y);
    }else{
        head->rchild=NULL;
    }
}