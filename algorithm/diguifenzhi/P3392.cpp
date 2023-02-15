#include <iostream>
#include <iomanip>

/*涂国旗
把国旗按照行划分为 1,i   i+1,j    j+1,m
遍历所有方法数所需要涂染数目，输出最小值

*/

using namespace std;
//结果
int res=3000;
//标志i j的存储
int x,y;
int m,n;
char flag[55][55];
int cent[55][4];

//遍历i j
void solve();
//计算这种划分下的i j数目
int color(int a,int b);
int test1();

int main(){
    //读入 初步处理
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>flag[i]+1;
        for(int j=1;j<=n;j++){
            if(flag[i][j]=='W'){
                cent[i][1]++;
            }else if(flag[i][j]=='B'){
                cent[i][2]++;
            }else if(flag[i][j]=='R'){
                cent[i][3]++;
            }
        }
    }
    solve();
    //test
    //test1();

    cout<<res<<endl;
    //cout<<x<<" "<<y<<endl;
    return 0;
}
void solve(){
    //1-i i+1——j-1 j-m
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m-1;j++){
            
                int temp=color(i,j);
                if(res>temp){
                    res=temp;
                    x=i;y=j;
                }
            
        }
    }
}

int color(int a,int b){
    int sum=0;
    for(int i=1;i<=m;i++){
        if(i<=a)
            sum+=cent[i][2]+cent[i][3];
        else if (i<=b){
            sum+=cent[i][1]+cent[i][3];
        }else if(i<=m){
            sum+=cent[i][1]+cent[i][2];
        }
    }
    return sum;

}
int test1(){
    for(int i=1;i<=m;i++){
        cout<<setw(3)<<cent[i][1]<<setw(3)<<cent[i][2]<<setw(3)<<cent[i][3]<<endl;
    }cout<<endl;
    return 1;
}