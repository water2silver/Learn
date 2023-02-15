#include <iostream>
/*
并查集 如果我送set会简单嘛？
这个写法直接模拟（可以这么说吗？）题目的流程，在整个过程中浪费了很多时间

3个TLE 1个WA
*/
using namespace std;
int data[10010];
int N,M;
int cent=1;
//N个整数，M个操作
int main(){
    cin>>N>>M;
    for(int i=1;i<=M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            if(data[c]==0&&data[b]==0){
                
                data[c]=cent;
                data[b]=cent;
                //test
                
                cent++;
            }else if(data[c]==0&&data[b]!=0){
                data[c]=data[b];
            }else if(data[b]==0&&data[c]!=0){
                data[b]=data[c];
            }else{
                int temp=data[c];
                for(int j=1;j<=N;j++){
                    if(data[j]==temp){
                        data[j]=data[b];
                    }
                }
            }
        }else if(a==2){
            if(data[b]==data[c]&&data[b]){
                cout<<"Y"<<endl;
            }else{
                cout<<"N"<<endl;
            }
        }
    }

    //test
    // for(int i=1;i<=N;i++){
    //     cout<<data[i]<<endl;
    // }

    return 0;
}
