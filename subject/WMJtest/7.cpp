#include <stdio.h>

/*开关灯问题
数据量小，可硬算
容斥原理？
联想：关于快速求解质数的问题

*/
int main(){
    int data[1010]={0};//让0表示开灯
    int n;scanf("%d",&n);
    int res=n;
    //三个for循环，每个循环一个if或者一个循环内三个if
    for(int j=3;j<=7;j=j+2){
        for(int i=1;i<=n;i++){
            if(i%j==0){
                if(data[i]==0){
                    data[i]=1;
                    res--;
                }
                else if(data[i]==1){
                    data[i]=0;
                    res++;
                }
            }
        }
    }
    printf("%d",res);
    return 0;
}