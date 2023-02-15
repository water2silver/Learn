#include <iostream>
#include<stdio.h>

/*
为什么会RE呢？
*/
using namespace std;
int n; 
int cent;
int data[100000010];
int res[100010];
int read();

int main(){
    cin>>n>>cent;
    int temp;
    for(int i=1;i<=n;i++){
        temp=read();
        if(data[temp]==0)
            data[temp]=i;
    }

    for(int i=1;i<=cent;i++){
        temp=read();
        if(data[temp]!=0){
            res[i]=data[temp];
        }else{
            res[i]=-1;
        }
    }

    for(int i=1;i<=cent;i++){
        printf("%d ",res[i]);
    }
    return 0;
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