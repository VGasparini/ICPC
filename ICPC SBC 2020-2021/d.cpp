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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    priority_queue<int, vi, greater<int>> pq;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        pq.push(x);
    }

    bool ok = true;
    int k = -1;

    while (pq.size() > 2 || (!ok && pq.size() > 1))
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        if (x == y)
            pq.push(x + 1);
        else
        {
            if (!ok)
            {
                pq.push(x);
                pq.push(y);
                break;
            }
            else
            {
                ok = false;
                pq.push(y);
                k = x;
            }
        }
    }

    if (k != -1) pq.push(k);

    if (pq.size() == 2)
        cout << "Y" << endl;
    else
    {
        cout << "N" << endl;
    }

    // cout << "N" << endl;

    return 0;
}