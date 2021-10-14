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

#define MAXN 100005

int v[MAXN];

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n;
    cin >> n;
    int t_a, t_b;
    char p, q;
    cin >> p >> t_a >> q >> t_b;

    int x = 0;
    while (n--)
    {
        int a, b;
        cin >> p >> a >> q >> b;
        // cout << a << " " << b << endl;
        t_a += a;
        t_b += b;
        if (t_b >= 100)
        {
            ++t_a;
            t_b -= 100;
        }
        if (t_b != 0)
            ++x;
    }

    printf("%d\n", x);

    return 0;
}