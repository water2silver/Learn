#include <stdio.h>

int main(){
    int n,i,j;
    int data[50010];
    scanf("%d",&n);
    for (i=1;i<=n;i++){
        scanf("%d",&data[i]);
    }
    scanf("%d",&n);
    int a,b;
    for(i=0;i<=n-1;i++){
        long long res=0;
        scanf("%d %d",&a,&b);
        for(j=a;j<=a+b-1;j++){
            res+=data[j];
        }
        printf("%lld\n",res);
    }
    return 0;
}