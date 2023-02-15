#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int x,y,z;
    int i,j=1,k;
    scanf("%d %d",&x,&y);
    for(i=x>y?y:x;i>=1;i--){//简化xy的比值，让他成为真分数
        if(x%i==0&&y%i==0){
            break;
        }
    }                   
    int m=i;
    x=x/m;y=y/m;
    z=x/y;
    double std=(double)x/(double)y;
    int start,end,flag=0;
    double wucha=2;
    for(i=1;i<=y;i++){
        flag=0;end=0;
        for(j=1;j<=x;j++){
            if(fabs((((double)j/(double)i)-std))<wucha){
                wucha=fabs((((double)j/(double)i)-std));
                end=j;
                flag=1;
            }
        }
        if(flag==1){
            printf("%d/%d",end,i);
            if(i!=y) printf("\n");
        }
    }
    return 0;
}