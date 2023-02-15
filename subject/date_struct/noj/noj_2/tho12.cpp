#include <bits/stdc++.h>
using namespace std;
/*普通稀疏矩阵的读入与相加
//没考虑矩阵的顺序问题，数据很水

*/



#define MaxSize 200

typedef int ElemType;
typedef struct Tri_ple
{
	int  i, j;		/* 行号和列号 */
	ElemType  elem;	/* 元素值 */
}Triple,*PTriple;

typedef struct
{
	Triple	data[MaxSize];
	int	mu, nu, tu;	/* 行数、列数和非零元个数*/
    int length=0;
}TSMatrix;



int main(){
    int t1,t2,i,j;int m,n,v;
    int flag=0;
    cin>>t1>>t2;
    TSMatrix m1,m2;
    for(i=1;i<=t1;i++){
        cin>>m>>n>>v;
        m1.data[i].i=m;
        m1.data[i].j=n;
        m1.data[i].elem=v;
        m1.length++;
    }
    for(i=1;i<=t2;i++){
        cin>>m>>n>>v;
        m2.data[i].i=m;
        m2.data[i].j=n;
        m2.data[i].elem=v;
        m2.length++;
    }
    for(i=1;i<=t2;i++){
        flag=0;
        for(j=1;j<=t1;j++){
            if(m2.data[i].i==m1.data[j].i&&m2.data[i].j==m1.data[j].j){
                m1.data[j].elem+=m2.data[i].elem;
                flag=1;
                break;
            }
        }
        if(flag==0){
            m1.data[++m1.length]=m2.data[i];
        }
    }

    for(i=1;i<=m1.length;i++){
        if(m1.data[i].elem!=0){
            cout<<m1.data[i].i<<" "<<m1.data[i].j<<" "<<m1.data[i].elem<<endl;
        }
    }
    return 0;
}
/*
2 2
2 3 2
3 1 4
2 3 2 
2 2 4
*/