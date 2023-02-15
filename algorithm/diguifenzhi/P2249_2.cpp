#include <iostream>
/*
这二分写的跟屎一样

*/
#include <stdio.h>
using namespace std;

int n,m;
int data[100010];
int res[100010];
int read();
int search(int x,int a,int b);
int binary(int x,int l,int r);
int binary2(int x,int l,int r);
int main(){
    n=read();
    m=read();
    //cout<<n<<" "<<m<<endl;
    for(int i=1;i<=n;i++){
        data[i]=read();
    }
    for(int i=1;i<=m;i++){
        res[i]=read();
    }

    for(int i=1;i<=m;i++){
        res[i]=binary(res[i],1,n);
    }
    for(int i=1;i<=m;i++){
        printf("%d ",res[i]);   
    };

    
    return 0;
}
int search(int x,int a,int b){
    if(a==b){
        if(data[a]!=x){
            return -1;
        }else{
            return a;
        }
    }else{
        if(x==data[(a+b)/2]){
            return (a+b)/2;
        }else if(x<data[(a+b)/2]){
            return search(x,a,(a+b)/2);
        }else{
            return search(x,(a+b)/2,b);
        }
    }
}
//正确答案
int binary(int x,int l,int r){
    while(l<r){
        int mid=(l+r)/2;
        if(x<=data[mid]){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    if(x==data[l]){
        return l;
    }else{
        return -1;
    }
}

//错解
int binary2(int x,int l,int r){
    while(l<r){
        int mid=(l+r)/2;
        if(x>data[mid]){
            l=mid;
        //这个地方不能这样写，因为数组可能会有重复的数字
        }else if(x==data[mid]){
            return mid;
        }
        else{
            r=mid-1;
        }
    }
    if(x==data[l]){
        return l;
    }else{
        return -1;
    }
}


int read(){//快读
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}