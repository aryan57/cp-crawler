/**
 *    author:  Aryan Agarwal
 *    created: 31.05.2022 20:05:29 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	int o=0,e=0;
	int nn=n;
	while (nn--)
	{
		int x;
		cin>>x;
		if(x&1){
			o++;
		}else e++;
	}
	cout<<min(n-o,n-e)<<"\n";
	
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