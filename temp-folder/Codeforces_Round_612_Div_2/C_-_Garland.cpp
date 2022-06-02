/**
 *    author:  Aryan Agarwal
 *    created: 20.05.2022 21:07:29 IST
**/
#include <bits/stdc++.h>
using namespace std;

const int mxn = 100;
const int inf = 1e9;

void solve()
{
	int n;
	cin>>n;
	int O=(n+1)/2;
	int E=n/2;

	vector <int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
		if(v[i]){
			v[i]&=1;
			if(v[i])O--;
			else E--;
		}else{
			v[i]=-1;
		}
	}

	int dp[mxn][2][mxn][mxn];
	fill_n(&dp[0][0][0][0],mxn*2*mxn*mxn,inf);

	for(int i=0;i<n;i++){
		for(int remE=0;remE<=E;remE++){
			for(int remO=0;remO<=O;remO++){
				
				if(v[i]!=-1){
					if(i)
					dp[i][v[i]][remO][remE]=min({dp[i][v[i]][remO][remE],dp[i-1][v[i]][remO][remE],dp[i-1][v[i]^1][remO][remE]+1});
					else dp[i][v[i]][remO][remE]=0;

				}else{

					if(i==0){
						if(remE+1<=E)
						dp[i][0][remO][remE] = 0;
						if(remO+1<=O)
						dp[i][1][remO][remE] = 0;
						
					}else {
						
						if(remE+1<=E)
						dp[i][0][remO][remE] = min({dp[i][0][remO][remE],dp[i-1][0][remO][remE+1],dp[i-1][1][remO][remE+1]+1});
						if(remO+1<=O)
						dp[i][1][remO][remE] = min({dp[i][1][remO][remE],dp[i-1][0][remO+1][remE]+1,dp[i-1][1][remO+1][remE]});
					}

				}

			}
		}
	}

	cout<<min(dp[n-1][0][0][0],dp[n-1][1][0][0]);
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