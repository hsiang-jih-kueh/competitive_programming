#include <bits/stdc++.h>
using namespace std;

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
	long long sum, width;

	node operator+(const node &n)
	{
		return {sum + n.sum, width + n.width};
	}
};

struct update
{
	long long a;
	long long d;
	long long value;

	node operator()(const node &n)
	{
		return {n.sum + n.width * a + (n.width - 1) * (n.width) / 2 * d, n.width};
	}
	update leftChild(const update &u)
	{
	}
	update rightChild(const update &u)
	{
	}
	update operator+(const update &u)
	{
		return {type, value + u.value};
	}
};

int main()
{
	int N, Q;
	cin >> N >> Q;
	seg_tree_lazy<node, update> st(N, {0, 0}, {0, 0, 0});
	vector<node> leaves(N, {0, 1});
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		leaves[i].sum = temp;
	}
	st.set_leaves(leaves);

	int T, L, R, V;

	while (Q-- && cin >> T >> L >> R)
	{
		if (T == 3)
		{
			cout << st.query(L - 1, R - 1).sum << "\n";
		}
		else
		{
			cin >> V;
			bool type;
			if (T == 1)
			{
				type = false;
			}
			else
			{
				type = true;
			}
			st.upd(L - 1, R - 1, {type, V});
		}
	}
}