/**
 *    author:  Aryan Agarwal
 *    created: 31.05.2022 21:09:46 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector <int> ngt(vector <int> &v){
	int n=v.size();
	stack<int> s;
	vector <int> res(n,n);
	for(int i=0;i<n;i++){
		while (!s.empty() && v[s.top()]<v[i]){
			res[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	return res;
}

bool f(vector <int> &v){
	int n=v.size();
	vector <int> pre(n);
	pre[0]=v[0];
	for(int i=1;i<n;i++)pre[i]=pre[i-1]+v[i];

	vector <int> ngt_v = ngt(v);
	vector <int> ngt_pre = ngt(pre);

	for(int i=0;i<n;i++)
		if(ngt_pre[i]<ngt_v[i])return false;
	return true;
}

void solve()
{
	int n;
	cin>>n;
	vector <int> v(n);
	for(int &x : v)cin>>x;

	bool ok1 = f(v);
	reverse(v.begin(),v.end());
	bool ok2 = f(v);

	cout << ((ok1&ok2) ? "YES\n" : "NO\n");
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}