/**
 *    author:  Aryan Agarwal
 *    created: 31.05.2022 20:43:16 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;

	int ans=0;
	int cnt=count(s.begin(),s.end(),'1');
	for(int i=1;i<n;i++){
		ans+=((s[i-1]-'0')*10 + s[i]-'0');
	}

	if(k==0 || cnt==0){
		cout<<ans;
		cout<<"\n";
		return;
	}

	if(cnt==1){
		int ind = find(s.begin(),s.end(),'1')-s.begin();
		if(k>=n-1-ind)ans=min(ans,1ll);
		if(k>=ind)ans=min(ans,10ll);
		cout<<ans<<"\n";
		return;
	}

	int first = find(s.begin(),s.end(),'1')-s.begin();
	int last=-1;
	for(int j=n-1;j>first;j--){
		if(s[j]=='1'){
			last=j;
			break;
		}
	}
	assert(last!=-1);
	if(first+n-1-last<=k)ans=min(ans,11*cnt-11);
	if(first<=k)ans=min(ans,11*cnt-1);
	if(n-1-last<=k)ans=min(ans,11*cnt-10);
	cout<<ans;
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