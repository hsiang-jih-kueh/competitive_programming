
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
void solve()
{
	int n;
	cin >> n;
	vi a(2 * n);
	ull count = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> a[i];
		if (a[i] % 2 == 1)
		{
			count++;
		}
	}
	if (count == n)
	{
		cout << "Yes\n";
	}
	else
	{

		cout << "No\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}