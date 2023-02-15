#include <iostream>
/*数的拆分
例子:拆分3
1 1 1,
1 2,
2 1.

老师的思路：建立树的思路
*//*拓展
如果2 1，1 2视为一种情况该如何思考?

*/


using namespace std;
int sum=0;
int data[101][102];
int cnt[101];
//用以计数
int h=0;

void solve(int num);
int wq_dfs(int left,int start);


int main(){
    int n;cin>>n;
    cout<<sum<<endl;

    return 0;
}
void solve (int num){
    if(num==0){
        sum++;
    }else{
        for(int i=1;i<=num;i++){
            solve(num-i);
        }
    }
}

//针对不会重复的情况
int wq_dfs(int left,int start){
    int i;
    if(left==0){
        sum++;
    }else{
        for(i=start;i<=left;i++){
            wq_dfs(left-i,i);
        }
    }
    return 0;
}

