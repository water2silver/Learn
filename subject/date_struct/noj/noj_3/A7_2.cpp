#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 30     //叶子结点最大值
#define M 2*N-1  //所有结点最大值

typedef struct
{
	int flag;
	char data;
	int weight;
	int parent, LChild, RChild;
}HTNode, HuffmanTree[M + 1]; //0号单元不用

typedef char* HuffmanCode[N + 1];

void CreateHuffman(HuffmanTree ht, int w[], char str[],int n);
//构建哈夫曼树ht[M+1],w[]存放n个权值
void Select(HuffmanTree ht, int tmp, int* s1, int* s2);
//找到ht中权值最小的两个结点
void CrtHuffmanCode(HuffmanTree ht, HuffmanCode hc, int n);
//构建哈夫曼编码
void GetCode(HuffmanTree ht, HuffmanCode hc, char* target, char* code, int n);
//获得二进制编码
void PrintCode(char* code);
//打印编码
void GetReCode(HuffmanTree ht, HuffmanCode hc, char* code, char *recode, int n);
//二进制码重新编译成报文
void PrintReCode(char* recode);
//打印报文

int main()
{
	int n; //n个权值
	scanf("%d", &n);
	char *str;
	str = (char*)malloc(sizeof(char) * (n+1));
	if (str == NULL) return 0;
	for (int i = 1; i <= n; i++) {
		getchar();
		scanf("%c", &str[i]);
	}
	int *w;
	w = (int*)malloc(sizeof(int) * (n+1));
	if (w == NULL) return 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	HuffmanTree ht;
	//ht 是哈夫曼树， w 是出现频率 str 是具体内容 n 是内容的数目
	CreateHuffman(ht, w,str, n);
	//hc 哈夫曼编码 二维数组
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

void CreateHuffman(HuffmanTree ht, int w[],char str[], int n)
{   
	ht[0].flag = 0;
	for (int i = 1; i <= n; i++) {
		//将前n项初始化
		ht[i].flag = ht[i - 1].flag + 1;
		ht[i].weight = w[i];
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChild = 0;
		ht[i].data = str[i];
	}
	int m = 2 * n - 1;
	for (int i = n + 1; i <= m; i++) {
		//将n+1项到m项初始化
		ht[i].flag = ht[i - 1].flag + 1;
		ht[i].weight = 0;
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChild = 0;
	}
	
	
	//构建哈夫曼树ht[M+1],w[]存放n个权值
	int s1, s2;
	m = 2 * n - 1;
	for (int i = n + 1; i <= m; i++) {
		//开始构造
		Select(ht, i-1, &s1, &s2);
		ht[i].weight = ht[s1].weight + ht[s2].weight;
		if (ht[s1].weight < ht[s2].weight) {
            ht[i].LChild = s1;
            ht[i].RChild = s2;
		}
		else {
            ht[i].LChild = s2;
            ht[i].RChild = s1;
		}
		ht[s1].parent = i;
		ht[s2].parent = i;
	}
}

void Select(HuffmanTree ht, int n, int* s1, int* s2)
{ 
	int min = 0, tmp;int i;
	//先找一个合适的结点存着某一个数字
	for (i = 1; i <= n; i++) {
		if (ht[i].parent == 0) {
			min = i;
			tmp = ht[i].weight;
			break;
		}
	}
	//再要求这个是最小的
	for (; i <= n; i++) {
		if (ht[i].parent == 0 && ht[i].weight < tmp) {
			min = i;
			tmp = ht[i].weight;
		}
	}
	*s1 = min;
	ht[min].parent = -1;
	for (i = 1; i <= n; i++) {
		if (ht[i].parent == 0) {
			min = i;
			tmp = ht[i].weight;
			break;
		}
	}
	for (1; i <= n; i++) {
		if (ht[i].parent == 0 && ht[i].weight < tmp) {
			min = i;
			tmp = ht[i].weight;
		}
	}
	*s2 = min;
}

void CrtHuffmanCode(HuffmanTree ht, HuffmanCode hc, int n)
{   //构建哈夫曼编码
	char* cd;
	cd = (char*)malloc(sizeof(char) * n);//编码长度不超过n
	cd[n - 1] = '\0';
	for (int i = 1; i <= n; i++) {
		int start = n - 1;//记录编码开始位置
		int tmp = i, par = ht[i].parent;
		//根据节点的父亲节点不断回溯5
		//逆着回溯
		while (par) {
			start--;
			if (ht[par].LChild == tmp) {
				cd[start] = '0';
			}
			else {
				cd[start] = '1';
			}
			tmp = par;
			par = ht[par].parent;
		}
		hc[i] = (char*)malloc(sizeof(char) * (n - start));
		if (hc[i] == NULL) return;
		strcpy(hc[i], &cd[start]);
	}
	free(cd);
}

void GetCode(HuffmanTree ht, HuffmanCode hc, char* target, char* code, int n)
{   //获得二进制编码
	int len = strlen(target);
	code[0] = '\0';
	for (int i = 0; i < len; i++) {
		for (int j = 1; j <= n; j++) {
			if (target[i] == ht[j].data) {
				strcat(code, hc[j]);
			}
		}
	}

}

void PrintCode(char* code)
{   //打印编码
	printf("%s\n",code);
}

void GetReCode(HuffmanTree ht, HuffmanCode hc, char* code, char *recode, int n)
{   //二进制码重新编译成报文
	int len_code = strlen(code);
	int i= 0, k = 0;
	while (i < len_code) {
		for (int j = 1; j <= n; j++) {
			if (code[i] == hc[j][0]) {
				int len_hc = strlen(hc[j]);
				if (strncmp(hc[j], &code[i], len_hc) == 0) {
					recode[k] = ht[j].data;
					k++;
					i = i + len_hc;
				}
			}
		}
	}
}

void PrintReCode(char* recode)
{   //打印报文
    printf("%s\n",recode);
}
