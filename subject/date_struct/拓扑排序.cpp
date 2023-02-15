#include <iostream>
#include <queue>
using namespace std;
/*
˼�� ����·��Ψһ��

*/
int n;
int g[101][101];
int s[101];//����
int ind[101];
queue <int> q;

void init();
void input();
void toposort();

int main(){
    input();
    init();
    toposort();
    return 0;
}/*4
0 1 1 0
0 0 0 1
0 0 0 1
0 0 0 0

*//*
12
0 1 1 1 0 0 0 0 0 0 0 1
0 0 1 0 0 0 0 0 0 0 0 0
0 0 0 0 1 0 1 1 0 0 0 0
0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0 0

0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 1 1 1
0 0 0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0



*/

void toposort(){
    int u;int i;
    while(!q.empty()){
        //1.�Ӷ�����ȡ��һ�����Ϊ0�Ľ��u
        u=q.front();q.pop();
        //2.������ u
        cout<<u+1<<" ";
        //3.ɾ������u�����ıߣ�һ�����������Ϊ0�ĵ㣬������У�
        for(i=0;i<=n-1;i++){
            if(g[u][i]==1){
                ind[i]--;
                if(ind[i]==0){
                    q.push(i);
                }
            }
        }
        //4.ɾ��u---��ʦɾ������һ��
        s[u]=0;

    }

}
void input(){
    cin>>n;
    int i,j;
    for(i=0;i<=n-1;i++){
        for(j=0;j<=n-1;j++){
            cin>>g[i][j];
            if(g[i][j]==1) ind[j]++;//j���������
        }
    }
}

void init(){
    //1.�ҵ��������Ϊ0�Ľ�� �����������
    int i;
    //2.�ҳ��������Ϊ0�ĵ�
    for(i=0;i<n;i++){
        if(ind[i]==0){
            q.push(i);
        }
    }
}