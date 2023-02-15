#include <iostream>
/*
典型二维背包问题，由简单问题解决到复杂问题


*/
using namespace std;
int T,M;
int herb[110][3];
int value[110][1010];
void package();

int main(){
    cin>>T>>M;
    for(int i=1;i<=M;i++){
        cin>>herb[i][1]>>herb[i][2];
    }

    package();

    cout<<value[M][T]<<endl;


    return 0;
}

void package(){
    for(int i=1;i<=M;i++){
        for(int j=1;j<=T;j++){
            if(j<herb[i][1]){
                value[i][j]=value[i-1][j];
            }else{
                value[i][j]=max(herb[i][2]+value[i-1][j-herb[i][1]],value[i-1][j]);
            }
        }

    }


}