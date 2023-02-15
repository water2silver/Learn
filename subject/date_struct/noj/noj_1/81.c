#include <stdio.h>
#include <stdlib.h>
int main(){
    long long k,b,c;
    scanf("%lld %lld",&k,&b);
    c=k*b;
    int a[101]={0};
    int i=0,j=0;int sum=0,t=0;
    
    while(c!=0){
        a[i++]=c%10;
        c=c/10;
    }
    for(j=0;j<=i-1;j++){
        sum=sum+a[j];
        a[i]=0;
    }
    i=0;
    while(sum>9){
        while(sum!=0){
        a[i++]=sum%10;
        sum=sum/10;
        }
        for(j=0;j<=i-1;j++){
            sum=sum+a[j];
            a[j]=0;
        }
        i=0;
    }
    printf("%d",sum);
    
}