#include<iostream>
using namespace std;
void kp(int a[],int l,int r){
    int i = l, j = r,flag = a[(l + r) / 2],tmp;
    do{
        while (a[i] < flag)i++;
        while (a[j] > flag)j--;
        if(i<=j){
        	tmp = a[i]; a[i] = a[j]; a[j] = tmp;
            i++;j--;
		}
    }while (i <= j);
    if(l < j)kp(a, l, j);
    if(i < r)kp(a, i, r);
    return;
}
int main(){
    int n;
    int N[100010];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>N[i];
    }
    kp(N,1,n);
    for(int i=1;i<=n;i++){
        if(i!=1){
            cout<<" ";
        }
        cout<<N[i];

    }
    cout<<endl;
    return 0;
}

