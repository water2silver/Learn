#include <iostream>

using namespace std;

#define N 30
#define M (2*N-1)
typedef struct{
    int weight;
	char data;
    int  parent;
    int LChild;
    int RChild;
}HTNode,HuffmanTree[M+1];//HuffmanTree 是一个结构数组类型，0号单元不用
typedef char * HuffmanCode[N+1];

void Select(HuffmanTree ht, int n, int* s1, int* s2)
{   //找到ht中权值最小的两个结点
	int min = 0, tmp;
	for (int i = 1; i <= n; i++) {
		if (ht[i].parent == 0) {
			min = i;
			tmp = ht[i].weight;
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (ht[i].parent == 0 && ht[i].weight < tmp) {
			min = i;
			tmp = ht[i].weight;
		}
	}
	*s1 = min;
	ht[min].parent = -1;
	for (int i = 1; i <= n; i++) {
		if (ht[i].parent == 0) {
			min = i;
			tmp = ht[i].weight;
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (ht[i].parent == 0 && ht[i].weight < tmp) {
			min = i;
			tmp = ht[i].weight;
		}
	}
	*s2 = min;
}
void CrtHuffmanTree(HuffmanTree ht,int w[],int str[],int n){
    int i;
    for(i=1;i<=n;i++) {
        ht[i]={w[i],str[i],0,0,0};
    }
    int m=2*n-1;
    for(i=n+1;i<=m;i++) ht[i]={0,0,0,0,0};
    for(i=n+1;i<=m;i++){
        int s1,s2;
        //select(ht,i-1;&s1,&s2);
        ht[i].weight=ht[s1].weight+ht[s2].weight;
        ht[s1].parent=i;ht[s2].parent=i;
        ht[i].LChild=s1;ht[i].RChild=s2;
    }
}
void CrtHuffmanCode(HuffmanCode ht,HuffmanCode hc,int n){

	
}



int main(){
	int n; //n个权值
	cin>>n;
	char *str;
	//有点类似于动态数组的想法
	str = (char*)malloc(sizeof(char) * (n+1));
	for (int i = 1; i <= n; i++) {
		getchar();
		scanf("%c", &str[i]);
	}
	int *w;
	w = (int*)malloc(sizeof(int) * (n+1));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	HuffmanTree ht;
	InitHuffman(ht, w, str, n);
	HuffmanCode hc;
	CrtHuffmanCode(ht, hc, n);
	char target[200], code[200];
	scanf("%s", target);
	GetCode(ht, hc, target, code, n);
	PrintCode(code);
	char recode[200];
    GetReCode(ht, hc, code, recode, n);
    PrintReCode(recode);


    return 0;
}