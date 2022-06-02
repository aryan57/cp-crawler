/**
 *    author:  Aryan Agarwal
 *    created: 22.05.2022 23:18:08 IST
**/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector <set<int>> adj(n);
	int star=-1;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			star=(i-1+n)%n;
			break;
		}
	}
	if(star==-1){
		cout<<"NO\n";
		return;
	}
	for(int i=(star+1)%n;i!=star;i++,i%=n){

		if(s[i]=='1'){
			adj[i].insert(star);
			adj[star].insert(i);
		}
		else{
			int pre = (i-1+n)%n;
			assert(pre!=star);
			adj[pre].erase(star); //disconnect star and previous
			adj[star].erase(pre);

			adj[i].insert(pre); //connect i and previous
			adj[pre].insert(i);

			adj[i].insert(star); //connect i and star
			adj[star].insert(i);
		}
	}
	if(adj[star].size()%2!=s[star]-'0'){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	for(int i=0;i<n;i++){
		for(int to : adj[i]){
			if(to>i){
				cout<<i+1<<" "<<to+1<<"\n";
			}
		}
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