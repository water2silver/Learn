#include <stdio.h>

int main(){
    int m,n;double A,a=0,res=0;
    scanf("%d %d",&m,&n);
    int data1[101][101],data2[101][101];
    int i,j;int temp;
    for(i=0;i<=m-1;i++){
        for(j=0;j<=n-1;j++){
            scanf("%d",&temp);
            data1[i][j]=temp;
        }
    }
    for(i=0;i<=m-1;i++){
        for(j=0;j<=n-1;j++){
            scanf("%d",&temp);
            data2[i][j]=temp;
            if(data2[i][j]==data1[i][j]){
                a++;
            }
        }
    }
    res=a/(m*n);
    printf("%.2lf",res*100);
    return 0;
}