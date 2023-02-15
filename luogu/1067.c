#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int n,i,j,k;
    scanf("%d",&n);
    int date[100001];
    for(i=0;i<=n;i++){
        scanf("%d",&date[i]);
    }
    for(i=n;i>=0;i--){
        if(date[i]!=0) break;
    }
    int t=i;
    int flag=0;
    for(i=0;i<=n-2;i++){ //判定到二次项 n=1？
        if(date[i]!=0){
            if(date[i]!=1&&date[i]!=-1){
                printf("%dx^%d",date[i],n-i>1?n-i:1);
                flag=1;
                
            }
            if(date[i]==1){
                printf("x^%d",n-i>1?n-i:1);
                flag=1;
            }
            if(date[i]==-1){
                printf("-x^%d",n-i>1?n-i:1);
                flag=1;
            }
            for(j=i+1;j<=t;j++){
                    //if(date[j]==0) break;
                    if(date[j]>0) {printf("+");break;}
                    if(date[j]<0) break;
            }
        }   
    }
    if(date[n-1]!=0) {
        if(date[n-1]!=1&&date[n-1]!=-1){
                printf("%dx",date[i]);
                flag=1;
            }
            if(date[i]==1){
                printf("x");
                flag=1;
            }
            if(date[i]==-1){
                printf("-x");
                flag=1;
            }
            for(j=i+1;j<=t;j++){
                    //if(date[j]==0) break;
                    if(date[j]>0) {printf("+");break;}
                    if(date[j]<0) break;
            }
    }
    if(date[n]!=0) printf("%d",date[n]);
    if(flag==0&&date[n]==0) printf("0");
    return 0;
}