/**
 *    author:  Aryan Agarwal
 *    created: 25.05.2022 23:08:50 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	deque <int> v(n);
	int sum=0;
	for(int &x : v){
		cin>>x;
		sum+=x;
	}

	for(int i=0;i<n;i++){
		if(sum==n*v[i]){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
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