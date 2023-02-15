#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Quicksort(int A[],int n,int left,int right);
void QS(int *A,int n,int left,int right);
inline int read();
int main(){
    int T,n,i,j,k;
    int date[10000000];
    scanf("%d",&T);
    while(T--){
        int num=0;
        scanf("%d %d",&n,&k);
        for(i=0;i<=n-1;i++){//数据读入
            date[i]=read();
        }//看来得用快速排序
        //Quicksort(date,n,0,n-1);
        QS(date,n,0,n-1);
        printf("%d\n",date[k-1]);

    }




}
inline int read() {//快速读入，针对大量数据的读入方式
    char ch = getchar(); int x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    } while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } return x * f;
}
void Quicksort(int A[],int n,int left,int right){
/*目前接触到的最优秀的排序方法
边界情况处理的很漂亮，膜！

*/
    int i,j,t;
    if(left<right){//这个if其实暗藏了递归终止的条件
        i=left;j=right+1;
        while(1){
            while(i+1<n&&A[++i]<A[left]);
            while(j-1>-1&&A[--j]>A[left]);
            //i找到一个比A[left]大的才会停下来，j找到一个比A[left]小的才会停下来
            if(i>=j) break;
            t=A[i];A[i]=A[j];A[j]=t;
        }
        t=A[left];A[left]=A[j];A[j]=t;
        Quicksort(A,n,left,j-1);
        Quicksort(A,n,j+1,right);
    }

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