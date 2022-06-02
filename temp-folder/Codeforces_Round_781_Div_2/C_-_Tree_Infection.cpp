/**
 *    author:  Aryan Agarwal
 *    created: 17.05.2022 11:41:31 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<int> p(n);
	vector<int> deg(n,-1);
	deg[0]=0;
	for(int i=1;i<n;i++){
		cin>>p[i];
		p[i]--;
		deg[i]++;
		deg[p[i]]++;
	}
	sort(deg.begin(),deg.end(),greater<>());
	int ans=3*n;
	int l=0;
	int r=ans;
	for(int i=0;i<n;i++){
		if(deg[i]==0){
			deg[i]=1;
			l=i+1;
			break;
		}
	}

	while(l<=r){
		int m=(l+r)/2;
		bool ok = true;
		int sum=0;
		int infect=0;
		for(int i=0;i<n;i++){
			if(deg[i]==0)break;
			infect++;
			int extra = (deg[i]-1)-(m-1-i);
			sum+=max(extra,0ll);
		}
		if(m-infect>=sum){
			ans=m;
			r=m-1;
		}else{
			l=m+1;
		}
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