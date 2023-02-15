#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,date[10001],b[10001];
    int i,j,k=0;
    int t,a;
    scanf("%d",&n);
    for(i=0;i<=n-1;i++){
        scanf("%d",&date[i]);
        b[i]=date[i];
    }
    int cent=0,flag=0;
    for(i=0;i<=n-2;i++){
        for(j=i+1;j<=n-1;j++){
            if(date[i]>date[j]){
                t=date[j];
                date[j]=date[i];
                date[i]=t;
            }
        }
    }
    k=0;
    for(i=0;i<=n-1;i++){
        for(j=0;j<=n-1;j++){
            if(b[j]==date[k]){
                k++;
                break;
            }
        }
        for(t=j;t>=i+1;t--){
            a=b[t];
            b[t]=b[t-1];
            b[t-1]=a;
            cent++;
        }
    }
    printf("%d",cent);
    return 0;


}