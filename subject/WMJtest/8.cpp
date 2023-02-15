#include <stdio.h>
#include <math.h>
/*一次函数求解问题

*/
int Mygcd(int a,int b);

int main(){
    int x1,y1,x2,y2;
    scanf("%d %d",&x1,&y1);
    scanf("%d %d",&x2,&y2);
    int k,b,temp1,temp2;
    int k1,k2,b1,b2;
    k1=y1-y2;k2=x1-x2;
    //排除掉两种特殊情况
    if(k2==0) {
        printf("x=%d",x1);
        return 1;
    }
    if(k1==0){
        printf("y=%d",y1);
        return 1;
    }
    //需要讨论正负号的问题

    temp1=Mygcd(abs(k1),abs(k2));
    b1=x1*y2-x2*y1;
    b2=x1-x2;
    if(b1!=0)
        temp2=Mygcd(abs(b1),abs(b2));
    if(k1*k2>0){//x后面常数的符号在下个if写吧
        if(abs(k2/temp1)!=1)
            printf("y=%d/%d*x",abs(k1/temp1),abs(k2/temp1));
        else {
            if(abs(k1/temp1)!=1){
                printf("y=%dx",abs(k1/temp1));
            }else{
                printf("y=x");
            }
        }
    }else if(k1*k2<0){
        if(abs(k2/temp1)!=1)
            printf("y=-%d/%d*x",abs(k1/temp1),abs(k2/temp1));
        else {
            if(abs(k1/temp1)!=1){
                printf("y=-%dx",abs(k1/temp1));
            }else{
                printf("y=-x");
            }
        }
    }
    if(b1!=0){
        if(b1*b2>0){
            if(abs(b2/temp2)==1){
                printf("+%d",abs(b1/temp2));
            }else {
                printf("+%d/%d",abs(b1/temp2),abs(b2/temp2));
            }
        }else{
            if(abs(b2/temp2)==1){
                printf("-%d",abs(b1/temp2));
            }else {
                printf("-%d/%d",abs(b1/temp2),abs(b2/temp2));
            }
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