#include <iostream>
/*
01背包，需要自己确定物品

*/
using namespace std;

int data[1002];
int res[1010][1010];

int S;

void init();
void package();

int main(){
    cin>>S;
    init();
    package();
    cout<<res[S][S]<<endl;

    return 0;
}

void package(){
    for(int i=1;i<=S;i++){
        for(int j=1;j<=S;j++){
            if(j>=i){
                res[i][j]=max(data[i]+res[i-1][j-i],res[i-1][j]);
            }else if(j<i){
                res[i][j]=res[i-1][j];
            }
        }
    }
}



void init(){
    
    for(int i=1;i<=S;i++){
        int sum=1;
        for(int j=2;j<=(i+1)/2;j++){
            if(i%j==0){
                sum+=j;
            }
        }
        data[i]=sum;
    }
    data[1]=0;
}