#include <iostream>
/*



*/
using namespace std;
int n;
int data[30][2];
int book[30];
int cnt;

void dfs(int a);
int main(){
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>data[i][0]>>data[i][1];
    }
    dfs(1);
    cout<<cnt<<endl;


    return 0;
}
void dfs(int a){
    if(a==n+1){
        cnt++;
        return ;
    }
    if(book[data[a][0]]==1&&book[data[a][1]]==1){
        return ;
    }
    if(book[data[a][1]]==0){
        book[data[a][1]]=1;
        dfs(a+1);
        book[data[a][1]]=0;
    }
    if(book[data[a][0]]==0){
        book[data[a][0]]=1;
        dfs(a+1);
        book[data[a][0]]=0;
    }
}