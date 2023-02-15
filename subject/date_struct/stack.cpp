#include <bits/stdc++.h>
using namespace std;
/*stack
stack的声明,初始化
pop();
push();
front();
empty();
*/
/*
1.连续存储实现方式
    数组实现，用a【0】，表示当前栈顶元素位置,是否为空用a[0]决定
    会有空间浪费的问题，但是如果全盘移动又很慢

2.链式存储
    申请空间，p->data=x;p->next=top;top=p;
*/
/*
q1:n个数字(1~n)入栈，有多少种出栈的方式？   (定住某一个，递归)

*/


#define N 1000
typedef int DataType;
struct SeqStack{//连续存储的stack
    DataType data[N];
    int top=0;
};
typedef struct SeqStack S_Stack;
S_Stack s;

int My_empty(S_Stack s);
void My_push(S_Stack &s,DataType x);
void My_pop(S_Stack &s);
/*反思：为啥直接 void My_pop(S_Stack s);不行？
原因：我定义了s是全局变量，可在传参数的时候，是值传递，
    即在内存中我又申请了一块区域，值为s，我修改的是这个区域，而不是全局变量s
只能说：引用传递yyds
*/
DataType My_top(S_Stack s);

int main(){
/*    
    if(My_empty(s)) cout<<"empty!"<<endl;
    My_push(s,1);
    cout<<"My top of stack:"<<My_top(s)<<endl;
    My_push(s,2);
    cout<<"My top of stack:"<<My_top(s)<<endl;
    My_push(s,3);
    cout<<"My top of stack:"<<My_top(s)<<endl;
    while(!My_empty(s)) {
        cout<<My_top(s)<<" ";
        My_pop(s);
    }*/

    return 0;
}

int My_empty(S_Stack s){
    if(s.top==0) return 1;
    else return 0;
}

void My_push(S_Stack &s,DataType x){//修改栈内元素，data[0]始终空着
    s.data[++(s.top)]=x;
    cout<<"My_push"<<s.data[s.top]<<endl;
}

void My_pop(S_Stack &s){
    (s.top)--;
}

DataType My_top(S_Stack s){
    if(!My_empty(s))
        return s.data[s.top];
    else cout<<"kong!"<<endl;
    return 0;
}