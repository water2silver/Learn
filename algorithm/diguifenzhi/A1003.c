#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int m,n,i,j;
    scanf("%d %d",&m,&n);
    if(m<=n){
        int t=m;
        m=n;n=t;
    }//m>n
    while(1){
        m=m%n;
        if(m==0) break;
        int t=m;
        m=n;n=t;
    }
    printf("%d",n);
}