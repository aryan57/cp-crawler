/**
 *    author:  Aryan Agarwal
 *    created: 19.05.2022 20:15:11 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int a,b,c;
	cin>>a>>b>>c;

	int x=a+b+c;
	int y=b+c;
	int z=c;

	assert(x%y==a);
	assert(y%z==b);
	assert(z%x==c);

	cout<<x<<" "<<y<<" "<<z<<"\n";
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