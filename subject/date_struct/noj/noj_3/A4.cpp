#include <bits/stdc++.h>
using namespace std;
/*
矩阵加法，三元组实现
算法：分别遍历两个三元组，根据他们的坐标判断他们的位置是否复合要求


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

void Init(PTSMatrix m1,PTSMatrix m2);
void Prin(PTSMatrix m);
void add_two(PTSMatrix m1,PTSMatrix m2,PTSMatrix final);

int main(){
    PTSMatrix m1,m2;
    m1=(PTSMatrix)malloc(sizeof(TSMatrix));
    m2=(PTSMatrix)malloc(sizeof(TSMatrix));
    PTSMatrix final=(PTSMatrix)malloc(sizeof(TSMatrix));
    Init(m1,m2);
    add_two(m1,m2,final);
    
    Prin(final);


    return 0;
}
void Init(PTSMatrix m1,PTSMatrix m2){//完成稀疏矩阵的初始化
//没写好啊，这俩指针要被赋值地址才有意义
    int m,n;int t1,t2;
    cin>>m>>n>>t1>>t2;
    //
    m1->mu=m;m1->nu=n;
    m2->mu=m;m2->nu=n;
    int i=0;int a,b,c;

    for(i=0;i<=t1-1;i++){
        cin>>a>>b>>c;
        m1->data[i].i=a;
        m1->data[i].j=b;
        m1->data[i].elem=c;
    }
    m1->length=t1;
    for(i=0;i<=t2-1;i++){
        cin>>a>>b>>c;
        m2->data[i].i=a;
        m2->data[i].j=b;
        m2->data[i].elem=c;
    }
    m2->length=t2;
}
void Prin(PTSMatrix m){
    //cout<<"?"<<endl;
    int i=0;
    for(i=0;i<=m->length-1;i++){
        cout<<m->data[i].i<<" "<<m->data[i].j<<" "<<m->data[i].elem<<endl;

    }
}
void add_two(PTSMatrix m1,PTSMatrix m2,PTSMatrix final){
    int i=0;int j=0;int h=0;
    for(i=0,j=0;;){//不管条件，先进入循环

        if(m1->data[i].i==m2->data[j].i&&m1->data[i].j==m2->data[j].j){
            int temp=m1->data[i].elem+m2->data[j].elem;
            if(temp!=0){
                final->data[h]=m1->data[i];
                final->data[h].elem=temp;
                h++;
            }
            i++;j++;//如果i,j达到边界了如何？

        }else{
            if(m1->data[i].i<m2->data[j].i){//m1比m2的i小
                final->data[h]=m1->data[i];
                h++;
                i++;
            }else if(m1->data[i].i>m2->data[j].i){
                final->data[h]=m2->data[j];
                h++;
                j++;
            }else if(m1->data[i].i==m2->data[j].i){
                if(m1->data[i].j<m2->data[j].j){
                    final->data[h]=m1->data[i];
                    h++;
                    i++;
                }else{
                    final->data[h]=m2->data[j];
                    h++;
                    j++;
                }
            }
        }
        if(i==m1->length||j==m2->length){//如果i,j一方遍历结束，只需要把剩下的都放到final里面即可
            break;
        }        
    }
    //等待他们自动执行即可
    for(;i<=m1->length-1;i++){
        final->data[h++]=m1->data[i];
    }
    for(;j<=m2->length-1;j++){
        final->data[h++]=m2->data[j];
    }
    final->length=h;
}




/*
样例：
3 4 3 2
1 1 1
1 3 1
2 2 2
1 2 1
2 2 3
*/