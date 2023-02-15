#include <iostream>
/*数字阶梯
虽然题目是自上往下走，但是从结果出发更容易建议递归关系


*/
using namespace std;

int n;
int data[1010][1010];
int solution[1010][1010];
void solve();


int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>data[i][j];
            if(i==n){
                solution[i][j]=data[i][j];
            }
        }
        
    }
    solve();

    cout<<solution[1][1]<<endl;
    return 0;




}


void solve(){
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            
            solution[i][j]=data[i][j]+max(solution[i+1][j],solution[i+1][j+1]);
            
        }
    }



}