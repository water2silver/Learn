#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,n,sum10,sum12,sum16;
    for(i=2992;i<10000;i++){
        n=i;
        sum10=0;
        while(n!=0){
            sum10+=sum10+n%10;
            n=n/10;
        }
        n=i;
        sum12=0;
        while(n!=0){
            sum12+=sum12+n%12;
            n=n/12;
        }
        n=i;
        sum16=0;
        while(n){
            sum16+=sum16+n%16;
            n/=n/16;
        }
        if(sum10==sum12&&sum12==sum16) printf("%d\n",i);
    }
    return 0;
}
