#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int prim(vector< vector< pair<int,int> > > &grafo, vector<int> &powerPlants){
	// first => peso / second => destino
	set< pair<int,int> > conjunto;
	bool visitados[ grafo.size() ];
	for(int i=0; i<grafo.size(); i++)
		visitados[i] = false;

	for(int i=0; i<powerPlants.size(); i++){
		int pp = powerPlants[i];
		visitados[pp] = true;
		for(int k=0; k<grafo[pp].size(); k++){
			conjunto.insert( make_pair(grafo[pp][k].first , grafo[pp][k].second) );
		}
	}

	int conectados = grafo.size() - powerPlants.size();
	int custo = 0;
	while( conectados > 0 ){
		pair<int,int> atual = *conjunto.begin();
		conjunto.erase( conjunto.begin() ) ;
		if( visitados[ atual.second ] ) continue;

		visitados[ atual.second ] = true;
		conectados--;
		custo += atual.first;
		//cerr << "escolhido: " << atual.second << " - $" << atual.first << " (" << conectados << ")" << endl;
		if( conectados == 0 ) break;

		for(int i=0; i< grafo[atual.second].size(); i++){
			int vizinho = grafo[ atual.second ][i].second;
			if( visitados[ vizinho ] == false )
				conjunto.insert( make_pair( grafo[atual.second][i].first, vizinho ) );
		}
	}
	return custo;
}


int main(){
	int t, n;
	
	cin >> t;
	for(int caso=1; caso<=t; caso++ ){
		int vertices, arestas, plants;
		cin >> vertices >> arestas >> plants;

		vector< vector< pair<int,int> > > grafo ( vertices );

		vector<int> powerPlants( plants );
		for(int i=0; i<plants; i++){
			cin >> powerPlants[i];
			powerPlants[i]--;
		}
		
		int origem, destino, peso;
		for(int i=0; i<arestas; i++){
			cin >> origem >> destino >> peso;
			grafo[ origem-1  ].push_back( make_pair(peso, destino-1) );
			grafo[ destino-1 ].push_back( make_pair(peso, origem-1 ) );
		}

		int custo = prim(grafo, powerPlants);
		cout << "Case #" << caso << ": " << custo << endl;
	}

	return 0;
}


