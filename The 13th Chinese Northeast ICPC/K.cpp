#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // não usar printf ou scanf
    long n;
    while(cin >> n){
    	int cont = 0;
    	while(n != 0){
    		long aux=n;
    		vector<int> dig;
    		while(aux != 0){
    			dig.push_back(aux - 10*((long)aux/10));
    			aux /= 10;
    		}
    		long m = 0;
    		sort(dig.begin(), dig.end());
    		for(int i:dig)
    			m = m*10 + i;
    		n = n-m;
    		cont++;
    	}
    	cout << cont << endl;
    }
}
