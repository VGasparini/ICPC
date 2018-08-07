#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 501;
const int INF = 999999999;
int mapa[MAX][MAX];
int mapa_max[MAX][MAX];
int linhas, colunas;

class Node{
public:
	int x, y, valor, tempo;
	Node(int x, int y, int v, int t){
		this->x = x;
		this->y = y;
		valor = v;
		tempo = t;
	}
};


int bfs( ){
	vector< Node > visitar;
	visitar.push_back( Node(0,1,mapa[0][0], 1) );
	visitar.push_back( Node(1,0,mapa[0][0], 1) );

	while( !visitar.empty() ){
		Node no = visitar[0];
		visitar.erase( visitar.begin() );
		if( no.valor==0 ) continue;

		int menor = min( mapa[no.y][no.x] - no.tempo , no.valor );
		if( mapa_max[no.y][no.x] < menor ){
			cerr << no.y << " " << no.x << " => " << menor << " " << no.tempo << endl;
			mapa_max[no.y][no.x] = menor;
			visitar.push_back( Node(no.y-1 , no.x , menor, no.tempo+1) );
			visitar.push_back( Node(no.y , no.x+1 , menor, no.tempo+1) );
			visitar.push_back( Node(no.y+1 , no.x , menor, no.tempo+1) );
			visitar.push_back( Node(no.y , no.x-1 , menor, no.tempo+1) );
		}
	}
	if( mapa_max[linhas-1][colunas-1] == 1 ) return 0;
	return mapa_max[linhas-1][colunas-1];
}



int main(){	
	cin >> linhas >> colunas;

	for(int i=0; i<linhas; i++){
		for(int k=0; k<colunas; k++){
			cin >> mapa[i][k];
			mapa_max[i][k] = -1;
		}
	}
	
	cout << bfs( )-1 << endl;
	return 0;
}

