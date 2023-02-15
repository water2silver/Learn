#include <iostream>
#include <stdlib.h>
#include <iomanip>
/*快速排序*/
using namespace std;
void output(int *a, int s, int e);
void Quick_Sort(int *a, int L, int R);
void Quick_Sort2(int *a,int l,int r);
int Quick_Read();

int main()
{
    int n;
    int a[100100];
    cin>>n;
    for (int i = 0; i <= n-1; i++)
    {
        a[i]=Quick_Read();
    }
    Quick_Sort(a,0,n-1);
    output(a,0,n-1);

    return 0;
}
void output(int *a, int s, int e)
{
    for(int i=s;i<=e;i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
//这个是从洛谷上找的
// void Quick_Sort2(int *a,int l,int r)//应用二分思想
// {
//     int mid=a[(l+r)/2];//中间数
//     int i=l,j=r;
//     do{
//         while(a[i]<mid) i++;//查找左半部分比中间数大的数
//         while(a[j]>mid) j--;//查找右半部分比中间数小的数
//         if(i <= j)//如果有一组不满足排序条件（左小右大）的数
//         {
//             swap(a[i],a[j]);//交换
//             i++;
//             j--;
//         }
//     }while(i<=j);//这里注意要有=
//     if(l<j) Quick_Sort2(a,l,j);//递归搜索左半部分
//     if(i<r) Quick_Sort2(a,i,r);//递归搜索右半部分
// }

//这个是自己写的
void Quick_Sort(int *a, int L, int R)
{
    if (L >= R)
        return;
    //选取中间的数准备基准
    swap(a[L],a[(L+R)/2]);
    //选一个基准
    int x = a[L];
    int i = L, j = R;
    while (j > i)
    {
        while (a[j] > x && j > i)
        {
            j--;
        }
        if (j > i)
        {
            a[i] = a[j];
            i++;
        }

        while (a[i] < x && j > i)
        {
            i++;
        }
        if (j > i)
        {
            a[j] = a[i];
            j--;
        }
    }
    a[j] = x;
    Quick_Sort(a, L, j - 1);
    Quick_Sort(a, j + 1, R);
}

int Quick_Read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-'){
            f=-1;
        }
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}