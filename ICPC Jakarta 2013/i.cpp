#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;


int solve( pair<int,int> *distancias, int n ){
	getmaior();
	simula movimento do maior;
	
}


int main(){
	int t, n, aneis;
	
	cin >> t;
	for(int caso=1; caso<=t; caso++ ){
		cin >> n >> aneis;

		pair<int,int> distancias[n];
		vector<int> moedas(n);
		for(int i=0; i<n; i++)
			cin >> moedas[i];
		sort( moedas.begin(), moedas.end() );

		distancias[0].first = abs(moedas[n-1] - moedas[0]);
		distancias[0].second = abs(moedas[1] - moedas[0]);
		for(int i=1; i<n; i++){
			distancias[i].first = abs(moedas[i] - moedas[i-1]);
			distancias[i].first = abs(moedas[i+1] - moedas[i]);
		}
		distancias[n-1].first =  abs(moedas[n-2] - moedas[n-1]);
		distancias[n-1].second = abs(moedas[n-1] - moedas[0]);

		int melhor = solve( distancias, n );

		cout << "Case #" << caso << ": " << melhor - 1 << endl;
	}

	return 0;
}


