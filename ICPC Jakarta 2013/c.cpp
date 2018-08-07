#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 999999999;

int bfs(vector< vector< pair<int,int> > > &grafo, int node, vector<bool> &visitados){
	if( visitados[node] ) return 0;
	visitados[node] = true;

	int vizinhos = 1;
	for(int i=0; i<grafo[node].size(); i++){
		if( visitados[ grafo[node][i].first ] ) continue;

		if( grafo[node][i].second == INF )
			grafo[node][i].second = bfs( grafo, grafo[node][i].first, visitados );
		vizinhos += grafo[node][i].second;
	}
	return vizinhos;
}


int solve( vector< vector< pair<int,int> > > &grafo, int origem ){
	int valor = 0;
	for(int i=0; i<grafo[origem].size(); i++){
		for(int j=i+1; j<grafo[origem].size(); j++){
			valor += grafo[origem][i].second * grafo[origem][j].second;
		}
	}
	//cerr << "solve " << origem << ": " << valor << endl;
	return valor;
}



int main(){
	int t, n;
	
	cin >> t;
	for(int caso=1; caso<=t; caso++ ){
		int vertices, arestas;
		cin >> vertices;

		// first -> destino / second -> custo
		vector< vector< pair<int,int> > > grafo ( vertices );
		arestas = vertices - 1;
		int origem, destino;
		for(int i=0; i<arestas; i++){
			cin >> origem >> destino;
			origem--;
			destino--;
			grafo[origem ].push_back( make_pair(destino, INF) );
			grafo[destino].push_back( make_pair(origem , INF) );
		}
		

		for(int i=0; i<vertices; i++){
			vector<bool> visitados (vertices, false);
			bfs( grafo, i, visitados );
		}

		/*for(int i=0; i<vertices; i++){
			cerr << i+1 << ": ";
			for(int j=0; j<grafo[i].size(); j++){
				cerr << "(" << grafo[i][j].first+1 << " , " << grafo[i][j].second << ") ; ";
			}
			cerr << endl;
		}*/


		int melhor = 0;
		int id = 0;
		for(int i=0; i<vertices; i++){
			int valor = solve( grafo, i );
			if( melhor < valor ){
				melhor = valor;
				id = i;
			}
		}


		//cerr << "Melhor id: " << id << endl;
		/*
		if( melhor == INF )
			for(;;);
		if( melhor == 0 )
			grafo[INF][INF].first = -1;
		*/

		cout << "Case #" << caso << ": " << melhor << endl;
	}

	return 0;
}


