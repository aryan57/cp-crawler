/**
 *    author:  Aryan Agarwal
 *    created: 22.05.2022 20:08:14 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int l=n/2;
	int r=n/2;
	if(n%2==0)l--;
	int cnt=0;
	int mid=l;

	while (l>=0 && r<n)
	{
		if(s[l]==s[mid]){
			cnt+=2;
			l--;
			r++;
		}else{
			break;
		}
	}
	if(n%2)cnt--;
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