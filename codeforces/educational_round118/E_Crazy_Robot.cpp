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

vvb grid;
int n, m;
bool oob(int i, int j)
{
	if (i < 0 || i >= n)
	{
		return true;
	}
	if (j < 0 || j >= m)
	{
		return true;
	}
	return false;
}

bool isopen(int i, int j)
{
	if (oob(i, j))
	{
		return false;
	}
	if (grid[i][j] == '.')
	{
		return true;
	}
	return false;
}

int co_surr_op(int i, int j)
{
	int c = 0;
	c += isopen(i + 1, j);
	c += isopen(i - 1, j);
	c += isopen(i, j + 1);
	c += isopen(i, j - 1);
	return c;
}
void solve(int tc)
{
	cin >> n >> m;
	grid.assign(n, vb(m));
	queue<pii> q;
	forn(i, 0, n)
	{
		string s;
		cin >> s;
		forn(j, 0, m)
		{
			grid[i][j] = s[j];
			if (grid[i][j] == 'L')
			{
				q.push({i - 1, j});
				q.push({i, j - 1});
				q.push({i + 1, j});
				q.push({i, j + 1});
			}
		}
	}
	while (!q.empty())
	{
		int i = q.front().fi;
		int j = q.front().se;
		q.pop();
		if (isopen(i, j) && co_surr_op(i, j) <= 1)
		{
			grid[i][j] = '+';
			q.push({i - 1, j});
			q.push({i, j - 1});
			q.push({i + 1, j});
			q.push({i, j + 1});
		}
	}
	forn(i, 0, n)
	{
		forn(j, 0, m)
		{
			cout << grid[i][j];
		}
		cout << "\n";
	}
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