/**
 *    author:  Aryan Agarwal
 *    created: 19.05.2022 21:19:38 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

/*
	It is the data structure for monoids i.e., the algebraic structure that satisfies the following properties :
		associativity: (a?b)?c = a?(b?c) for all a,b,c ? S
		existence of the identity element: a?e = e?a = a for all a ? S

	(1) segtree<S, binary_operation, identity_element> seg(int n)
	(2) segtree<S, binary_operation, identity_element> seg(vector<S> v)
		(1): It creates an array a of length n. All the elements are initialized to identity_element().
		(2): It creates an array a of length n = v.size(), initialized to v.
		0?n?10**8
		O(n)

	void seg.set(int p, S x)
		It assigns x to a[p]
		0?p<n
		O(logn)

	S seg.get(int p)
		It returns a[p]
		0?p<n
		O(1)

	S seg.prod(int l, int r)
		It returns binary_operation(a[l], ..., a[r - 1]), assuming the properties of the monoid. It returns identity_element() if l=r.
		0?l?r?n
		O(logn)

	S seg.all_prod()
		It returns op(a[0], ..., a[n - 1]), assuming the properties of the monoid. It returns identity_element() if n=0.
		O(1)

	(1) int seg.max_right<check_function>(int l)
	(2) int seg.max_right<F>(int l, F check_function)
		(1): It applies binary search on the segment tree. The function bool check_function(S x) should be defined.
		(2): The function object that takes S as the argument and returns bool should be defined.

		It returns an index r that satisfies both of the following :-
			r = l or check_function(binary_operation(a[l], a[l + 1], ..., a[r - 1])) = true
			r = n or check_function(binary_operation(a[l], a[l + 1], ..., a[r])) = false

		If check_function is monotone, this is the maximum r that satisfies check_function(binary_operation(a[l], a[l+1], ..,a[r-1]))=true

		if check_function is called with the same argument, it returns the same value, i.e., check_function has no side effect.
		check_function(identity_element()) = true
		0?l?n

		O(logn)

	(1) int seg.min_left<check_function>(int r)
	(2) int seg.min_left<F>(int r, F check_function)
		(1): It applies binary search on the segment tree. The function bool check_function(S x) should be defined.
		(2): The function object that takes S as the argument and returns bool should be defined.

		It returns an index l that satisfies both of the following :-
			l = r or check_function(binary_operation(a[l], a[l + 1], ..., a[r - 1])) = true
			l = 0 or check_function(binary_operation(a[l - 1], a[l], ..., a[r - 1])) = false

		If check_function is monotone, this is the minimum l that satisfies check_function(binary_operation(a[l], a[l+1], ..,a[r-1]))=true

		if check_function is called with the same argument, it returns the same value, i.e., check_function has no side effect.
		check_function(identity_element()) = true
		0?r?n

		O(logn)

	https://atcoder.github.io/ac-library/production/document_en/segtree.html

*/

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
	segtree() : segtree(0) {}
	explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
	explicit segtree(const std::vector<S>& v) : _n((int)(v.size())) {
		log = segtree::ceil_pow2(_n);
		size = 1 << log;
		d = std::vector<S>(2 * size, e());
		for (int i = 0; i < _n; i++) d[size + i] = v[i];
		for (int i = size - 1; i >= 1; i--) {
			update(i);
		}
	}

	void set(int p, S x) {
		assert(0 <= p && p < _n);
		p += size;
		d[p] = x;
		for (int i = 1; i <= log; i++) update(p >> i);
	}

	S get(int p) const {
		assert(0 <= p && p < _n);
		return d[p + size];
	}

	S prod(int l, int r) const {
		assert(0 <= l && l <= r && r <= _n);
		S sml = e(), smr = e();
		l += size;
		r += size;

		while (l < r) {
			if (l & 1) sml = op(sml, d[l++]);
			if (r & 1) smr = op(d[--r], smr);
			l >>= 1;
			r >>= 1;
		}
		return op(sml, smr);
	}

	S all_prod() const { return d[1]; }

	template <bool (*f)(S)> int max_right(int l) const {
		return max_right(l, [](S x) { return f(x); });
	}
	template <class F> int max_right(int l, F f) const {
		assert(0 <= l && l <= _n);
		assert(f(e()));
		if (l == _n) return _n;
		l += size;
		S sm = e();
		do {
			while (l % 2 == 0) l >>= 1;
			if (!f(op(sm, d[l]))) {
				while (l < size) {
					l = (2 * l);
					if (f(op(sm, d[l]))) {
						sm = op(sm, d[l]);
						l++;
					}
				}
				return l - size;
			}
			sm = op(sm, d[l]);
			l++;
		} while ((l & -l) != l);
		return _n;
	}

	template <bool (*f)(S)> int min_left(int r) const {
		return min_left(r, [](S x) { return f(x); });
	}
	template <class F> int min_left(int r, F f) const {
		assert(0 <= r && r <= _n);
		assert(f(e()));
		if (r == 0) return 0;
		r += size;
		S sm = e();
		do {
			r--;
			while (r > 1 && (r % 2)) r >>= 1;
			if (!f(op(d[r], sm))) {
				while (r < size) {
					r = (2 * r + 1);
					if (f(op(d[r], sm))) {
						sm = op(d[r], sm);
						r--;
					}
				}
				return r + 1 - size;
			}
			sm = op(d[r], sm);
		} while ((r & -r) != r);
		return 0;
	}

  private:
	int _n, size, log;
	std::vector<S> d;

	void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }

	// @param n `0 <= n`
	// @return minimum non-negative `x` s.t. `n <= 2**x`
	int ceil_pow2(int n) {
		int x = 0;
		while ((1U << x) < (unsigned int)(n)) x++;
		return x;
	}

};

int binary_operation(int a,int b)
{
	return a+b;
}

int identity_element()
{
	return 0;
}

int target;
bool check_function(int v)
{
	return v<=target;
}

const int inf = 2e18;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void solve()
{
	int n,k;
	cin>>n>>k;

	vector<int> v(n);
	vector <bool> vis(n+10);
	map<int,int> freq,id;

	for(int i=0;i<n;i++){
		cin>>v[i];
		if(v[i]<=n)vis[v[i]]=true;
		freq[v[i]]++;
	}
	vector<pair<int,int> > tt;
	for(auto p : freq){
		tt.push_back({p.second,p.first});
	}

	sort(tt.begin(),tt.end());

	int tot=tt.size();
	vector <int> temp1(tot,1),temp2(tot);
	int zz=0;
	for(int i=0;i<tot;i++){
		auto p = tt[i];
		id[p.second]=zz++;
		temp2[i]=p.first;
	}

	assert(zz==tot);


	segtree<int,binary_operation,identity_element> sum(temp2);
	segtree<int,binary_operation,identity_element> cnt(temp1);

	int ans=inf;

	auto it = id.find(0);
	if(it!=id.end()){
		auto p = it->second;
		sum.set(p,0);
		cnt.set(p,0);
		tot--;

		if(temp2[p]<=k){
			int ava=k-temp2[p];
			if(p==zz-1){
				if(zz>=2){
					int dif=zz-1;
					for(int i=0;i<zz-2;i++){
						if(ava>=temp2[i]){
							ava-=temp2[i];
							dif--;
						}else break;
					}
					ans=min(ans,dif);

				}else{
					if(temp2[p]<=k)ans=min(ans,1ll);
				}
			}else{
				int dif=zz-1;
				for(int i=0;i<zz-1;i++){
					if(i==p)continue;
					if(ava>=temp2[i]){
						ava-=temp2[i];
						dif--;
					}else break;
				}
				ans=min(ans,dif);
			}

		}

		
	}else{
		int dif=zz;
		int ava=k;
		for(int i=0;i<zz-1;i++){
			if(ava>=temp2[i]){
				ava-=temp2[i];
				dif--;
			}else break;
		}
		ans=min(ans,dif);
	}

	int reqTTTT=0;

	// dbg(vis);

	for(int mex=1;mex<=n+1;mex++){
		
		if(!vis[mex-1])reqTTTT++;
		auto it = id.find(mex);
		if(it!=id.end()){
			auto p = it->second;
			sum.set(p,0);
			cnt.set(p,0);
			tot--;
		}

		// if(mex==5){
		// 	// dbg(reqTTTT);
		// }

		int reqT=reqTTTT;

		int reqG=freq[mex];
		int avaO=k;

		reqT-=reqG;
		avaO-=reqG;

		if(avaO<0)continue;
		reqT=max(reqT,0ll);

		target=avaO;

		int mxr = sum.max_right<check_function>(0);
		int totop = sum.prod(0,mxr);

		assert(totop<=avaO);
		avaO-=totop;
		reqT-=totop;

		int move = cnt.prod(0,mxr);
		
		reqT=max(reqT,0ll);
		
		avaO-=reqT;

		if(avaO<0)continue;

		assert(tot>=move);

		int diff=tot-move + mex;

		ans=min(ans,diff-mex);
		// if(diff-mex==1){
		// 	dbg(mex);
		// }

	}


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