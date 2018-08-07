#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long int LLI;


Circle msc( vector<Ponto> &p )



int main(){
	int t;
	cin >> t;

	for(int casos=1; casos<t; casos++){
		int plantas, cortar;
		cin >> pĺantas >> cortar;
		vector<Ponto> planta[TAM];

		for(int i=0; i<plantas; i++)
			cin >> planta[i].first >> planta[i].second;
		double raio = solve( plantas, cortar );
	}
	
	return 0;
}

