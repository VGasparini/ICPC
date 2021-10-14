#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int x;
    cin >> n >> x;
    pair<int, int> windows[n + 1];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        windows[i] = make_pair(a, a + b);
    }
    sort(windows, windows + n);
    int start = 0;
    int minConf = 1e9;
    for (int i = 0; i <= 480; i++)
    {
        int pos = i;
        int j = 0;
        int conf = 0;
        while (j < n)
        {
            while (j < n && pos > windows[j].second)
            {
                j++;
            }
            if (j == n)
                break;
            if (pos >= windows[j].first && pos <= windows[j].second)
            {
                int diff = windows[j].second - pos;
                int p = ceil((double)diff / x);
                if (diff % x == 0)
                    p++;

                conf += p;
                pos += p * x;
                if (conf > minConf)
                {
                    break;
                }
            }
            else
            {
                int p = ceil((double)(windows[j].first - pos) / x);
                pos += p * x;
            }
        }
        if (conf < minConf)
        {
            minConf = conf;
            start = i;
            if (minConf == 0)
            {
                break;
            }
        }
    }
    cout << start << " " << minConf << endl;
    return 0;
}