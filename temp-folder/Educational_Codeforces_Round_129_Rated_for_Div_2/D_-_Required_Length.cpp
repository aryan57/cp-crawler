/**
 *    author:  Aryan Agarwal
 *    created: 24.05.2022 23:48:35 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,x;
	cin>>n>>x;
	queue<int> q;
	map<int,int> dis;
	q.push(x);
	dis[x]=0;
	while (!q.empty())
	{
		int num = q.front();
		q.pop();
		string s = to_string(num);
		if(s.size()==n){
			cout<<dis[num];
			return;
		}
		for(int d : s){
			if(d<='1')continue;
			int k = num*(d-'0');
			if(dis.count(k)==0){
				dis[k]=dis[num]+1;
				q.push(k);
			}
		}
	}
	cout<<"-1\n";
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