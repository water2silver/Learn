#include <stdio.h>

int main(){
    int num;int res=0;
    scanf("%d",&num);
    while(num!=0){
        if(num%2==1){
            num--;
            res++;
        }else{
            num=num/2;
        }
    }
    printf("%d",res);


    return 0;
}