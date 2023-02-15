#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int n,i,j,k;
    int sta[8];
    int date[1001][8];
    int prize[7]={0};
    scanf("%d",&n);
    for(i=1;i<=7;i++){
        scanf("%d",&sta[i]);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=7;j++){
            scanf("%d",&date[i][j]);
        }
    }
    int cnt=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=7;j++){
            for(k=1;k<=7;k++){
                if(date[i][j]==sta[k]) {
                    cnt++;
                    break;       
                }
            }
        }
        if(cnt>=1)
            prize[cnt-1]++;
        cnt=0;
    }
    for(i=6;i>=1;i--){
        printf("%d ",prize[i]);
    }
    printf("%d",prize[0]);
}