#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
//template ends
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, tc;
    cin >> n >> tc;
    int n;
    while (tc--)
    {
        int k;
        cin >> k;
        int l = 1, r = n, m;
        while (l != r)
        {
            int a;
            m = (l + r) / 2;
            a = ft.sum(l - 1, m - 1);
            a = (m - l + 1) - a;
            if (k > a)
            {
                l = m + 1;
                k -= a;
            }
            else
            {
                r = m;
            }
        }
        cout << "! " << l << "\n";
        ft.add(l - 1, 1);
        cout.flush();
    }
    return 0;
}