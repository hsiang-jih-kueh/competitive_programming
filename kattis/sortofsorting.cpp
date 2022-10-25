#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using cd = complex<ld>;
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

template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back // https://stackoverflow.com/questions/4303513/push-back-vs-emplace-back
#define mp make_pair
#define sz(c) size(c)
#define all(c) begin(c), end(c)
#define forn(i, a, b) for (int i = a, __end = (b); i < __end; i++)		 //[a,b)
#define fornr(i, a, b) for (int i = b - 1, __end = (a); i >= __end; i--) //[a,b) reversed
#define repn(i, a, b) for (int i = a, __end = (b); i <= __end; i++)		 //[a,b]
#define repnr(i, a, b) for (int i = b, __end = (a); i >= __end; i--)	 //[a,b] reversed
#define fora(a, x) for (auto &a : x)
/**
#define setmin(a, b) a = min(a, (b))
#define setmax(a, b) a = max(a, (b))
**/
template <class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#define INF INT_MAX
#define INFLL LLONG_MAX
#define int128 __int128_t

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double EPS = 1e-9;
const long long MOD = 1000000007;
const int MAXN = 200005;
const char nl = '\n';

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define FAST_IO                            \
	std::ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                         \
	cout.tie(NULL)
#define yn(flag) ((flag) ? "YES" : "NO")
#define sgn(x) (((x) > 0) ? 1 : (((x) < 0) ? -1 : 0))

bool cmp(const string &lhs, const string &rhs)
{
	if (lhs[0] == rhs[0])
	{
		return lhs[1] < rhs[1];
	}
	return lhs[0] < rhs[0];
}

int main()
{
	FAST_IO;
	int n;
	while (cin >> n)
	{
		vector<string> a(n);
		forn(i, 0, n)
		{
			cin >> a[i];
		}
		stable_sort(all(a), cmp);
		for (auto &s : a)
		{
			cout << s << nl;
		}
		cout << nl;
	}
	return 0;
}