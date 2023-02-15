#include <stdio.h>
int main() {
    typedef struct st_u{
        int xuehao;
        int gra1;
        int gra2;
        double all;
    }stu;
stu a[1001];
int n,i,j;
scanf("%d",&n);
for(i=0;i<=n-1;i++){
    scanf("%d",&a[i].xuehao);
    scanf("%d",&a[i].gra1);
    scanf("%d",&a[i].gra2);
    a[i].all=0.7*a[i].gra1+0.3*a[i].gra2;

}
for(i=0;i<=n-1;i++){
    if(a[i].gra1+a[i].gra2>140&&a[i].all>=80){
        printf("Excellent\n");    
    }
    else{






        
        printf("Not excellent\n");
    }
}
return 0;
}