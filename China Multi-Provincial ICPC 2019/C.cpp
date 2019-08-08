#include <bits/stdc++.h>
#define endl '\n'

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int caso=1;caso<=n;caso++){
    	int n, m;
    	cin >> n >> m;

    	string a, b, c;
    	cin >> a >> b >> c;

    	int aux = b[0] - a[0];

    	string ans = "";
    	for(int i=0; i<m; i++){
    		int t = (c[i] - 'A') - aux;
    		t %= 26;
    		while (t < 0)
    			t += 26;
    		ans += (char) (t + 'A');
    	}
    	cout << "Case #" << caso << ": " << ans << endl;
    }
    return 0;
}
