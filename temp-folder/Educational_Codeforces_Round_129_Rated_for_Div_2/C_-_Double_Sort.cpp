/**
 *    author:  Aryan Agarwal
 *    created: 23.05.2022 20:16:59 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<pair<pair <int,int> ,int> > v(n);
	vector <int> a(n),b(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
		v[i]={{a[i],b[i]},i};
	}

	sort(v.begin(),v.end());
	for(int i=1;i<n;i++){
		if(v[i].first.second<v[i-1].first.second){
			cout<<"-1\n";
			return;
		}
	}

	vector<pair<int,int> > ans;

	for(int i=0;i<n-1;i++){
		if(v[i].second==i)continue;
		int j = v[i].second;
		ans.push_back({j,i});
		for(int k=i+1;k<n;k++){
			if(v[k].second==i){
				v[k].second=j;
				break;
			}
		}
	}
	cout<<ans.size();
	cout<<"\n";
	for(auto p : ans)cout<<p.first+1<<" "<<p.second+1<<"\n";
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