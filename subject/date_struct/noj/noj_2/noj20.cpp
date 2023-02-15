#include <iostream>
using namespace std;
int Graph[102][102]={0};
int mask[101]={0};
int n,m;
//写一个栈
typedef struct Stack__my{
    int data[1001];
    int top=0;
    int tail=0;
    int length=0;
}Stack_my;
Stack_my s;

void bfs(int a,int b);

int main(){
    cin>>n>>m;
    int c[102];
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    int a,b;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        Graph[a][b]=1;
    }
    cin>>a>>b;
    mask[a]=1;
    s.data[s.tail]=a;
    s.length++;
    s.tail++;
    while(s.top!=s.tail){
        for(int i=1;i<=n;i++){
            bfs(s.data[s.top],i);
        }
        s.top++;
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

void bfs(int a,int b){
    if(Graph[a][b]==1&&mask[b]==0){
        mask[b]=1;
        s.data[s.tail]=b;
        s.length++;
        s.tail++;
    }
}