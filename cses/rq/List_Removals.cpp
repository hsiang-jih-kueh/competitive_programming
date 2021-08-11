#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

//template ends
const ll N = 2e5;
ll n; // array size

ll t[2 * N];
ll lst[N];
void build()
{ // build the tree
	for (ll i = n - 1; i > 0; --i)
		t[i] = (t[i << 1] + t[i << 1 | 1]);
}

void modify(ll p, ll value)
{ // set value at position p
	for (t[p += n] = value; p > 1; p >>= 1)
		t[p >> 1] = (t[p] + t[p ^ 1]);
}

ll query(ll l, ll r)
{ // sum on interval [l, r)
	ll res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1)
			res += (t[l++]);
		if (r & 1)
			res += (t[--r]);
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> lst[i];
		t[n + i] = 1;
	}
	build();
	for (int i = 0; i < n; i++)
	{
		int req;
		cin >> req;
		int l = 0;
		int r = n;
		int mid;
		int query_sum;
		int cum_sum = 0;
		while (true)
		{
			int mid = l + (r - l) / 2;
			if (mid == l)
			{
				break;
			}
			query_sum = query(l, mid);
			if (cum_sum + query_sum < req)
			{
				cum_sum += query_sum;
				l = mid;
			}
			else
			{
				r = mid;
			}
		}
		modify(l, 0);
		cout << lst[l] << " ";
	}
	return 0;
}