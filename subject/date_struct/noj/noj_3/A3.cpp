#include <bits/stdc++.h>
using namespace std;
/*矩阵转置
采用三元数组存储矩阵并且转置
核心：知道转置之后这个东西要放到哪里，记录每一列中非零元素的数目
记录原矩阵之中该列之前的所有元素数目，在新矩阵中对应的位置插入并++我们所记录的数目
记得删除检查代码 
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
typedef TSMatrix *PTSMatrix;

void transform(TSMatrix m,PTSMatrix final);
void Prin(PTSMatrix m);

int main(){
    TSMatrix m1,final;

    int n,m;
    cin>>m>>n;
    m1.mu=m;m1.nu=n;
    final.mu=m;final.nu=n;
    int a,b,c,i=0,j;
    while(1){
        cin>>a>>b>>c;
        if(a==0&&b==0&&c==0){
            break;
        }else{
            m1.data[i].i=a;
            m1.data[i].j=b;
            m1.data[i].elem=c;
            i++;
            m1.length++;
        }
    }
    transform(m1,&final);
    Prin(&final);

    return 0;
}
void transform(TSMatrix m,PTSMatrix final){
    final->length=m.length;
    int i=0;int cent[500]={0};
    int h=0;
    for(i=0;i<=m.length-1;i++){
        cent[m.data[i].j+1]++;//
    }
    
    for(i=1;i<=m.nu-1;i++){//0--列数-1
        cent[i]+=cent[i-1];//cent[i]存储的是i列之前一共有多少元素
    }
    for(i=0;i<=m.length-1;i++){
        swap(m.data[i].i,m.data[i].j);
        final->data[cent[m.data[i].i]]=m.data[i];
        cent[m.data[i].i]++;
    }
}
void Prin(PTSMatrix m){
    //cout<<"?"<<endl;
    int i=0;
    for(i=0;i<=m->length-1;i++){
        cout<<m->data[i].i<<" "<<m->data[i].j<<" "<<m->data[i].elem<<endl;
    }
}/*
4 4
1 1 1
2 1 2
3 2 3
*/
/*
6 7
0 3 22
0 6 15
1 1  11
1 5 17
2 3 -6
3 5 39
4 0 91
5 2 28
0 0 0



*/