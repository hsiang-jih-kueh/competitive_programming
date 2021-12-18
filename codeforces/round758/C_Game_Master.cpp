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
using vb = vector<char>; // char faster
using vvb = vector<vector<char>>;

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

void solve(int tc)
{
	int n;
	cin >> n;
	// relative ordering ok alr.
	vii a(n);
	vii b(n);
	forn(i, 0, n)
	{
		a[i].se = i;
		cin >> a[i].fi;
	}
	forn(i, 0, n)
	{
		b[i].se = i;
		cin >> b[i].fi;
	}
	sort(all(a));
	sort(all(b));
	vi posa(n);
	vi posb(n);
	forn(i, 0, n)
	{
		posa[a[i].se] = i;
		posb[b[i].se] = i;
	}
	vb vis(n, 0);
	queue<int> q;
	string ans(n, '0');
	q.push(a.back().se);
	q.push(b.back().se);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		if (!vis[t])
		{
			vis[t] = true;
			ans[t] = '1';
			if (posa[t] + 1 < n)
			{
				q.push(a[posa[t] + 1].se);
			}
			if (posb[t] + 1 < n)
			{
				q.push(b[posb[t] + 1].se);
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
	int t;
	cin >> t;
	repn(i, 1, t)
	{
		solve(i);
	}
	return 0;
}