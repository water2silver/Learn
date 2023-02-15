#include<bits/stdc++.h>
using namespace std;
int n,k,m;vector<int>a;set<int>s;
set<int>::iterator it;//迭代器 
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		s.insert(m);//一步到位 
	}
	for(it=s.begin();it!=s.end();it++) a.push_back(*it);//将set存入vector 
	if(a.size()<k) cout<<"NO RESULT";//判是否输NO 
	else cout<<a[k-1];//vector起始下标为0 
	return 0;
}
