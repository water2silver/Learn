#include<iostream>
/*
未完成
dp背包？
当我在平板上写下几个数字之后，我居然产生了思路？所以说，要动手，别光看着

思路：
ans[a][b]=dp(a-1,b-data[a])+dp(a-1,b);
ans[a][b]=dp(a-1,b);
选择前a个菜品，有b钱的时候，此时建立于(a-1,b-data[a])和(a-1,b)的联系
*/
using namespace std;
int n,m;
int data[105];
int res;
int ans[103][10010];
bool flag[103][10010];

int dp(int a,int b);

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>data[i];
    }

    res=dp(n,m);
    cout<<res<<endl;

}

//a表示用前n个数字,b表示剩余容量
int dp(int a,int b){

    if(flag[a][b]){
        
    }else if(b==0){
        return 1;
    }else if(a==0){
        return 0;
    }else{
        if(b>=data[a]){
            //
            ans[a][b]=dp(a-1,b-data[a])+dp(a-1,b);
            flag[a][b]=1;
        }else if(b<data[a]){
            ans[a][b]=dp(a-1,b);
            flag[a][b]=1;
        }
    }
    return ans[a][b];
}