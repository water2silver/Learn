#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int m,n,i,j,k;
    scanf("%d %d",&n,&m);//n为参与人数,m为计划录入的人数
    struct wo_rk{
        int xh;
        int gra;
    }date[5100];

    for(i=0;i<=n-1;i++){
        scanf("%d %d",&date[i].xh,&date[i].gra);
    }

    for(i=0;i<=n-2;i++){
        for(j=0;j<=n-2-i;j++){
            if(date[j].gra<date[j+1].gra){
                struct wo_rk t;
                t=date[j];
                date[j]=date[j+1];
                date[j+1]=t;
            }
            if(date[j].gra==date[j+1].gra&&date[j].xh>date[j+1].xh){
                struct wo_rk t;
                t=date[j];
                date[j]=date[j+1];
                date[j+1]=t;
            }
        }
    }

    /*for(i=0;i<=n-2;i++){
        for(j=0;j<=n-2;j++){
            if(date[j].gra==date[j+1].gra&&date[j].xh>date[j+1].xh){
                struct wo_rk t;
                t=date[j];
                date[j]=date[j+1];
                date[j+1]=t;
            }
        }
    }*/
    int q=m*3/2;int count=0;
    int std=date[q-1].gra;
    for(i=0;i<=n-1;i++){
        if(date[i].gra>=std){
            count++;
        }
    }
    printf("%d %d\n",std,count);
    for(i=0;i<=count-1;i++){
        printf("%d %d\n",date[i].xh,date[i].gra);
    }
    return 0;
}