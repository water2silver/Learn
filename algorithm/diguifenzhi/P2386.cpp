#include <iostream>
/*有错误,样例就出错*/
using namespace std;
int n,data[30][2];
int num[10];


int dfs(int start,int pos,int left);
int solve();

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>data[i][0]>>data[i][1];
    }
    solve();

    return 0;
}
int solve(){
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=data[i][1];j++){
            for(int k=1;k<=data[i][0]-data[i][1]+1;k++){
                sum+=dfs(k,j,data[i][0]);
            }
        }
        cout<<sum<<endl;
    } 
    return 1;
}

//会不会有算多了的情况?
int dfs(int start,int pos,int left){
    if((left==0)&&(pos==0)){
        return 1;
    }else if(pos==0||left==0){
        return 0;
    }
    else{
        int sum=0;
        for(int i=start;i<=left;i++){
            sum+=dfs(i,pos-1,left-i);
        }
        return sum;
    }

}