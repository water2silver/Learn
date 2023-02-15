#include <iostream>
/*
错解之两次动态规划
0 6 4
3 5 2
0 2 0
两次最优 之后导致 3被丢下，如果不按照最优走，则可以把所有数字都拿下来
*/
using namespace std;
int data[10][10];
int n;
int sum=0;
int road[20];

//如何 去回溯这样的路径?
void dfs(int a,int b,int am,int step,int *path);

void output_road();

void set_zero();

int main(){
    //数据读入
    int path[20];
    cin>>n;
    while(1){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==b&&b==c&&c==0){
            break;
        }else{
            data[a][b]=c;
        }
    }
    int res=0;
    dfs(1,1,0,1,path);
    res=sum;
    set_zero();
    sum=0;
    dfs(1,1,0,1,path);
    res+=sum;
    cout<<res<<endl;


    return 0;
}

//先试试一条路的
void dfs(int a,int b,int am,int step,int *path){
    if(a<n&&b<n){
        path[step]=1;
        dfs(a+1,b,am+data[a+1][b],step+1,path);
        path[step]=0;
        dfs(a,b+1,am+data[a][b+1],step+1,path);
    }else if(a==n&b<n){
        path[step]=0;
        dfs(a,b+1,am+data[a][b+1],step+1,path);
    }else if(b==n&&a<n){
        path[step]=1;
        dfs(a+1,b,am+data[a+1][b],step+1,path);
    }else if(a==b&&a==n){
        //终点
        if(am>sum){
            sum=am;
            for(int i=1;i<=2*n-2;i++){
                road[i]=path[i];
            }
        }
    }
}

void output_road(){
    for(int i=1;i<=2*n-2;i++){
        cout<<road[i]<<" ";
    }
    cout<<endl;
}
void set_zero(){
    int a=1,b=1;
    data[a][b]=0;
    for(int i=1;i<=2*n-2;i++){
        if(road[i]==1) a++;
        else b++;
        data[a][b]=0;
    }
}