#include <stdio.h>
#include <stdlib.h>
int main(){
    int m,n,i,j,l,a[10]={0};
    int t,k=0;
    scanf("%d %d",&m,&n);
    for(i=m;i<=n;i++){
        t=i;
        while(t!=0){
            k=t%10;
            a[k]++;
            t=t/10;

        }
    }
    for(i=0;i<=8;i++){
        printf("%d ",a[i]);
    }
    printf("%d",a[9]);

}