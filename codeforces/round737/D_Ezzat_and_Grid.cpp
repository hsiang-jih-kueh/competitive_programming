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
template <typename T, typename U>
struct seg_tree_lazy
{
	int S, H;

	T zero;
	vector<T> value;

	U noop;
	vector<bool> dirty;
	vector<U> prop;

	seg_tree_lazy<T, U>(int _S, T _zero = T(), U _noop = U())
	{
		zero = _zero, noop = _noop;
		for (S = 1, H = 1; S < _S;)
			S *= 2, H++;

		value.resize(2 * S, zero);
		dirty.resize(2 * S, false);
		prop.resize(2 * S, noop);
	}

	void set_leaves(vector<T> &leaves)
	{
		copy(leaves.begin(), leaves.end(), value.begin() + S);

		for (int i = S - 1; i > 0; i--)
			value[i] = value[2 * i] + value[2 * i + 1];
	}

	void apply(int i, U &update)
	{
		value[i] = update(value[i]);
		if (i < S)
		{
			prop[i] = prop[i] + update;
			dirty[i] = true;
		}
	}

	void rebuild(int i)
	{
		for (int l = i / 2; l; l /= 2)
		{
			T combined = value[2 * l] + value[2 * l + 1];
			value[l] = prop[l](combined);
		}
	}

	void propagate(int i)
	{
		for (int h = H; h > 0; h--)
		{
			int l = i >> h;

			if (dirty[l])
			{
				apply(2 * l, prop[l]);
				apply(2 * l + 1, prop[l]);

				prop[l] = noop;
				dirty[l] = false;
			}
		}
	}

	void upd(int i, int j, U update)
	{
		i += S, j += S;
		propagate(i), propagate(j);

		for (int l = i, r = j; l <= r; l /= 2, r /= 2)
		{
			if ((l & 1) == 1)
				apply(l++, update);
			if ((r & 1) == 0)
				apply(r--, update);
		}

		rebuild(i), rebuild(j);
	}

	T query(int i, int j)
	{
		i += S, j += S;
		propagate(i), propagate(j);

		T res_left = zero, res_right = zero;
		for (; i <= j; i /= 2, j /= 2)
		{
			if ((i & 1) == 1)
				res_left = res_left + value[i++];
			if ((j & 1) == 0)
				res_right = value[j--] + res_right;
		}
		return res_left + res_right;
	}
};

struct node
{
	int max_rows;
	int last_row;
	node operator+(const node &n)
	{
		return max(*this, n);
	}
	friend bool operator<(const node &lhs, const node &rhs)
	{
		return lhs.max_rows < rhs.max_rows;
	}
};

struct update
{
	int new_max_rows;
	int new_last_row;
	bool no_op;

	node operator()(const node &n)
	{
		if (no_op)
		{
			return n;
		}
		else
		{
			return {new_max_rows, new_last_row};
		}
	}

	update operator+(const update &u)
	{
		return u;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vii> segs(n);
	set<int> coords;
	for (int j = 0; j < m; j++)
	{
		int i, l, r;
		cin >> i >> l >> r;
		segs[i - 1].push_back({l - 1, r - 1});
		coords.insert(l - 1);
		coords.insert(r - 1);
	}
	map<int, int> comp;
	int j = 0;
	for (auto c : coords)
	{
		comp[c] = j;
		j++;
	}
	seg_tree_lazy<node, update> st(comp.size(), {0, -1}, {0, -1, true});
	vi dp(n, -1);
	for (int i = 0; i < n; i++)
	{
		node mx = {0, -1};
		for (auto s : segs[i])
		{
			mx = max(mx, st.query(comp[s.first], comp[s.second]));
		}
		dp[i] = mx.last_row;
		mx.max_rows++;
		mx.last_row = i;
		for (auto s : segs[i])
		{
			st.upd(comp[s.first], comp[s.second], {mx.max_rows, mx.last_row, false});
		}
	}
	node last = st.query(0, comp.size() - 1);
	cout << n - last.max_rows << "\n";
	for (int i = n - 1; i >= 0; i--)
	{
		if (i != last.last_row)
		{
			cout << i + 1 << " ";
		}
		else
		{
			last.last_row = dp[last.last_row];
		}
	}
	return 0;
}