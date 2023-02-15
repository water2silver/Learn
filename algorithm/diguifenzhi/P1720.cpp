#include <iostream>

using namespace std;
long long data[100];

long long Feb2(int n){
    return data[n-1]+data[n-2];
}

int Feb(int n){
    if(n==1||n==2){
        return 1;
    }else{
        return Feb(n-1)+Feb(n-2);
    }
}


int main(){
    data[1]=1;data[2]=1;
    long long n;cin>>n;
    for(int i=3;i<=n-1;i++){
        data[i]=Feb2(i);
    }

    cout<<Feb2(n)<<".00"<<endl;


}