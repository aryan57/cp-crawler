/**
 *    author:  Aryan Agarwal
 *    created: 22.05.2022 23:45:44 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	map<int,int> f;
	while (n--){
		int x;
		cin>>x;
		f[x]++;
	}
	int two=0,one=0;
	for(auto p : f){
		if(p.second>=2)two++;
		else one++;
	}
	cout<<two+(one+1)/2;
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