#include <iostream>
#include <iomanip>
using namespace std;
/*Dynamic Programming
dp[][];
核心:
如何想到去建立一个二维数组来解决这个问题的?动态规划的魅力
我们考虑n个A和n个B的排序问题太过于抽象，不妨考虑从n=1,n=2,的一些特殊情况入手
虽然问题要求我们是判断n n，但是必要的情况下考虑n n-1以及n-1 n 还是必要的，这是二维数组所必需的


实现：
1.从较小的特殊值出发，逐步构建大值的数组
2.或者向我之前一样，逐步往回调用。dp[a][b]=dfs(a-1,b)+dfs(a,b-1);

*/
int m,n;
long long dp[25][25];
//逐渐扩展的dp
void init();
void Dynamic(int a,int b);
//采用递归的dp
void init2();
int Dynamic_recursion(int a,int b);

void output();

int main(){
    cin>>n;
    m=2*n;
    // init();
    // Dynamic(n,n);

    init2();
    Dynamic_recursion(n,n);
    cout<<dp[n][n]<<endl;

    //output();
    
    return 0;
}
int Dynamic_recursion(int a,int b){
    if(a<b){
        dp[a][b]=0;
    }else{
        if(dp[a-1][b]==-1){
            Dynamic_recursion(a-1,b);
        } 
        if(dp[a][b-1]==-1){
            Dynamic_recursion(a,b-1);
        }
        dp[a][b]=dp[a-1][b]+dp[a][b-1];
    }
    return dp[a][b];
}
void init2(){
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }

    for(int i=1;i<=n;i++){
        dp[i][0]=1;
    }
    for(int j=0;j<=n;j++){
        dp[0][j]=0;
    }
}


void init(){

    for(int i=1;i<=n;i++){
        dp[i][0]=1;
    }
    for(int j=0;j<=n;j++){
        dp[0][j]=0;
    }
}

void Dynamic(int a,int b){
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    //dp[a][b]=dp[a-1][b]+dp[a][b-1];
}

void output(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<setw(5)<<dp[i][j];
        }cout<<endl;
    }
}