/**
 *    author:  Aryan Agarwal
 *    created: 19.05.2022 14:07:57 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int fun(int a,int b){
	assert(a<=b);
	
	if(a==b)return 0;

	const int mx=20;

	int pos=-1;
	for(int bit=mx-1;bit>=0;bit--){
		if(((b>>bit)&1)==0 && ((a>>bit)&1)==1){
			pos=bit;
			break;
		}
	}

	if(pos==-1)return 1;
	
	int pos2=-1;
	for(int j=pos+1;j<mx;j++){
		if(((b>>j)&1)==1 && ((a>>j)&1)==0){
			pos2=j;
			break;
		}
	}
	assert(pos2!=-1);

	int t=(1ll<<mx)-1;
	t<<=pos2;
	int na = (a&t) + (1ll<<pos2);

	assert(na<=b);
	assert(na>a);

	int ans = (na!=b?na-a+1:na-a);

	t=(1ll<<mx)-1;
	t<<=pos;
	int nb = (b&t) + (1ll<<pos);

	assert(nb>b);

	return min(ans,nb-b+fun(a,nb));
}

void solve()
{
	int a,b;
	cin>>a>>b;
	cout<<fun(a,b)<<"\n";
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