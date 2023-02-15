#include <iostream>
/*
一维数组薄纱！


*/
using namespace std;

int T,M;
long long value[10000010];
int herb[10010][3];

int main(){
    //T为时间,M是容量
    cin>>T>>M;
    for(int i=1;i<=M;i++){
        cin>>herb[i][1]>>herb[i][2];
    }
    for(int i=1;i<=M;i++){
        for(int j=herb[i][1];j<=T;j++){
            value[j]=max(value[j],value[j-herb[i][1]]+herb[i][2]);
        }
    }
    cout<<value[T]<<endl;


}