#include<iostream>
using namespace std;
int data[10010];
int ans[1010];
int s[1010];
int t=1;

void multi(int n){
    int i=1,j=1,k,m=0;
    int r;
    for(j=1;j<=t;j++){
        ans[i]*=n;
    }
    for(j=1;j<=t;j++){
        if(ans[i]>9){
            k=ans[i]/10;
            ans[i+1]+=k;
            if(i+1>t){
                t++;
            }
            ans[i]=ans[i]%10;
        }
    }

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