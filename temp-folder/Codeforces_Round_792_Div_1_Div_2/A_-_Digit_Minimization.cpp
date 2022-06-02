/**
 *    author:  Aryan Agarwal
 *    created: 19.05.2022 20:10:34 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	if(n==2){
		cout<<s[1];
		cout<<"\n";
		return;
	}

	cout<<*min_element(s.begin(),s.end());
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