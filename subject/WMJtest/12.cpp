#include <stdio.h>
#include <math.h>
int main(){
    int i,j,n,res;
    while(1){
        res=0;
        scanf("%d",&n);
        if(n==0) break;
        while(n%2==0){
            res++;
            n=n/2;
        }
        printf("%.0lf\n",pow(2,res));
    }
    return 0;
}