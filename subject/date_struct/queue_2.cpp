#include <iostream>
#include <stdio.h>
using namespace std;
/*内容：循环队列



*/

typedef int DataType;
struct que_ue{
    DataType *data;
    int max;
    int length;
    int head;
    int tail;
};
typedef struct que_ue Cqueue;
typedef struct que_ue* PCqueue;

PCqueue Init(int N);
void push_Cqueue(PCqueue Q,DataType x);
void pop_Cqueue(PCqueue Q);
int empty_Cqueue(PCqueue Q);
DataType top_Cqueue(PCqueue Q);
DataType tail_Cqueue(PCqueue Q);
void Prin_Cqueue(PCqueue Q);
//void test();

int main(){
    //test();检验基本的入栈，出栈函数
    int max,k;
    cin>>max>>k;
    PCqueue Q=Init(k);
    int sum=0;
    while(1){
        if(Q->length<=k-1){
            push_Cqueue(Q,0);
        }else if(Q->length==k){
            push_Cqueue(Q,sum>1?sum:1);
            sum=sum-top_Cqueue(Q);//去掉之前先减掉
            pop_Cqueue(Q);
        }
        sum=sum+Q->data[Q->tail];//加上最新的元素,此时sum是下一个入栈的元素
        if(sum>max&&Q->data[Q->tail]<=max) break;
    }
    Prin_Cqueue(Q);
    return 0;
}
/*void test(){
    int n,k;cin>>k;
    PCqueue Q=Init(k);//申请一个k+1 大小的循环队列    
    for(int i=1;i<=k;i++)
        push_Cqueue(Q,i);
    Prin_Cqueue(Q);
    pop_Cqueue(Q);
    Prin_Cqueue(Q);
}*/
PCqueue Init(int N){
    PCqueue Ptemp=(PCqueue)malloc(sizeof(Cqueue));
    Ptemp->data=(int*)malloc(sizeof(DataType)*(N+1));
    Ptemp->head=0;
    Ptemp->tail=0;
    Ptemp->max=N+1;
    Ptemp->length=0;
    return Ptemp;
}

void push_Cqueue(PCqueue Q,DataType x){
    if((Q->tail+1)%(Q->max)==(Q->head)){//尾巴的下一个是head的时候，队列满了
        return ;
    }else{
        if(Q->length==0){
            Q->data[Q->head]=x;
        }else {
            Q->tail=(Q->tail+1)%(Q->max);//注意越界问题
            Q->data[Q->tail]=x;
        }
        Q->length++;
    }
    return ;
}

void pop_Cqueue(PCqueue Q){//也有可能是只有一个元素
    if(Q->length==0){
        return ;
    }else if (Q->length==1){
        Q->length--;
    }else{
        Q->length--;
        Q->head=(Q->head+1)%(Q->max);/////////////
    }
}
DataType top_Cqueue(PCqueue Q){
    if(Q->length==0){
        return -1;
    }else{
        return Q->data[Q->head];
    }
}
DataType tail_Cqueue(PCqueue Q){
    if(Q->length==0){
        return -1;
    }else{
        return Q->data[Q->tail];
    }

}

int empty_Cqueue(PCqueue Q){
    if(Q->length==0) return 1;
    else return 0;
}

void Prin_Cqueue(PCqueue Q){
    int i;
    for(i=1;i<=Q->length;i++){
        cout<<Q->data[(Q->head+i-1)%(Q->max)]<<" ";//警惕
    }
}