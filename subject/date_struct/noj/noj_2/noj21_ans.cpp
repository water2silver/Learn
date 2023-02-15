#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 2000

typedef struct node{//定义一个带有标记和优先级的字符节点来储存表达式中的字符
    int tag;
    char elem;
    int prio;//优先级
}Node;//字符节点

typedef struct binTreeNode{
    Node data;
    struct binTreeNode *left,*right;
}BinTreeNode;//二叉树节点

typedef struct newString{
    Node data[MAX];
    int length;
}NewString;//存储字符串

//对于算式的二叉树储存，要考虑括号的影响，如何统筹全局？这个答案给了一种漂亮的解法
void InitString(NewString *S){
    char str[MAX];
    int len,baselevel = 0;
    scanf("%s",str);
    len = strlen(str);
    //运算符tag=1，其他tag=0
    //优先级:')'==-2; '{'==2; '字符'==0; '+,-'==1; '*,/'==2;
    for(int i=0;i<len;i++){
        S->data[i].elem = str[i];
		if (str[i]=='+'||str[i]=='-'){
			S->data[i].tag = 1;
			S->data[i].prio = baselevel+1;
		}
		else if (str[i] == '*' || str[i] == '/'){
			S->data[i].tag = 1;
			S->data[i].prio = baselevel+2;
		}
		else if (str[i] == '('){
			S->data[i].tag = 0;
			baselevel = baselevel + 2;
		}
		else if (str[i] == ')'){
			S->data[i].tag = 0;
			baselevel = baselevel - 2;
		}
		else{
			S->data[i].tag = 0;
		}
    }
    S->length = len;
}

void RemoveExtraBrackets(NewString *S){//去除外层多余的括号
    int level = 0;
    if(S->data[0].elem=='('&&S->data[S->length-1].elem==')'){//该子串头尾为左右括号，应判断子串左右括号配合栈是否恒不为为空，即匹配过程不出现level==0，括号可去
        for(int i=0;i<S->length-1;i++){//本质是简化的左右括号配合栈操作
            if(S->data[i].elem=='('){
            level++;
            }
            else if(S->data[i].elem==')'){
            level--;
            }
            if(level==0){
            return;
            }
        }
        for(int i=1;i<=S->length-1;i++){//更新字符串与该子串长度
            S->data[i-1] = S->data[i];
        }
        S->length = S->length - 2;
    }
}

int FIndMinPositive(NewString *S){//返回level最小符号的下标
    int positive=0,min=MAX;//min为当前最小的level，positive记录下标
    for(int i=0;i<S->length;i++){
        //这个地方带不带这个"="应该都无所谓
        if(S->data[i].prio<=min&&S->data[i].tag==1){//优先级相同时，先算前面的，所以将后面的作为中间值划分。
            min = S->data[i].prio;
            positive = i;
        }
    }
    return positive;
}

void CreatTree(BinTreeNode *T, NewString *S){
    NewString *left,*right;
    left = (NewString*)malloc(sizeof(NewString));
    right = (NewString*)malloc(sizeof(NewString));
    int midpositive,len;
    len = S->length;
    if(len==1){
        T->data = S->data[len-1];
        T->left = NULL;
        T->right = NULL;
    }
    else if(len>1){//以优先级最低的符号作为根节点，左右子串分别生成左右子树
        midpositive = FIndMinPositive(S);
        left->length = midpositive;
        for(int i = 0;i < midpositive;i++){
            left->data[i] = S->data[i];
        }
        right->length = S->length-midpositive-1;
        for(int i=0;i<right->length;i++){
            right->data[i] = S->data[i+midpositive+1];
        }
        RemoveExtraBrackets(left);
        RemoveExtraBrackets(right);
        T->data = S->data[midpositive];
        T->left = (BinTreeNode*)malloc(sizeof(BinTreeNode));
        T->right = (BinTreeNode*)malloc(sizeof(BinTreeNode));
        CreatTree(T->left,left);
        CreatTree(T->right,right);
    }
}

void Output(BinTreeNode* T){//递归后序输出二叉树
    if(T->left==NULL&&T->right==NULL){
        printf("%c",T->data.elem);
    }
    else{
        Output(T->left);
        Output(T->right);
        printf("%c",T->data.elem);
    }
}

int main(){
    NewString *S;
    S = (NewString*)malloc(sizeof(NewString));
    S->length = 0;
    InitString(S);
    RemoveExtraBrackets(S);
    BinTreeNode *T;
    T = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    CreatTree(T,S);
    Output(T);
    return 0;
}

