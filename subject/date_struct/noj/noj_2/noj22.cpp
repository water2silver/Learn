#include <iostream>
using namespace std;/*
Dijkstra算法 感觉离散数学教的那个思路更好玩一点


*/

int G[102][102]={0};
int n;int m;
int short_my[102]={0}; 
int mask[102]={0};
int Start=1;
void Dijkstra();
int find_min_temp(int *data,int length);

int main(){
    cin>>n>>m;
    int a,b;
    for(int i=1;i<=m;i++){
        int temp;
        cin>>a>>b>>temp;
        G[a][b]=temp;
    }
    //不可达，则认为距离是10000
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(G[i][j]==0){
                G[i][j]=10000;
            }
        }
    }
    mask[Start]=1;
    Dijkstra();
    for(int i=2;i<=n;i++){
        if(short_my[i]==0){
            short_my[i]=10000;
        }
    }
    int mask2[102]={0};
    int MIN=10001,pos=0;
    for(int i=1;i<=n-1;i++){
        for(int j=2;j<=n;j++){
            if(mask2[j]==0&&short_my[j]<MIN){
                MIN=short_my[j];
                pos=j;
            }
        }

        mask2[pos]=1;
        if(MIN!=10000)
            cout<<"1 "<<pos<<" "<<MIN<<endl;
        else{
            cout<<"1 "<<pos<<" "<<-1<<endl;
        }
        MIN=10001;
    }


    

    return 0;
}/*
6 11
1 2 50
1 3 10
1 5 45
2 3 15
2 5 10
3 1 20
3 4 15
4 2 20
4 5 35
5 4 30
6 4 3


*/

void Dijkstra(){
    int temp[102];
    for(int i=1;i<=101;i++){
        temp[i]=10000;
    }
    for(int i=1;i<=n;i++){
        if(G[Start][i]<temp[i]){
            temp[i]=G[Start][i];
        }
    }
    //开始操作操作n-1次即可
    for(int i=1;i<=n-1;i++){
        int pos=find_min_temp(temp,n);
        for(int j=1;j<=n;j++){
            if((short_my[pos]+G[pos][j])<temp[j]){
                temp[j]=short_my[pos]+G[pos][j];
            }
        }

    }

}

int find_min_temp(int *data,int length){
    int min=999,pos;
    for(int i=1;i<=length;i++){
        if(mask[i]==0&&data[i]<min){
            min=data[i];
            pos=i;
        }
    }
    mask[pos]=1;
    short_my[pos]=data[pos];
    return pos;
}