#include <iostream>
#include <queue>
using namespace std;

//+1*2平方
queue <int> q;
int start,target;
int step[10010];
int used[10010];

int main(){
    cin>>start>>target;


    return 0;
}

int bfs(){
    int u,v,i;
    while(!q.empty()){
        u=q.front();q.pop();
        for(i=0;i<=2;i++){
            if(canmoveto(u,i)){
                v=moveto(u,i);
                if(v==target){
                    return step[u]+1;
                }else{
                    step[v]=step[u]+1;
                    used[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
//判断计算后的v是否合法
void canmoveto(int u,int i){

}
//计算v
void moveto(int u,int i){

}