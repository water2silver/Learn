#include <iostream>
/*
1.
也应该归属于背包问题？
跟疯狂采药相似点在于某些物品可以多次选择，
但是选择次数有限

用map来写?

2.筛法，把所有可能的结果都找出来，
事实上这里采用了筛法，把所有的答案都筛选出来了
这些题目一个很有意思的点在于，for 循环的正序和倒序对数组的改变是不一样的，这个地方理解很重要
以及，如何用for循环实现对有限次操作，正如
*/
#include <map>
using namespace std;
//1 2 3 5 10 20


int a[7];
int data[]={0,1,2,3,5,10,20};
int ans[1010];

int main(){
    //读入数据
    int num=0;
    for(int i=1;i<=6;i++){
        cin>>a[i];
    }
    ans[0]=1;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=a[i];j++){
            for(int k=1000;k>=0;k--){
                if(ans[k]){
                    //ans[k+j*data[i]]=1;是错的，可能你选择操作的数已经被加过多次data[i]了
                    ans[k+data[i]]=1;
                }
            }
        }
    }
    int final=0;
    for(int i=1;i<=1000;i++){
        if(ans[i]){
            final++;
        }
    }
    cout<<"Total="<<final<<endl;

    return 0;
}
