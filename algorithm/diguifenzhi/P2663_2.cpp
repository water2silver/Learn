#include <iostream>

using namespace std;

int n;
int sum;
int data[105];
int res[102][10010];
void package();

int main(){
    //数据读入
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>data[i];
        sum+=data[i];
    }
    
    package();
    for(int i=sum/2;i>=0;i--){
        if(res[n/2][i]){
            cout<<i;
            break;
        }else if(res[(n+1)/2][i]){
            cout<<i;
            break;
        }
    }


    return 0;
}
void package(){
    for(int i=0;i<=(n+1)/2;i++){
        res[i][0]=1;
    }

    for(int i=1;i<=n;i++){
        //区别是什么？]
        //for(int j=(n)/2;j>=1;j--)
        for(int j=i;j>=1;j--){
            for(int k=sum/2;k>=data[i];k--){
                res[j][k]|=res[j-1][k-data[i]];
            }
        }
    }
}