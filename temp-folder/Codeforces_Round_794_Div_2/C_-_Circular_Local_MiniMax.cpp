/**
 *    author:  Aryan Agarwal
 *    created: 25.05.2022 23:22:54 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	deque <int> v(n);
	for(int &x : v)cin>>x;
	if(n%2){
		cout<<"NO\n";
		return;
	}
	deque <int> ans(n);
	sort(v.begin(),v.end());
	int ind=0;
	for(int i=0;i<n;i+=2){
		ans[i]=v[ind++];
	}
	for(int i=1;i<n;i+=2){
		ans[i]=v[ind++];
	}

	for(int i=0;i<n;i++){
		int prev = (i-1+n)%n;
		int next = (i+1)%n;

		if(ans[i]>ans[prev] && ans[i]>ans[next])continue;
		if(ans[i]<ans[prev] && ans[i]<ans[next])continue;
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	for(int x : ans)cout<<x<<" ";
	cout<<"\n";
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