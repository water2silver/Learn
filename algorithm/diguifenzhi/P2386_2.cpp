#include <iostream>
/*
定义dfs的时候，自己从main函数中进行了start值的循环，实际上我在dfs中也定义了start值的循环，
因此只有我在输出路径之后才发现了自己的错误


*/
using namespace std;
#define N 3
int n,data[30][2];
int num[10];
int cnt=0;
int number[20];
int dfs(int start,int pos,int left);
int solve();
void output();

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>data[i][0]>>data[i][1];
    }
    solve();

    return 0;
}
int solve(){
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=data[i][1];j++)
            sum+=dfs(1,j,data[i][0]);
        cout<<cnt<<endl;
        cnt=0;
    } 
    return 1;
}

//会不会有算多了的情况?
int dfs(int start,int pos,int left){
    if((left==0)&&(pos==0)){

        //test
        //output();
        cnt++;
        return 1;
    }else if(pos==0||left==0){
        return 0;
    }
    else{
        int sum=0;
        for(int i=start;i<=left;i++){

            // test
            //number[3-pos+1]=i;

            sum+=dfs(i,pos-1,left-i);
        }
        return sum;
    }

}

void output(){
    for(int i=1;i<=N;i++){
        cout<<number[i]<<" ";
    }cout<<endl;
}