#include <iostream>
#include <math.h>
using namespace std;
/*
C了...

*/
int data[18][100010];
int n;

int dp(int a,int b);
int getSqrt4(int num);

int main(){
    cin>>n;
    int temp=getSqrt4(n);
    int res=dp(temp,n);
    cout<<res<<endl;
    return 0;
}

int dp(int a,int b){
    if(data[a][b]!=0){
        return data[a][b];
    }else if(b==0){
        data[a][b]=0;
        return 0;
    }else if(a==1){
        data[a][b]=b;
        return b;
    }else{
        data[a][b]=min(1+dp(getSqrt4(b-a*a*a*a),b-a*a*a*a),dp(a-1,b));
        return data[a][b];
    }
}

int getSqrt4(int num){
    return floor(sqrt(sqrt(num)));
}