#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,m,date[1000]={0};
    int i,j,k;
    scanf("%d %d",&n,&m);

    for(i=0;i<=n-1;i++){
        scanf("%d",&date[i]);
    }
    int flag=0,final=0;
    int cent=0;
    //printf("%d",date[2]);
    for(i=0;i<=n-1;i++){
        for(j=i+1;j<=n-1;j++){
            if(date[i]<date[j]){
                flag=1;
                break;
            }
        }
        if(flag==0) {
            date[i]=0;
            cent++;
            if(i==m){
                final=1;
            }
        }
        else {
            date[n++]=date[i];
            date[i]==0;
            flag=0;
            if(i==m){
                m=n-1;
            }
        }
        
        if(final==1){
            break;
        }
    }

    printf("%d",cent);
    return 0;
}