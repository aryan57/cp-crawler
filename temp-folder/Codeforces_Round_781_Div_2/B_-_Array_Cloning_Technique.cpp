/**
 *    author:  Aryan Agarwal
 *    created: 17.05.2022 11:25:17 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	const int inf = 2e18;
	int ans=inf;

	map<int,int> cnt;
	vector<int> v(n);
	for(int &x : v){
		cin>>x;
		cnt[x]++;
	}

	for(int x : v){
		int k = cnt[x];
		int op=0;
		while(k<n){
			int ava = k;
			op++;
			int req=n-k;
			op+=min(ava,req);
			k+=min(ava,req);
		}
		ans=min(ans,op);
	}
	cout<<ans<<"\n";
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