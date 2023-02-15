#include <iostream>
/*
考虑不重复(不计算排序)的数字组成，并输出他们的排列，我卡了很久的地方在于如何继承之前的数据以及m的运用

*/
using namespace std;
int sum=0;
int data[101][102];
int cnt[101];
//用以计数
int h=0;

int wq_dfs(int left,int start,int *temp,int m);
void output();

int main(){
    int temp[101]={0};
    int n;cin>>n;

    wq_dfs(n,1,temp,0);
    //cout<<sum<<endl;
    output();

    return 0;
}

//针对不会重复的情况
int wq_dfs(int left,int start,int *temp,int m){

    int i;
    if(left==0){
        for(int i=0;i<=m-1;i++){
            data[sum][i]=temp[i];
        }
        cnt[sum]=m;
        sum++;
    }else{
        for(i=start;i<=left;i++){
            //这里出问题了   cnt[sum]++一直在加
            temp[m]=i;
            wq_dfs(left-i,i,temp,m+1);
        }
    }
    return 0;
}

void output(){
    for(int i=0;i<=sum-2;i++){
        cout<<data[i][0];
        for(int j=1;j<=cnt[i]-1;j++)
            cout<<"+"<<data[i][j];
        cout<<endl;
    }
}