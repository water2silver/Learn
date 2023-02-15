#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int n;
    int i;double date[1000];
    int j;
    scanf("%d",&n);
    for(i=0;i<=n-1;i++){
        scanf("%lf",&date[i]);
    }
    for(i=0;i<=n-2;i++){        //降序排列
        for(j=i+1;j<=n-1;j++){
            if(date[i]<date[j]){
                double t;
                t=date[j];
                date[j]=date[i];
                date[i]=t;
            }
        }
    }
    double end[1000];
    for(i=0;i<=n-1;i++){
        end[i]=2*sqrt(date[i]*date[i]-1.0);
    }
    double sum=0;
    i=0;
    while(sum<=20){
        sum=sum+end[i++];
    }
    printf("%d",i);
    return 0;
}