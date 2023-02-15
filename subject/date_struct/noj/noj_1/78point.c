#include <stdio.h>
#include <stdlib.h>

int main(){
    typedef struct wo_rk{
        int num;
        struct wo_rk* next;
    }work;
    int n,i,j,k;
    int number,newer;
    work *head=NULL;//头指针
    scanf("%d",&n);
    for(i=0;i<=n-1;i++){
        scanf("%d",&number);
        work*p=(work*)malloc(sizeof(work));//malloc默认返回一个void的指针
        p->num=number;//
        p->next=NULL;
        work *last=head;
        if(last){
            while(last->next){
                last=last->next;
            }
            last->next=p;
        }else{
            head=p;
        }
    }
    scanf("%d",&newer);
    work *p=NULL,*q=NULL;
    for(p=head;p;q=p,p=p->next){
        if(newer<p->num){
            work *newlink=(work*)malloc(sizeof(work));
            if(q){
                newlink->num=newer;
                q->next=newlink;
                newlink->next=p;
            }
            else 
            {
                q=head;
                newlink->num=newer;
                head=newlink;
                head->next=q;
            }  
            break;
        }
        if(p->next==NULL){
           // break;
            work *newlink=(work*)malloc(sizeof(work));
            newlink->num=newer;
            newlink->next=NULL;
            p->next=newlink;
        }
    }
    for(p=head;p;p=p->next){
        printf("%d ",p->num);
    }
    return 0;
}