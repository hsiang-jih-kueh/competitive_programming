#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(c) ((int)(c).size())
#define all(c) (c).begin(), (c).end()
#define forn(i, a, b) for (int i = a, __end = (b); i < __end; i++)		 //[a,b)
#define fornr(i, a, b) for (int i = b - 1, __end = (a); i >= __end; i--) //[a,b) reversed
#define repn(i, a, b) for (int i = a, __end = (b); i <= __end; i++)		 //[a,b]
#define repnr(i, a, b) for (int i = b, __end = (a); i >= __end; i--)	 //[a,b] reversed
#define setmin(a, b) a = min(a, (b))
#define setmax(a, b) a = max(a, (b))
#define NIL 0
#define INF INT_MAX
#define INFLL LLONG_MAX
#define int128 __int128_t

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const int MAXN = 200005;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
	int n, m;
	cin >> n >> m;
	vvi c(n, vi(m));
	map<int, pair<vi, vi>> cp;
	ll ans = 0;
	forn(i, 0, n)
	{
		forn(j, 0, m)
		{
			cin >> c[i][j];
			cp[c[i][j]].fi.pb(i);
			cp[c[i][j]].se.pb(j);
		}
	}
	for (auto [k, p] : cp)
	{
		if (sz(p.fi) > 1)
		{
			sort(all(p.fi));
			ll s = 0;
			ll _n = sz(p.fi);
			ll i = _n;
			for (auto x : p.fi)
			{
				s += x;
			}
			for (auto x : p.fi)
			{
				ans += s;
				ans -= _n * x;
				s -= x;
				_n--;
			}
		}
		if (sz(p.se) > 1)
		{
			sort(all(p.se));
			ll s = 0;
			ll _n = sz(p.se);
			ll i = _n;
			for (auto x : p.se)
			{
				s += x;
			}
			for (auto x : p.se)
			{
				ans += s;
				ans -= _n * x;
				s -= x;
				_n--;
			}
		}
	}
	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}