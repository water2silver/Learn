#include <iostream>
#include <iomanip>
using namespace std;

int data[10];
int n;int cnt=0;
void dfs(int num,int u);
int check_num(int num,int u);

int main(){
    cin>>n;
    dfs(n,0);

    return 0;
}

void dfs(int num,int u){

    for(int i=1;i<=num;i++){
        if(check_num(i,u)==1){
            cnt++;
            data[u+1]=i;
            if(u+1==n){
                for(int j=1;j<=n;j++){
                    cout<<setw(5)<<data[j];
                }
                cout<<endl;
            }else{
                dfs(num,u+1);
            }
        }       
    }
}

int check_num(int num,int u){
    for(int i=1;i<=u;i++){
        if(num==data[i]){
            return 0;
        }
    }
    return 1;

}