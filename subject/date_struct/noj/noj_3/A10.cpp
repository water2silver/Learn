#include <iostream>

using namespace std;

typedef struct Ma_p {
    int flag[101] = { 0 };
    int num = 0;
    int arc[101][101];
}Mymap, * PMymap;
typedef struct Pa_th{
    int prevex;
    int length;
}Path;

//图的创建
void create_graph(Mymap& G);
//输出图
void Prin_map(Mymap G);
//计算
void Floyd(Mymap &G,Path p[]);


int main(){
    Mymap G;
    create_graph(G);
    
    Path p[101];
    //Floyd(G,p);
    int n;int a[101],b[101];
    int i;
    
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    Floyd(G,p);
    for(i=1;i<=n;i++){
        cout<<G.arc[a[i]][b[i]]<<endl;
    }

    return 0;
}/*
4
0 2 10 10000
2 0 7 3
10 7 0 6
10000 3 6 0
2 
0 2
3 0


*/

void Floyd(Mymap &G,Path p[]){
    int i=0;int j,k;
    for(i=0;i<=G.num-1;i++){
        for(j=0;j<=G.num-1;j++){
            for(k=0;k<=G.num-1;k++){
                if(G.arc[i][j]>G.arc[i][k]+G.arc[k][j]){
                    G.arc[i][j]=G.arc[i][k]+G.arc[k][j]; 
                }
            }
        }
    }
}


void create_graph(Mymap& G) {
    cin >> G.num;
    int i, j;
    for (i = 0; i <= G.num - 1; i++) {
        for (j = 0; j <= G.num - 1; j++) {
            cin >> G.arc[i][j];
        }
    }
}
void Prin_map(Mymap G) {
    for (int i = 0; i <= G.num - 1; i++) {
        for (int j = 0; j <= G.num - 1; j++) {
            cout << G.arc[i][j] << " ";
        }
        cout << endl;
    }
}