#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int i,j,k;
    int a[1010],b[1010];
    for(i=0;;i++){//数据读入
        scanf("%d %d",&a[i],&b[i]);
        if(a[i]==b[i]&&a[i]==0){
            break;
        }
    }
    double sum=0;
    double min=1;
    double t1,t2,t3;
    int cent=i;//cent是一共多少组数字
    for(i=0;i<=cent-1;i++){//对这cent组数字进行运算
        //int x1=1.0/a[i],x2=1.0/(b[i]+a[i]);
        for(j=0;j<=a[i];j++){//对原先的a[i]个元素开始处理
            t1=1.0*j/a[i];
            for(k=0;k<=a[i]+b[i];k++){
                t2=1.0*k/(a[i]+b[i]);
                t3=fabs(t2-t1);
                if(t3<min) min=t3;
            }
            sum=sum+min;
            min=1;
        }
        printf("%.4lf\n",sum*10000);
        sum=0;
    }
    return 0;
}