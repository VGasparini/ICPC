#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
#define MAXN 1005

using namespace std;

char f(char antigo){
	switch(antigo){
		case '<':
			return '^';
		case '>':
			return 'v';
		case 'v':
			return '<';
		case '^':
			return '>';
		default:
			return '.';
	}
}

char matriz[4][MAXN][MAXN];

void tomba(int n, int rod){
	for(int i=1; i<=rod; i++){
		for(int linha=0; linha<n; linha++){
			for(int coluna=0; coluna<n; coluna++){
				matriz[i][coluna][n-1-linha] = f(matriz[i-1][linha][coluna]);
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // não usar printf ou scanf
    int n;
    cin >> n;
    string op;
    cin >> op;
    int ans=0;

    for(int i=0; i<op.length(); i++){
    	if (ans == 3 && op[i]=='R') ans = 0;
    	else if (ans == 0 && op[i]=='L') ans = 3;
    	else{
    		if (op[i] == 'L') ans -= 1;
    		else ans += 1;
    	}
    }

    for(int i=0; i<n; i++){
    	for(int j=0; j<n; j++){
    		cin >> matriz[0][i][j];
    	}
    }

    tomba(n, ans);

    for(int i=0; i<n; i++){
    	for(int j=0; j<n; j++){
    		cout << matriz[ans][i][j];
    	}
    	cout << endl;
    }
}