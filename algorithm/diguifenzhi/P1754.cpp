#include <iostream>
/*
这个暴力的做法干了60分 哈哈哈哈
思路：之前有个列举组合数的程序,调用过来，data中的n个数即为2n中抽取的，把
zzh数组中，对应的data[i]位置赋值为1，即可，模拟，统计zzh中1与0排列寻找答案
*/
using namespace std;
int data[25];
int zzh[50];
int n;int m;
int res;
void   solve();
void check_data(int u);
int check_AB(int m);

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        data[i]=i;
    }
    m=2*n;
    solve();
    cout<<res<<endl;
    return 0;
}

void   solve(){
    int temp=n;
    long long sum=1;
    for(int i=0;i<=n-1;i++){
        sum=sum*(m-i)/(i+1);
    }

    for(;;){
        int flag=0;
        for(int j=1;j<=2*n;j++){
            zzh[j]=0;
        }

        for(int j=1;j<=n;j++){
            zzh[data[j]]=1;
        }
        int uu=0;
        for(int j=1;j<=2*n;j++){
            uu+=check_AB(zzh[j]);
            if(uu<0){
                flag=1;
                break;
            }
        }

        if(flag==0){
            //
            // for(int j=1;j<=n;j++){
            //     cout<<data[j]%2<<" ";
            // }cout<<endl;
            res++;
        }
        data[temp]++;
        check_data(temp);
        sum--;
        if(sum==0){
            break;
        }
    }
}

int check_AB(int m){
    if(m%2==1){
        return 1;
    }else{
        return -1;
    }
}

void check_data(int u){
    //
    if(data[u]<=m-n+u){
        return ;
    }else {
        data[u-1]++;
        check_data(u-1);
        data[u]=data[u-1]+1;
    }
}