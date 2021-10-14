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

#define MAXN 100005

int v[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        total += v[i];
    }
    int k = total / n;
    int p = 0;
    for (int i = 0; i < n; ++i)
    {
        v[i] = v[i] - k;
        if (v[i] > 0)
            p = i;
    }
    vll h(v, v + n);
    // cout << p << endl;
    // for (int i = 0; i < n; ++i)
    //     cout << h[i] << " ";
    // cout << endl;
    deque<i2> pos;
    ll res1 = 0;
    for (int i = 0; i < 2 * n; ++i)
    {
        int j = (p + i) % n;
        if (h[j] > 0)
        {
            pos.push_back({h[j], i});
            h[j] = 0;
        }
        else if (h[j] < 0)
        {
            while (pos.size() > 0 && h[j] < 0)
            {
                int px, pi;
                tie(px, pi) = pos.front();
                pos.pop_front();
                if (h[j] + px >= 0)
                {
                    res1 += -h[j] * (i - pi);
                    px += h[j];
                    h[j] = 0;
                    if (px > 0)
                        pos.push_front({px, pi});
                }
                else
                {
                    res1 += px * (i - pi);
                    h[j] += px;
                }
            }
        }
    }
    h = vll(v, v + n);
    ll res2 = 0;
    for (int i = 0; i < 2 * n; ++i)
    {
        int j = ((p - i) + 2 * n) % n;
        // cout << j << " " << h[j] << endl;
        if (h[j] > 0)
        {
            pos.push_back({h[j], i});
            h[j] = 0;
        }
        else if (h[j] < 0)
        {
            while (pos.size() > 0 && h[j] < 0)
            {
                int px, pi;
                tie(px, pi) = pos.front();
                // cout << "lel " << px << " " << pi << endl;
                pos.pop_front();
                if (h[j] + px >= 0)
                {
                    res2 += -h[j] * (i - pi);
                    px += h[j];
                    h[j] = 0;
                    if (px > 0)
                        pos.push_front({px, pi});
                }
                else
                {
                    res2 += px * (i - pi);
                    h[j] += px;
                }
            }
        }
        // cout << res2 << endl;
    }

    cout << min(res1, res2) << endl;

    return 0;
}