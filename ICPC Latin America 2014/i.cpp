#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long int LLI;

int dfs( vector< vector< pair<int,int> > > &grafo, vector< pair<int,int> > &grafoReverso, vector<bool> &amigoBool, 
	     vector<int> &distancias, int no, int valor=0 ){
	if( distancias[no] != -1 ) return distancias[no];

	distancias[no] = valor;
	if( grafo[no].size()==0 ){
		if( amigoBool[ no ] )
			return grafoReverso[no].first;
		else
			return 0;
	}

	int acumulador = 0;
	for(int i=0; i<grafo[no].size(); i++){
		int vizinho = grafo[no][i].second;
		acumulador += dfs( grafo, grafoReverso, amigoBool, distancias, vizinho , valor + grafo[no][i].first );
	}
	if( acumulador == 0 ){
		if( amigoBool[ no ] ) return grafoReverso[no].first;
		else return 0;
	}
	return acumulador + grafoReverso[no].first;
}





int solver( vector< pair<int,int> > &grafoReverso, int no ){
	if( no==0 ) return 0;

	int pai = grafoReverso[no].second;
	int custo = grafoReverso[no].first;
	while( pai != 0 ){
		custo += grafoReverso[pai].first;
		pai = grafoReverso[pai].second;
	}
	return custo;
}




int main(){
	int n, f;
	
	while( cin >> n >> f ){
		vector< vector< pair<int,int> > >  grafo( n );
		vector< pair<int,int> >  grafoReverso( n );
		vector< int > amigos(f);

		for(int i=1; i<n; i++){
			int a, b, c;
			cin >> a >> b >> c;
			a--;
			b--;
			grafo[a].push_back( make_pair(c,b) );
			grafoReverso[b] = make_pair(c,a);
		}

		vector<bool> amigoBool (n, false);
		for(int i=0; i<f; i++){
			cin >> amigos[i];
			amigos[i]--;
			amigoBool[ amigos[i] ] = true;
		}


		vector< int > distancias (n, -1);
		int custoTotal = dfs( grafo, grafoReverso, amigoBool, distancias, 0 );
		//cerr << "Custo Total: " << custoTotal << endl;

/*
		for(int i=0; i<n; i++)
			cerr << i << " => " << distancias[i] << endl;
		cerr << endl;
*/
		int maior = 0;
		int maiorID = 0;
		for(int i=0; i<f; i++){
			int a = amigos[i];
			if( maior < distancias[a] ){
				maior = distancias[a];
				maiorID = a;
			}
		}

		//cerr << "Amigo: " << maiorID << " - " << maior << endl;
		int caminho = solver( grafoReverso , maiorID );
		//cerr << "caminho: " << caminho << endl;
		cout << custoTotal - caminho << endl;
	}

	return 0;
}

