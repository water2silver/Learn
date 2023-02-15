#include <stdio.h>
#include <math.h>
/*
小蒜有两个数，这两个正整数的最大公约数是 G，最小公倍数是L，它们的和最小是多少？
即根据两个数字的最大公约数和最小公倍数求他们这两个数字和的关系
*/

int Mygcd(int a,int b);
int main(){
    int G,L,i,j,k;
    scanf("%d %d",&G,&L);
    int temp=L/G;
    /*
    xy=temp;
    min(14(x+y))
    */
   for(i=sqrt(temp);i>=1;i--){
       j=temp/i;
       if(i*j==temp&&Mygcd(j,i)==1){//何时满足条件
           printf("%d",G*(i+j));
           break;
       }
   }
    return 0;
}

int Mygcd(int a,int b){
    int temp;int res;
    //保证a>b;
    if(a<b){
        temp=a;
        a=b;
        b=temp;
    }
    if(a%b==0) res=b;
    else{
        a=a%b;
        res=Mygcd(b,a);
    }
    return res;
}