/**
 *    author:  Aryan Agarwal
 *    created: 19.05.2022 20:45:14 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;
	vector <int> v(n);
	int s=-(k*(k-1))/2;
	for(int i=0;i<n;i++){
		cin>>v[i];
		s+=v[i];
		v[i]=n-(i+1)-v[i];
	}

	sort(v.begin(),v.end());
	for(int i=0;i<k;i++){
		s+=v[i];
	}
	cout<<s;
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