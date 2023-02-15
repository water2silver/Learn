#include <iostream>
#include <string>
#include <math.h>
/*
在我的拙劣想法下，这个题目过了两个点
现在过了四个，死在高精度上了
*/
using namespace std;

string str;
long long res=1;
int x[20],y[20];
int map[20][20];
int str_num[10];
int cent[10];

void connect(int origin,int start);
void dfs();
void count();
long long solve();
void output_map();

int main(){
    int k;
    cin>>str;
    cin>>k;
    //构造图
    for(int i=1;i<=k;i++){
        cin>>x[i]>>y[i];
        map[x[i]][y[i]]=1;
    }
    for(int i=0;i<=9;i++){
        map[i][i]=1;
    }
    //可能得先执行个七八遍才行
    int tt=15;
    while(tt--){
        dfs();
        if(tt==0) break;
    }
    //test
    //output_map();


    count();
    res=solve();

    cout<<res<<endl;
    return 0;
}
void output_map(){
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            cout<<map[i][j]<<" ";
        }cout<<endl;
    }

}

long long solve(){
    long long s=1;
    for(int i=0;i<=str.length()-1;i++){
        //test

        //cout<<cent[str[i]-'0']<<" ";
        s*=cent[str[i]-'0'];
    }
    return s;
}

void dfs(){
    //
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(map[i][j]==1){
                //这里是我做法的精华
                int temp[12]={0};
                int cnt=0;
                
                //
                connect(i,j);

            }
        }
    }
}

void connect(int origin,int start){
    for(int j=0;j<=9;j++){
        if(map[start][j]==1){
            map[origin][j]=1;
        }
    }

}

void count(){

    for(int i=0;i<=str.length()-1;i++){
        str_num[str[i]-'0']++;
    }

    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(map[i][j]==1){
                cent[i]++;
            }
        }
    }
}

/*
12345 3
1 3
3 4
4 2

123456 6
1 3
3 5
5 6
6 1
2 4
4 6

*/