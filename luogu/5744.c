#include <stdio.h>
#include <string.h>
int main(){
    typedef struct s_tu{
        char name[101];
        int age,gra;
    }stu;
    int n,i,j;
    stu a[101];
    scanf("%d",&n);
    for(i=0;i<=n-1;i++){
        scanf("%s",&a[i].name);
        scanf("%d",&a[i].age);
        scanf("%d",&a[i].gra);
    }
    for(i=0;i<=n-1;i++){
        printf("%s %d ",a[i].name,a[i].age+1);
        printf("%d\n",6*a[i].gra/5>=600?600:6*a[i].gra/5);
    }
}