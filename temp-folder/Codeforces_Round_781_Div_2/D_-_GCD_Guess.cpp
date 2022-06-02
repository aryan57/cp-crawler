/**
 *    author:  Aryan Agarwal
 *    created: 17.05.2022 12:31:56 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{	
	int pw=1;
	int a=1;
	int x=0;
	for(int bit=0;bit<=29;bit++,pw*=2){
		int b=a+2*pw;
		cout<<"? "<<a<<" "<<b<<endl;
		fflush(stdout);
		int g;
		cin>>g;
		if(g==2*pw){
			x+=pw;
		}else if(g==pw){
			a+=pw;
		}else{
			assert(false);
		}
	}
	cout<<"! "<<x<<endl;
	fflush(stdout);
}

signed main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}