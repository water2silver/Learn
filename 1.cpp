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
	double number1[3], number2[3], number3[3];
	printf("请输入电阻臂：");
	for(R int i = 0; i < 3; ++ i){
		cin >> number1[i];
	}
	printf("\n请输入变化量：");
	for(R int i = 0; i < 3; ++ i){
		cin >> number2[i];
	}
	printf("\n请输入偏转格数：");
	for(R int i = 0; i < 3; ++ i){
		cin >> number3[i];
	}
	double answer = 0;
	for(R int i = 0; i < 3; ++ i){
		answer += number3[i] / number2[i] * number1[i];
	}
	answer /= 3;
	printf("直流电桥灵敏度：%.2lf", answer);
	system("pause");
	return 0;
}
