#include <iostream>
/*路径回溯*/
using namespace std;
int sum=0;
int data[101][102];
int cnt[101];


void solve2 (int num,int* temp,int m);
void output();

int main(){
    int temp[101]={0};
    int n;cin>>n;

    solve2(n,temp,0);

    output();
    return 0;
}

//输出所有拆分，要去继承一个数组？
void solve2 (int num,int* temp,int m){

    if(num==0){
        //这里把传来的数组进行复制
        for(int i=0;i<=cnt[sum]-1;i++){
            data[sum][i]=temp[i];
        }
        sum++;

    }else{
        //cnt的计算也出错了
        for(int i=1;i<=num;i++){
            if(cnt[sum]==0){
                cnt[sum]=m;
            }
            temp[cnt[sum]++]=i;
            solve2(num-i,temp,m+1);
        }
    }
}
void output(){
    for(int i=0;i<=sum-1;i++){
        cout<<data[i][0];
        for(int j=1;j<=cnt[i]-1;j++)
            cout<<"+"<<data[i][j];
        cout<<endl;
    }
}