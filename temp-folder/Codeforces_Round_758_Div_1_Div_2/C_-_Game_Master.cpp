/**
 *    author:  Aryan Agarwal
 *    created: 19.05.2022 11:18:18 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	using pii = pair<int,int>;
	vector<pii> b(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i].first;
		b[i].second=i;
	}
	sort(b.begin(),b.end());
	string ans(n,'0');
	vector<int> mx(n),mn(n);
	mx[0]=a[b[0].second];
	for(int i=1;i<n;i++){
		mx[i]=max(mx[i-1],a[b[i].second]);
	}
	mn[n-1]=a[b[n-1].second];
	for(int i=n-2;i>=0;i--){
		mn[i]=min(mn[i+1],a[b[i].second]);
	}
	
	ans[b[n-1].second]='1';

	for(int i=n-2;i>=0;i--){

		int l=i;
		int r=n-1;
		int last=i;

		while(l<=r){
			int m=(l+r)/2;
			if(mx[i]<mn[m]){
				r=m-1;
			}else{
				last=m;
				l=m+1;
			}
		}
		if(ans[b[last].second]=='1')
			ans[b[i].second]='1';
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