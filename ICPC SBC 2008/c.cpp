#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 99999999;

int computa( vector<int> tabuas, int linhas, int medida ){
	int i = tabuas.size()-1;
	int j = 0;
	int qtd = 0;

	for( ; i>=0 && tabuas[i] > medida ; i-- );
	if( i<0 ) return INF;

	for( ; i>=0 && linhas>0; i-- ){
		if( tabuas[i] == medida ){
			linhas--;
			qtd++;
		}
		else{ //tenta combinar
			for( ; j<i && tabuas[i] + tabuas[j] < medida ; j++ );
			if( j>=i ) return INF;
			else if( tabuas[i] + tabuas[j] == medida ){
				linhas--;
				j++;
				qtd += 2;
			}
		}
	}

	if( linhas > 0 ) return INF;
	return qtd;
}



int main(){
	int x, y;
	int largura, n;

	for(;;){
		cin >> x >> y;
		if( x==0 && y==0 ) break;
		
		cin >> largura >> n;
		vector<int> tabuas(n);
		for(int i=0; i<n; i++)
			cin >> tabuas[i];

		sort( tabuas.begin(), tabuas.end() );
		//for(int i=0; i<n; i++) cerr << tabuas[i] << " "; cerr << endl;


		int qtd = INF;
		// caso tentar usar na vertical
		if( (y*100) % largura == 0){
			int linhas = y*100 / largura;
			//cout << "linhas " << linhas << endl;
			qtd = computa( tabuas, linhas, x );
			//cout << "QTD V: " << qtd << endl;
		}
			
		
		// caso tentar usar na horizontal
		if( (x*100) % largura == 0){
			int linhas = x*100 / largura;
			qtd = min( qtd, computa( tabuas, linhas, y ) );
			//cout << "QTD H: " << aux << endl;
		}
		
		if( qtd == INF ) cout << "impossivel" << endl;
		else cout << qtd << endl;
	}

	return 0;
}


