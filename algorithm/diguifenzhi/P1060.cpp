#include <iostream>
#include <iomanip>
using namespace std;
/*
动态规划解法，我暴露的i,j部分，存储数据的变量乱用的问题
可以继续优化吗？
*/

int m,n;
int data[28][30002];
int v[30];
int p[30];

void output();

int main(){
    
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>p[i];
        p[i]*=v[i];
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=m;i++){
            if(i>=v[j]){
                data[j][i]=max(data[j-1][i],data[j-1][i-v[j]]+p[j]);
            }else{
                data[j][i]=data[j-1][i];
            }
        }
    }
    //output();
    cout<<data[n][m]<<endl;

    return 0;
}
// b 表示对应的大小， a表示前几个物品

void output(){
    for(int i=1;i<=n;i++){
        cout<<setw(5)<<v[i]<<" ";
    }cout<<endl;
}