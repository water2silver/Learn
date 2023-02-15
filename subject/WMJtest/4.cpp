#include <stdio.h>
#include <math.h>

int main(){
    int num,i,time;double res=0;
    scanf("%d",&num);
    double a,b;
    double c;
    for(i=1;i<=num;i++){
        scanf("%lf %lf %lf",&a,&b,&c); 
        double temp=sqrt(a*a+b*b);
        res=2*temp/50+res+c*1.5;
    }
    int final=res;
    if(final<res){
        final++;
    }
    printf("%d",final);
}