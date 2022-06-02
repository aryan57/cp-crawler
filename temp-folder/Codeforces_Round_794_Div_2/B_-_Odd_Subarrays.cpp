/**
 *    author:  Aryan Agarwal
 *    created: 25.05.2022 23:12:45 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	deque <int> v(n);
	for(int &x :v)cin>>x;
	int cnt=0;
	for(int i=1;i<n;i++){
		if(v[i]<v[i-1]){
			cnt++;
			i++;
		}
	}
	cout<<cnt;
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