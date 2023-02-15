#include <iostream>
/*
使用背包算法，不一定需要直接得到答案
这里使用的是三位的背包,表示从前i个学生中挑选j个学生，能否组成k的成绩
*/
using namespace std;

int n;
int data[105];
int res[102][51][5100];
int sum;

int main(){

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>data[i];
        sum+=data[i];
    }
    //初始化
    for(int i=0;i<=n;i++){

        for(int j=0;j<=i;j++){
            res[i][j][0]=1;
        }
    }

    //实际操作
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            for(int k=1;k<=sum/2;k++){
                if(k>=data[i])
                    res[i][j][k]=res[i-1][j][k]|res[i-1][j-1][k-data[i]];
                else 
                    res[i][j][k]=res[i-1][j][k];
            }
        }
    }
    for(int i=sum/2;i>=0;i--){
        if(n%2==0){
            if(res[n][n/2][i]){
                cout<<i;
                break;
            }
        }
        //
        else if(res[n][n/2][i]){
            cout<<i;
            break;
        }else if(res[n][n/2+1][i]){
            cout<<i;
            break;
        }
    }
}
