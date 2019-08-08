#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // não usar printf ou scanf
    int a,b,k;
    int n; cin >> n;
    for(int i=0; i<n; i++){
    	cin >> a >> b;
    	if (a>b+1 || a%2) cout << "Kilani" << endl;
    	else cout << "Ayoub" << endl;
    }
}