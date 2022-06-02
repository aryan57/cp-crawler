/**
 *    author:  Aryan Agarwal
 *    created: 19.05.2022 20:24:14 IST
**/
#include <bits/stdc++.h>
using namespace std;

// #define int long long

void solve()
{
	int n,m;
	cin>>n>>m;
	pair <int,int> p={-1,-1};
	vector <bool> tocheck(n);

	vector< vector<int> > g(n,vector <int> (m));
	vector <int> v2(m);

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>g[i][j];
		}
	}


	for(int i=0;i<n;i++){
		
		for(int j=0;j<m;j++){
			v2[j]=g[i][j];
		}
		
		sort(v2.begin(),v2.end());

		pair <int,int> z={-1,-1};
		int cnt=0;
		for(int j=0;j<m;j++){
			if(g[i][j]!=v2[j]){
				cnt++;
				if(cnt>2){
					cout<<"-1\n";
					return;
				}
				if(cnt==1)z.first=j;
				else z.second=j;
			}
		}
		if(z.first==-1){
			tocheck[i]=true;
			continue;
		}
		if(p.first==-1){
			p=z;
		}else if(p!=z){
			cout<<"-1\n";
			return;
		}
	}

	if(p.first==-1)cout<<"1 1\n";
	else{
		
		for(int i=0;i<n;i++){
			if(!tocheck[i])continue;
			if(g[i][p.first]!=g[i][p.second]){
				cout<<"-1\n";
				return;
			}
		}

		cout<<p.first+1<<" "<<p.second+1<<"\n";
	}
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