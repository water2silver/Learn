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
	printf("���������ۣ�");
    cin >> number1[0];
	for(R int i = 1; i < 6; ++ i){
		number1[i]=number1[0];
	}
	printf("\n������仯����");
	for(R int i = 0; i < 6; ++ i){
		cin >> number2[i];
	}
	printf("\n������ƫת������");
	for(R int i = 0; i < 6; ++ i){
		cin >> number3[i];
	}
	double answer = 0;
	printf("ֱ�����������ȣ�");
	for(R int i = 0; i < 6; ++ i){
		answer = number3[i] / number2[i] * number1[i];
		printf("%.2lf ", answer);
	}	
	system("pause");
	return 0;
}
