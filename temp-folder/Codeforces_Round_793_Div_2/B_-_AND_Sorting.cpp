/**
 *    author:  Aryan Agarwal
 *    created: 22.05.2022 20:14:13 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	int ands = ((1ll<<32)-1);
	for(int i=0;i<n;i++){
		int p;
		cin>>p;
		if(p!=i)ands&=p;
	}
	cout<<ands;
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