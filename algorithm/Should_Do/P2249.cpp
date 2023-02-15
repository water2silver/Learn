​
#include<bits/stdc++.h>
 
using namespace std;
 
const int maxn = 1000010;
int a[maxn] = {0};
 
//排序函数
bool cmp(int a, int b){
	return a < b;
}
 
//二分查找
int search(int A[], int left , int right, int x){
	int mid;
	while(left < right){
		mid = (left + right) / 2;
		if(A[mid] >= x){
			right = mid;
		}else{
			left = mid + 1;
		}
	}
	return left;
	
}
 
int main(){
	int n, m;
	cin >> n >> m;	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
    //没有注意这道题是否给出的是顺序数列，所以自己排序了一下
	sort(a, a + n, cmp);
	
    //输入所要查找的数字，循环查找输出
	int c;
	for(int i = 0; i < m; i++){
		cin >> c;
		if(a[search(a,0, n -1, c)] == c) cout << search(a,0, n -1, c) + 1 << ' ';
		else cout << -1 << ' ';
	}
	cout << endl;
	return 0; 
}
 
​