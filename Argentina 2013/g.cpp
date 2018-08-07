#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long int LLI;

int main(){
	int n;
	
	cin >> n;
	vector<LLI> armyA(n);
	vector<LLI> armyB(n);
	for(int i=0; i<n; i++)
		cin >> armyA[ i ];

	for(int i=0; i<n; i++)
		cin >> armyB[ i ];

	sort( armyA.begin(), armyA.end() );
	sort( armyB.begin(), armyB.end() );

	int vitorias = 0;
	int k = n-1;
	for( int i=n-1; i>=0; i-- ){
		while( armyB[i] <= armyA[k] ){
			k--;
			if( k<0 ) break;
		}
		if( k<0 ) break;

		vitorias++;
		k--;
	}

	cout << vitorias << endl;
	return 0;
}

