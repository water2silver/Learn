#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int jc(int n);
int main(){
    int n,i,j;
    scanf("%d",&n);
    int sym=0,t=0;
    int flag=0;
    for(;;){
        for(i=0;;i++){
            if(jc(i)<=n&&jc(i+1)>n){
                if(t!=i){
                    t=jc(i);
                    sym=i;
                    break;
                }else{
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1){
            printf("NO");
            break;
        }
        n=n-t;
        if(n==0||n==1||n==2){
            printf("YES");
            break;
        }

    }

}
int jc(int n){
    int i=0,res=1;
    for(i=1;i<=n;i++){
        res=res*i;
    }
    return res;
}