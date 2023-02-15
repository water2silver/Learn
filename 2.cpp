#include<map>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<iomanip>
#include<cstring>
#include<iterator>
#include<iostream>
#include<algorithm>
#define R register
#define LL long long
#define pi 3.141
#define INF 1400000000
using namespace std;

int main(){
	double number1[6], number2[6], number3[6];
	printf("请输入电阻臂：");
    cin >> number1[0];
	for(R int i = 1; i < 6; ++ i){
		number1[i]=number1[0];
	}
	printf("\n请输入变化量：");
	for(R int i = 0; i < 6; ++ i){
		cin >> number2[i];
	}
	printf("\n请输入偏转格数：");
	for(R int i = 0; i < 6; ++ i){
		cin >> number3[i];
	}
	double answer = 0;
	printf("直流电桥灵敏度：");
	for(R int i = 0; i < 6; ++ i){
		answer = number3[i] / number2[i] * number1[i];
		printf("%.2lf ", answer);
	}	
	system("pause");
	return 0;
}
