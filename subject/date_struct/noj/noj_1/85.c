#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//why I am incorrect ?
/*
int main(){
    int i,j;
    double k,b;
    int x1,x2,x3,y1,y2,y3;
    scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
    k=(double)(y1-y2)/(double)(x1-x2);
    b=(double)y1-k*(double)x1;
    if(x1-x2==0&&y1>y2){
        if(x3>x1){
            printf("0");
            return 0;
        }
        else{
           printf("1");
            return 0; 
        }
    }
    else if(x1-x2==0&&y2>y1){
        if(x3>x1){
            printf("1");
            return 0;
        }
        else{
           printf("0");
            return 0; 
        }
    }
    else if(x1>x2){
        if(k>=0){
            if(k*x3-y3+b>0){
                printf("0");
                return 0;
            }
            else {
                printf("1");
                return 0;
            }
        }
        if(k<0){
            if(k*x3-y3+b>0){
                printf("1");//修改
                return 0;
            }
            else {
                printf("0");
                return 0;
            }
        }
    }
    else if(x1<x2){
        if(k>=0){
            if(k*x3-y3+b>0){
                printf("1");
                return 0;
            }
            else {
                printf("0");
                return 0;
            }
        }
        if(k<0){
            if(k*x3-y3+b>0){
                printf("0");
                return 0;
            }
            else {
                printf("1");
                return 0;
            }
        }
    }
}*/
int main(){
    int i,j;
    double k,b;
    int x1,x2,x3,y1,y2,y3;
    scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
    int t=(x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
    if(t>0) printf("0");
    else printf("1");

}