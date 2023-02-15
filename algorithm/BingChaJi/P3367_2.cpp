#include <iostream>
/*
并查集
*/
using namespace std;
int n,m;
int data[10010];
int find(int a);

int main(){
    
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        data[i]=i;
    }

    for(int i=1;i<=m;i++){
        int flag,x,y;
        cin>>flag>>x>>y;

        if(flag==1){
            data[find(y)]=find(x);
        }else{
            if(find(x)==find(y)){
                cout<<"Y"<<endl;
            }else{
                cout<<"N"<<endl;
            }
        }
    }


    return 0;
}

//并查集的核心函数?
int find(int a){
    //这是最开始我们规定每一个元素都是一个集合的
    if(data[a]==a) {
        return a;
    }
    data[a]=find(data[a]);
    return data[a];
}