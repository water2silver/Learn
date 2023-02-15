#include <iostream>
#include <iomanip>
/*有点小毛病，过了，第五个测试点是为什么？*/
using namespace std;
int data[25];
int m,n;

void solve();
void check_data(int u);

int main(){    
    cin>>m>>n;
    
    for(int i=1;i<=n;i++){
        data[i]=i;
    }
    if(n==0){
        //如果我把这行注释掉，就能通过所有测试点，不然，会有一个RE？
        return 0;
    }else {
        solve();
    }


    return 0;   
}
void   solve(){
    int temp=n;
    long long sum=1;
    for(int i=0;i<=n-1;i++){
        sum=sum*(m-i)/(i+1);
    }

    for(;;){

        for(int j=1;j<=n;j++){
            cout<<setw(3)<<data[j];
        }
        cout<<endl;
        data[temp]++;
        check_data(temp);
        sum--;
        if(sum==0){
            break;
        }
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