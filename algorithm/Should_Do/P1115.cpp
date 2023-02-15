#include<iostream>
#include<algorithm>
using namespace std;
long long arr[200001];//数组开大点 
long long ans[200001];
int main(){
	int n;
	long long sum;
	cin >> n;
	cin>>arr[0];
	sum = arr[0];
	ans[0] = arr[0];
	for(int i = 1; i < n; i++){
		cin >> arr[i];
		ans[i] = max(ans[i-1] + arr[i], arr[i]);
		sum = max(ans[i],sum);
	}
	cout << sum;
	return 0;
} 
