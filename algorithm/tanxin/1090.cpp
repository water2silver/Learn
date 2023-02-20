#include <iostream>
using namespace std;
/*
error！
思路：写一个单调递增的可删除，插入的链表，用以进行题目的操作。
太久没写链表了，居然没写对，笑了。

*/
class Node
{
    Node()
    {
        v=0;
        last=NULL;
        next=NULL;
    }
public:
    int v;
    Node* last=NULL;
    Node* next=NULL;  
};
void insert(Node* &s,int a);
void Node_delete(Node * &s,int a);

int main()
{
    int n;
    cin>>n;
    int a;
    Node *s;
    s=(Node*)malloc(sizeof(Node));
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        insert(s,a);
    }
    //test
    // for(int i=1;i<=n;i++)
    // {   
    //     cout<<s->v<<" ";
    //     if(s->next!=NULL)
    //         s=s->next;
    // }
    int sum=0;
    for(int i=1;i<=n-1;i++)
    {

        int t1,t2;
        t1=s->v;Node_delete(s,t1);
        t2=s->v;Node_delete(s,t2);
        sum+=t1+t2;
        insert(s,t1+t2);
    }
    cout<<sum<<endl;
    return 0;
}
/**
@brief: 在以Node* s 为起点的链表，按照递增的顺序进行插入。
*/
void insert(Node* &s,int a)
{
    //
    //cout<<"***"<<endl;
    if(s->v==0)
    {
        s->v=a;
        s->next=NULL;
        s->last=NULL;
    }else if(a<s->v)
    {
        Node *p=(Node*)malloc(sizeof(Node));
        p->v=a;
        p->next=s;
        p->last=s->last;//==NULL
        s->last=p;
        s=p;
    }else
    {
        Node* t=s;
        while(1)
        {
            if(t->v <a)
            {   
                if(t->next!=NULL)
                {
                    t=t->next;
                }else
                {
                    Node* p=(Node*)malloc(sizeof(Node));
                    p->v=a;
                    p->last=t;
                    p->next=NULL;
                    break;
                }
            }else
            {
                Node* p=(Node*)malloc(sizeof(Node));
                p->v=a;
                p->last=t->last;
                p->next=t;
                t->last->next=p;
                t->last=p;
                break;
            }
        }
    }
}
/*
5
5 2 4 1 3
*//**/

/**
 * @brief: 在一个单调递增的链表中删除一个值为 a 的节点，保证链表一定有值为 a 的节点。
 * 事实上我们每次都是删除第一个节点。
 */ 
void Node_delete(Node * &s,int a)
{
    
    if(s->v==a)
    {
        if(s->next!=NULL)
        {
            s=s->next;
        }else
        {
            //置空这个操作就先不做了，避免
            //s=NULL;
        }
    }else
    {

    }
}