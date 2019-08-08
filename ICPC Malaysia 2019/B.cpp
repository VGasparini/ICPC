#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int tests; cin >> tests;
    for (int test=1; test<=tests; test++){

        int n, s;
        cin >> n >> s;

        vector<int> v;

        for(int i=0; i<n; i++){
            int f, t;
            cin >> f >> t;
            int saving;
            if (t<=s) saving = f;
            else {
                saving = f-(t-s);
                } 
            v.push_back(saving);
        }
        sort(v.begin(), v.end());
        cout << "Case #" << test << ": " << v.back() << endl;
        v.clear();
    }
}
