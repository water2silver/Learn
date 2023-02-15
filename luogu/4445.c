#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int n,i,k;
    scanf("%d",&n);
    long long date[100001];
    for(i=0;i<=n-1;i++){
        scanf("%lld",&date[i]);
    }
    long long sum=0;
    for(i=0;i<=n-2;i++){
        sum=sum+(date[i]>date[i+1]?date[i]:date[i+1]);
    }
    printf("%lld",sum);

}