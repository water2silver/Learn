#include <iostream>
/*
典型二维背包问题，由简单问题解决到复杂问题
尝试使用new delete进行内存的动态管理

*/
using namespace std;
int T,M;
int herb[10010][3];


void package_improve(long long **V);

int main(){
    //T为时间,M是容量
    cin>>T>>M;
    for(int i=1;i<=M;i++){
        cin>>herb[i][1]>>herb[i][2];
    }

    //package();

    //动态数组初始化
    long long **V=new long long*[M+1];
    for(int i=0;i<=M;i++){
        V[i]=new long long [T+1];
    }
    //置0 
    for(int i=0;i<=T;i++){
        V[0][i]=0;
    }
    for(int i=0;i<=M;i++){
        V[i][0]=0;
    }

    package_improve(V);

    cout<<V[M][T]<<endl;
    //cout<<value[M][T]<<endl;


    return 0;
}



void package_improve(long long **V){
    //第一行初始化
    for(int i=1;i<=T;i++){
        if(herb[1][1]<i){
            V[1][i]=herb[1][2]+V[1][i-herb[1][1]];
        }else{
            V[1][i]=0;
        }
    }

    //i为可选草药种类,j为可用空间
    for(int i=2;i<=M;i++){
        
        for(int j=1;j<=T;j++){
            if(herb[i][1]>j){
                V[i][j]=V[i-1][j];
            }else {
                V[i][j]=max(herb[i][2]+V[i][j-herb[i][1]],V[i-1][j]);
            }
        }
        delete[] V[i-2];
    }
}