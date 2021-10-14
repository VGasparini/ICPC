#include <bits/stdc++.h>

using namespace std;

#define SHIFTL(x, y) ((x) << (y))
#define SHIFTR(x, y) ((x) >> (y))

#define BIT(x) (1LL << (x))

typedef long long ll;
typedef unsigned long long ull;
typedef tuple<int, int> i2;
typedef tuple<int, int, int> i3;
typedef tuple<int, int, int, int> i4;
typedef vector<int> vi;
typedef vector<i2> vi2;
typedef vector<i3> vi3;
typedef vector<vi2> v2i2;
typedef vector<string> vs;
typedef vector<ll> vll;

#define MAXN 800

// int v[MAXN][MAXN], l[MAXN], r[MAXN];

ll dp[800][10005];
ll dp2[800][10005];
ll mod = 1e9 + 7;

ll k, l;

// ll solve(int cur, int rem) {
//   if (rem == 0) return 1;
//   if (cur > k) return 0;


// }

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    cin >> k >> l;
    vector<vector<int>> v(k, vi(k));
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < k; ++j)
            scanf("%d", &v[i][j]);
    int n;
    cin >> n;
    vector<vector<int>> left(k + 5, vi(n + 5)), right(k + 5, vi(n + 5));
    vi p(n + 5);
    for (int i = 0; i < n - 1; ++i)
        scanf("%d", &p[i]);
    

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            left[j][i] = lower_bound(v[j].begin(), v[j].end(), p[i] - l) - v[j].begin();
            right[j][i] = upper_bound(v[j].begin(), v[j].end(), p[i] + l) - v[j].begin();
            // cout << "(" << j <<  ", " << left[j][i] << ", " << right[j][i] << ") ";
        }
        // cout << endl;
    }

    for (int i = 0; i < k; ++i) {
        dp[i][n - 1] = 1;
        dp2[i][n - 1] = i + 1;
    }
    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = 0; j < k; ++j)
        {
            ll R = (right[j][i] - 1 >= 0) ? dp2[right[j][i] - 1][i + 1] : 0;
            ll L = ((left[j][i] - 1 >= 0) ? dp2[left[j][i] - 1][i + 1] : 0);
            dp[j][i] = (R - L + mod) % mod;
            dp2[j][i] = j > 0 ? ((dp2[j - 1][i] + dp[j][i]) % mod) : (dp[j][i] % mod);
        }
    }

    // for (int i = 0; i <= n - 1; ++i) {
    //   for (int j = 0; j < k; ++j) {
    //     cout << dp[j][i] << " ";
    //   }
    //   cout << endl;
    // }

    ll res = 0;
    for (int i = 0; i < k; ++i)
    {
        res = (res + dp[i][0]) % mod;
    }

    cout << res << endl;

    return 0;
}