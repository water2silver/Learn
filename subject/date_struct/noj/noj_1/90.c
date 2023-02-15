#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    char dir[10];
    int n,i,r=0;
    scanf("%s",dir);scanf("%d",&n);
    if(dir[0]=='N') r=0;
    if(dir[0]=='W') r=1;
    if(dir[0]=='S') r=2;
    if(dir[0]=='E') r=3;
    int date[10010];
    int sum0=0,sum1=0;
    int final;
    for(i=0;i<=n-1;i++){
        scanf("%d",&date[i]);
        if(date[i]==0){
            sum0++;
        }else{
            sum1++;
        }
    }
    final=(100+r+(sum0-sum1))%4;
    if(final==0) printf("North");
    if(final==1) printf("West");
    if(final==2) printf("South");
    if(final==3) printf("East");
    return 0;
}