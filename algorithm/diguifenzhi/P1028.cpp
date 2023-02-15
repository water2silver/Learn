#include <iostream>
/*
把计算的结果储存在数组里面，用的时候直接调用，果然能提高效率

*/
using namespace std;
//本身也算
int data[1010];
//dfs没有充分利用计算得到的答案
int dfs(int n);
//这个利用相对充分一些
int dfs2(int n);

int main(){
    // data[1]=1;data[2]=2;data[3]=2;
    // data[4]=4;
    int n;cin>>n;
    // for(int i=1;i<=n;i++){
    //     cout<<"n= "<<i<<" ans = "<<dfs(i)<<endl;
    // }
    for(int i=1;i<=n/2;i++){
        data[i]=dfs2(i);
    }
    cout<<dfs2(n)<<endl;

    return 0;
}
int dfs2(int n){
    int s=0;
    for(int i=1;i<=n/2;i++){
        s+=data[i];
    }
    return s+1;

}
int dfs(int n){
    int s=0;

    for(int i=1;i<=n/2;i++){
        int temp=dfs(i);
        s+=temp;
    }
    return s+1;
}