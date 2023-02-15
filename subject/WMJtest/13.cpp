#include <iostream>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long temp1,temp;
    long long left=5,right=5*n;
    long long num=0;int i=33;
    while(1){
        i--;
        num=0;
        temp=(left+right)/2;
        temp1=temp;
        while(temp){
            temp=temp/5;
            num+=temp;
        }
        if(num>n){
            right=temp1;
        }else if(num<n){
            left=temp1+1;
        }else break;
        //程序在某个地方死循环了
        if(i==0) break;

    }
    cout<<(temp1-temp1%5)<<endl;
}