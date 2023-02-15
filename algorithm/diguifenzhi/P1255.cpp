#include <iostream>
/*
1255 高精度加法



*/
using namespace std;
int n;
long long res[5200];
void solve();

int main(){
    cin>>n;
    res[1]=1;
    res[2]=2;
    solve();
    cout<<res[n];

    return 0;
}
void solve(){
    for(int i=3;i<=n;i++){
        res[i]=res[i-1]+res[i-2];
    }


}