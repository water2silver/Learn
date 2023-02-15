#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int fun(int n);
int main(){
    int i,j,a,b;
    int max=1;
    int m=0;
    //for(;;){
        scanf("%d %d",&a,&b);
        for(i=a;i<=b;i++){
            m=fun(i);
            if(m>max){
                max=m;
            }
        }
        printf("%d %d %d\n",a,b,max);
    //}
    return 0;
}
int fun(int n){
    int cent=1;
    while(n!=1){
        if(n%2==1){
            n=3*n+1;
        }else{
            n=n/2;
        }
        cent++;
    }
    return cent;
}