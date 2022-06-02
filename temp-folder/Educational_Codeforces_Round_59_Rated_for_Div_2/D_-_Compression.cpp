/**
 *    author:  Aryan Agarwal
 *    created: 20.05.2022 22:07:21 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}

void solve()
{
	int n;
	cin>>n;
	vector <string> v(n);
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		v[i]="";
		for(char x : s){
			int num = stoi(""s+x,nullptr,16);
			v[i]+=bitset<4>(num).to_string();
		}
	}

	int g=0;

	for(int i=0;i<n;i++){
		int cnt=1;
		for(int j=1;j<n;j++){
			if(v[i][j]!=v[i][j-1]){
				g=gcd(g,cnt);
				cnt=0;
			}
			cnt++;
		}
		g=gcd(g,cnt);
	}
	for(int j=0;j<n;j++){
		int cnt=1;
		for(int i=1;i<n;i++){
			if(v[i][j]!=v[i-1][j]){
				g=gcd(g,cnt);
				cnt=0;
			}
			cnt++;
		}
		g=gcd(g,cnt);
	}
	cout<<g;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}