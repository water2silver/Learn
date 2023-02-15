#include <iostream>
using namespace std;
int Graph[102][102]={0};
int mask[101]={0};
int n,m;
void dfs(int a,int b);
int main(){

    cin>>n>>m;
    int c[102];
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        Graph[a][b]=1;
    }
    int a,b;
    cin>>a>>b;
    mask[a]=0;
    for(int i=1;i<=n;i++){
        dfs(a,i);
    }
    if(mask[b]==1){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }


    return 0;
}
/*
4 4
1 2 3 4
1 4
1 3
4 2
2 3
1 2
*/
void dfs(int a,int b){
    if(Graph[a][b]==1&&mask[b]!=1){
        mask[b]=1;
        for(int i=1;i<=n;i++){
            dfs(b,i);
        }
    }
}