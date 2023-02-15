#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int n,i,j;
    int sum1=0,sum2=0;
    scanf("%d",&n);
    int date[10010][2];
    for(i=0;i<=n-1;i++){
        scanf("%d %d",&date[i][0],&date[i][1]); //将这n个士兵的坐标收集来

    }
    int midy1=0,midy2=0;
    int midy=0;int x0=0,x1=0,y0=0,y1=0;
    int sumy=0;//y坐标的最小步数目
    for(i=0;i<=n-2;i++){ //按照y从小到大排序这个地方的排序只取排y坐标
        for(j=i+1;j<=n-1;j++){//有问题？
            if(date[i][1]>date[j][1]){ 
                y1=date[j][1];
                date[j][1]=date[i][1];
                date[i][1]=y1;
            }
        }
    }
    if(n%2==1){//实现对于y移动的计算
        midy=(n-1)/2;
        for(i=0;i<=n-1;i++){
            sumy=sumy+abs(date[i][1]-date[midy][1]);
        }
    }
    else{
        
        midy1=n/2;
        midy2=n/2-1;
        for(i=0;i<=n-1;i++){
            sum1=sum1+abs(date[i][1]-date[midy1][1]);
            sum2=sum2+abs(date[i][1]-date[midy2][1]);
        }
        if(sum1>sum2){
            midy=midy2;
            sumy=sum2;
        }else{
            midy=midy1;
            sumy=sum1;
        }

    }
    for(i=0;i<=n-2;i++){//冒泡排序排列x坐标，从小到大
        for(j=i+1;j<=n-1;j++){
            if(date[i][0]>date[j][0]){
                x0=date[j][0];
                date[j][0]=date[i][0];
                date[i][0]=x0;
            }
        }
    }
    int sumx=0;int h=0;int sumt=0;
    for(i=date[0][0]-n+1;i<=date[n-1][0]+n-1;i++){
        h=i;
        for(j=0;j<=n-1;j++){
            sumt=sumt+abs(date[j][0]-h);
            h++;
        }
        if(sumx==0&&i==(date[0][0]-n+1)){
            sumx=sumt;
            sumt=0;
        }else{
            if(sumt<sumx){
                sumx=sumt;
                sumt=0;
            }
        }
    }
    printf("%d",sumx+sumy);
    return 0;
}