#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int jc(int n);
int main(){
    int a[10];int q[4];
    int i,j,k;
    int d,q1;
    int flag=1;
    int final=0;
    scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4]);
    for(i=1;i<=4;i++){
        if((a[i]/a[i-1])*a[i-1]==a[i]){
            q[i-1]=a[i]/a[i-1];
            continue;
        }else{
            flag=0;
            break;
        }
    }
    if(flag==1&&q[0]==q[1]&&q[1]==q[2]&&q[2]==q[3]){
        final=1;
    }
    
    if(a[2]==a[0]+a[1]&&a[3]==a[2]+a[1]&&a[4]==a[3]+a[2]){
        for(i=5;i<=9;i++){
            a[i]=a[i-1]+a[i-2];
        }
    }
    else if ((a[4]-a[3])==(a[3]-a[2])&&(a[3]-a[2])==(a[2]-a[1])&&(a[2]-a[1])==(a[1]-a[0])){
        for(i=5;i<=9;i++){
            a[i]=a[i-1]+a[4]-a[3];
        }
    }
    else if(final==1){
        q1=a[4]/a[3];
        for(i=5;i<=9;i++){
            a[i]=a[i-1]*q1;
        }
    }else{
        printf("NULL");
        return 0;
    }
    for(i=5;i<=8;i++){
        printf("%d ",a[i]);
    }
    printf("%d",a[9]);
    return 0;
}