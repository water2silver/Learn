#include <iostream>
using namespace std;
/*线性表的就地逆置
单链表的就地逆置怎样做才会简单


*/
struct No_de {
    int data;
    struct No_de* next;
};
typedef struct No_de Node;
typedef struct No_de* PNode;

struct LinkList{
    PNode head;
};
typedef LinkList* PLinkList;

PLinkList Init();
void add_normal(PLinkList plist,int x);
void Prin (PLinkList plist);
void inverse(PLinkList plist);

int main(){
  int n,i;
    int a[1010];
    PLinkList plist=Init();
    cin>>n;
 /* for(i=1;i<=n;i++){
        cin>>a[i];
        add_normal(plist,a[i]);
    }
    for(i=1;i<=n/2;i++){
        swap(a[i],a[n+1-i]);
    }
    for(i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }*/

    //Prin(plist);

    add_normal(plist,1);
    add_normal(plist,2);
    add_normal(plist,3);
    Prin(plist);
    inverse(plist);
    Prin(plist);
    return 0;
}

PLinkList Init(){
    PLinkList Ptemp=(PLinkList)malloc(sizeof(LinkList));//我给了
    Ptemp->head=(PNode)malloc(sizeof(Node));//head and next
    Ptemp->head->next=NULL;//这个地方考虑啊，你是想head成为头节点，还是head->next成为？
    return Ptemp;
}

void add_normal(PLinkList plist,int x){
    //create
    PNode Ptemp=(PNode)malloc(sizeof(Node));
    Ptemp->data=x;
    Ptemp->next=NULL;

    if(plist->head->next==NULL){//非空
        plist->head->next=Ptemp;
    }else{
        PNode P_te =plist->head->next;
        while(P_te->next){
            P_te=P_te->next;
        }
        P_te->next=Ptemp;
    }
}

void Prin (PLinkList plist){//打印函数
    PNode temp=plist->head->next;
    while(temp){
        cout<<temp->data<<" ";
        if(temp->next==NULL) break;
        else temp=temp->next;
    }
}

void inverse(PLinkList plist){
    PNode Ptemp=plist->head->next;
    PNode P[1010];
    int i=1;
    //
    if(Ptemp->next==NULL) return ;
    else if(Ptemp->next->next==NULL){
        plist->head->next=Ptemp->next;
        plist->head->next->next=Ptemp;
    }else{
        P[1]=Ptemp->next->next;//P1指向第三个节点
        P[2]=Ptemp->next;//      P2指向第二个节点
        Ptemp->next->next=Ptemp;
        Ptemp->next=NULL;
        while(1){
            P[2*i+1]=P[2*i-1]->next;
            P[2*i-1]->next=P[2*i];
            P[2*i+2]=P[2*i-1];
            if(P[2*i+1]->next==NULL) break;
            i++;
        }
        P[2*i+1]->next=P[2*i-1];
        plist->head->next=P[2*i+1];
    }
}