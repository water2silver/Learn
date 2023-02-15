#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
/*
奶酪？
*/
using namespace std;

int T;
int n,h,r;
class Point{
    public:
        int x;
        int y;
        int z;
};
//vector<Point> data;
Point data[1010];

bool compare(Point a,Point b);
double dist(long long a,long long b,long long c);
int cross(int a,int b);
int dfs(int a,bool m[][1010],bool *f);


int main(){
    cin>>T;

    for(int t=1;t<=T;t++){

        int final=0;
        cin>>n>>h>>r;
        for(int i=1;i<=n;i++){
            cin>>data[i].x>>data[i].y>>data[i].z;
        }
        //排序
        sort(data+1,data+n+1,compare);
        //判断点与点之间的可达性
        bool Map[1010][1010]={0};
        //判断是否被访问过
        bool flag[1010]={0};
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(cross(i,j)){
                    Map[i][j]=1;
                    Map[j][i]=1;
                }
            }
        }
        


        //开始操作
        for(int i=1;i<=n;i++){
            //这个点可以作为入口
            if(data[i].y<=r){
                if(flag[i]==0){
                    flag[i]=1;
                    final|=dfs(i,Map,flag);
                }else{

                }

                
            }
            if(final==1){
                break;
            }
        }
        if(final==1){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }


    }    


    return 0;
}

int dfs(int a,bool m[][1010],bool *f){
    int res=0;
    if(data[a].z+r>=h){
        res=1;
    }else{
        for(int i=1;i<=n;i++){
            //那个点可达，未被访问过
            if(m[a][i]&&f[i]){
                res|=dfs(i,m,f);
                if(res==1){
                    break;
                }
            }
        }
    }
    return res;
}
int cross(int a,int b){
    if(dist(data[a].x-data[b].x,data[a].y-data[b].y,data[a].z-data[b].z)<=r){
        return 1;
    }else{
        return 0;
    }
}
double dist(long long a,long long b,long long c){
    return sqrt(a*a+b*b+c*c);
}



bool compare(Point a,Point b){
    return a.z<b.z;
}
