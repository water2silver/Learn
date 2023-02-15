#include <iostream>
#include <stdlib.h>
#include <iomanip>
/*快速排序*/
using namespace std;
void output(int *a, int s, int e);
void Quick_Sort(int *a, int L, int R);

int main()
{
    srand(1026);
    int n;
    int a[25];
    for (int i = 0; i <= 20; i++)
    {
        a[i] = rand() % 100;
    }
    output(a,0,20);
    Quick_Sort(a,0,20);
    output(a,0,20);

    return 0;
}
void output(int *a, int s, int e)
{
    for(int i=s;i<=e;i++)
    {
        cout<<setw(4)<<a[i];
    }cout<<endl;
}
void Quick_Sort(int *a, int L, int R)
{
    if (L >= R)
        return;
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