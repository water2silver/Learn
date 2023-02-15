#include <iostream>

using namespace std;
long long v[25][25][25];
int sym[25][25][25];

int dfs(int x,int y,int z);

int main(){
    long long a,b,c;
    while(1){
        cin>>a>>b>>c;
        if(a==b&&b==c&&a==-1){
            break;
        }
        printf("w(%lld, %lld, %lld) = ",a,b,c);
        
        cout<<dfs(a,b,c)<<endl;
    }

    return 0;
}
int dfs(int x,int y,int z){

    if(x<=0||y<=0||z<=0){
        return 1;
    }else if(x>20||y>20||z>20){
        if(sym[20][20][20]==1) return v[20][20][20];
        v[20][20][20]=dfs(20,20,20);
        sym[20][20][20]=1;
        return v[20][20][20];
    }else if(x<y&&y<z){
        if(sym[x][y][z]==1) return v[x][y][z];
        v[x][y][z]=dfs(x,y,z-1)+dfs(x,y-1,z-1)-dfs(x,y-1,z);
        sym[x][y][z]=1;
        return v[x][y][z];
    }else{
        if(sym[x][y][z]==1) return v[x][y][z];
        int a=x;int b=y;int c=z;//()（）
        v[x][y][z]=dfs(a-1,b,c)+dfs(a-1,b-1,c)+dfs(a-1,b,c-1)-dfs(a-1,b-1,c-1);
        //dfs(a-1,b,c)+dfs(a-1,b-1,c)+dfs(a-1,b,c-1)-dfs(a-1,b-1,c-1);
        sym[x][y][z]=1;
        return v[x][y][z];
    }
}