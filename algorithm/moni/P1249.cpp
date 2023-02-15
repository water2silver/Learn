#include<iostream>
using namespace std;
/*把一个数字拆分成为任意个数字之和，并且使这样的数字相乘之积最大

*/
int data[10010];
int ans[1010];
int s[1010];
int t=1;

void test(int n);
void multi(int n){
    int i=1,j=1,k,m=0;
    int r;
    for(j=1;j<=t;j++){
        ans[j]=ans[j]*n;
    }
    for(j=1;j<=t;j++){
        if(ans[j]>9){
            k=ans[j]/10;
            ans[j+1]+=k;
            if(j+1>t){
                t++;
            }
            ans[j]=ans[j]%10;
        }
    }
    //test(n);
}
void test(int n){
    cout<<"n="<<n<<endl;
    for(int p=t;p>=1;p--){
        cout<<ans[p]<<" ";
    }
    cout<<endl;
}   

int main(){
    int n;
    cin>>n;
    int sum=0;int i=2;
    while(sum<n){
        sum+=i;
        data[i]=i;
        i++;
    }
    if((sum-n)==1){
        data[2]=0;
        data[i-1]++;
    }else{
        data[sum-n]=0;
    }
    ans[1]=1;
    for(int j=2;j<=i;j++){
        if(data[j]!=0){
            cout<<data[j]<<" ";
            multi(data[j]);
        }
    }
    
    cout<<endl;
    for(int j=t;j>=1;j--){
        cout<<ans[j];
    }
    return 0;
}