#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
    long long n, k, ans;
    cin >> n >> k;
    if (k*2 >= n){
        cout << 10 << endl;
    }else{
        ans = ((n) / (k) + (((n) % (k)) ? 1 : 0)) * 5;
        cout << ans << endl;
    }
}