#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;
typedef long long int LLI;

int dp[26][26];

int formula(int a, int b){
	return min( abs(a - b) , 24-abs(a - b) );
}

int solve( vector<int> &zonas, int e, int d ){
	if( d - e < 2 ) return formula(zonas[d], zonas[e]);
	if( dp[e][d] >= 0 ) return dp[e][d];

	int op1 = formula(zonas[e], zonas[e+1]) + solve(zonas, e+2, d);
	int op2 = formula(zonas[e], zonas[d]) + solve(zonas, e+1, d-1);
	dp[e][d] = min( op1, op2 );
	return dp[e][d];
}


int main(){
	int n;
	
	while( cin >> n ){
		vector<int> acumulador( 24 );
		int aux;
		for( int i=0; i<n; i++){
			cin >> aux;
			acumulador[ aux + 11 ] += 1;
		}

		
		vector<int> zonas;
		for( int i=0; i<24; i++){
			if( acumulador[i] % 2 == 1 ){
				zonas.push_back( i - 11 );
			}
		}
		sort( zonas.begin() , zonas.end() );


		for(int i=0; i<26; i++)
			for(int j=0; j<26; j++)
				dp[i][j] = -1;

		/*for( int i=0; i<zonas.size(); i++)
			cerr << zonas[i] << " ";
		cerr << endl;*/

		int custo = 0;
		if( zonas.size() > 0 ) 
			custo = solve( zonas, 0, zonas.size()-1 );
		cout << custo << endl;
	}

	return 0;
}

