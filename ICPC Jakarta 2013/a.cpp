#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long int LLI;
const LLI INF = 9999999999999999L;
const LLI MAXN = 150;
LLI pd[ MAXN ][ MAXN ];


void initPD( LLI n, LLI g ){
	for(LLI i=0; i<MAXN; i++)
		for(LLI k=0; k<=MAXN; k++)
			pd[i][k] = -1;
}


LLI solve( vector<LLI> &numeros, LLI left, LLI g, LLI right ){
	LLI custo = INF;
	if( left >= right ) return INF;
	if( g==1 )
		return numeros[right-1] - numeros[left];

	for(LLI i=left; i<right; i++){
		LLI c = numeros[i] - numeros[left];
		if( pd[i+1][g-1] == -1 ){
			pd[i+1][g-1] = solve( numeros, i+1, g-1, right );
		}
		c += pd[i+1][g-1]; 
		if( custo > c )
			custo = c;
	}
	return custo;
}




int main(){
	LLI t, n, g;
	
	cin >> t;
	for(LLI caso=1; caso<=t; caso++ ){
		cin >> n >> g;

		vector<LLI> numeros(n);
		for(LLI k=0; k<n; k++)
			cin >> numeros[k];
		sort( numeros.begin(), numeros.end() );
		initPD( n, g );

		LLI valor = solve( numeros, 0 , g, n );
		cout << "Case #" << caso << ": " << valor << endl;
	}

	return 0;
}


