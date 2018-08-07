#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 999999999;
typedef long long int LLI;

LLI dfs(vector< vector< LLI > > &grafo, vector<LLI> &niveis, LLI node ){
	if( niveis[node]!=-1 ) return niveis[node];
	if( node == niveis.size()-1 ) return 1;

	LLI caminhos = 0;
	for(LLI i=0; i<grafo[node].size(); i++){
		LLI niv = dfs( grafo, niveis, grafo[node][i] );
		caminhos += niv;
	}

	niveis[node] = caminhos;
	return niveis[node];
}




LLI solverDFS(vector< vector< LLI > > &grafo, vector<LLI> &niveis, vector<LLI> &acumulado, LLI node ){
	if( acumulado[node] != -1 ) return acumulado[node];
	if( niveis[node]==0 ) return 0;
	if( node == niveis.size()-1 ) return 1;

	LLI melhor = 0;
	for(LLI i=0; i<grafo[node].size(); i++){
		LLI acumulador = niveis[node] + solverDFS( grafo, niveis, acumulado, grafo[node][i] );
		if( melhor < acumulador )
			melhor = acumulador;
	}

	acumulado[node] = melhor;
	return acumulado[node];
}



int main(){
	LLI nos, arestas;
	LLI origem, destino;

	cin >> nos >> arestas;

	vector< vector<LLI> > grafo ( nos );
	vector<LLI> niveis ( nos, -1 );

	for(LLI i=0; i<arestas; i++ ){
		cin >> origem >> destino;
		origem--;
		destino--;
		grafo[ origem ].push_back( destino );
	}

	dfs( grafo, niveis, 0 );

	vector<LLI> acumulado ( nos, -1 );
	LLI valor = solverDFS( grafo, niveis, acumulado, 0 );
	cout << valor <<  endl;

	return 0;
}

