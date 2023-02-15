#include <stdio.h>
int math_t(int n,int m);
int main(){
    int n,m,i,j;
    scanf("%d",&n);int k=0;
    for(i=n-1;i>=0;i--){
        for(k=i;k<n-1;k++){
            printf(" ");
        }
        for(j=0;j<=i;j++){
            if(j==i) printf("%d\n",math_t(j,i));
            else printf("%d ",math_t(j,i));
        }
    }

    return 0;
}

int math_t(int n,int m){
    int res=1;
    if(m==0) return 1;
    if(n==0) return 1;
    int i,j;
    for(i=m,j=1;i>=m-n+1;i--,j++){
        res=res*i/j;
    }
    return res;
}