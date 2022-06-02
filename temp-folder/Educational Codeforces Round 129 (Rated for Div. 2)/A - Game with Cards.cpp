/**
 *    author:  Aryan Agarwal
 *    created: 23.05.2022 20:08:25 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> a(n);
	for(int &x : a)cin>>x;
	int m;
	cin>>m;
	vector <int> b(m);
	for(int &x : b)cin>>x;

	cout<<((*max_element(a.begin(),a.end()) >= *max_element(b.begin(),b.end()))?"Alice\n":"Bob\n");
	cout<<((*max_element(b.begin(),b.end()) >= *max_element(a.begin(),a.end()))?"Bob\n":"Alice\n");
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