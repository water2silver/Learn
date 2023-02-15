#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void QS(int *A,int n,int left,int right);
void quick_sort(int s[], int l, int r);

int main(){
    int i;
    int date[20];
    srand(1);
    for(i=0;i<=19;i++){
        date[i]=rand()%100;
        printf("%d ",date[i]);
    }
    printf("\n");
    QS(date,20,0,19);
    //quick_sort(date,0,19);
    for(i=0;i<=19;i++) printf("%d ",date[i]);

    return 0;
}

void QS(int *A,int n,int left,int right){
    int i,j,k,X;
    if(left<right){
        X=A[left];
        i=left;j=right;
        while(i<j){
            while(A[j]>X) {j--;}
            if(j>i) {
                A[i]=A[j];
                i++;
            }
            while(i<j&&A[i]<X) {i++;}
            if(j>i){
                A[j]=A[i];
                j--;
            }
        }
        A[i]=X;
        QS(A,n,left,i-1);
        QS(A,n,i+1,right);
    }
}
void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
        //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
                j--;  
            if(i < j) 
                s[i++] = s[j];
            
            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                i++;  
            if(i < j) 
                s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // 递归调用 
        quick_sort(s, i + 1, r);
    }
}