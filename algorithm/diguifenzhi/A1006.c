#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int PX1(int *date,int n);

int main () {
    int n,i,j,k,date[1020];
    scanf("%d",&n);
    for(i=0;i<=n-1;i++){
        scanf("%d",&date[i]);
    }
    
    
    printf("%d",s);
    return 0;

}

int PX1(int *date,int n){
    int i,ni[1020],j;
    ni[0]=0;
    for(i=1;i<=n-1;i++){
        ni[i]=0;
        for(j=0;j<=i-1;j++){
            if(date[i]<date[j]) ni[i]++;
        }
    }
    int s=0;
    for(i=1;i<=n-1;i++) s=s+ni[i];
    return s;
}