#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long int LLI;


LLI solver( string &numero, int tam ){
	LLI maxt = 1 << tam;
	vector<bool> visitados( maxt, false );
	LLI partes = 0;
	for(int i=0; i<=numero.size()-tam; i++){
		LLI indice = 0;
		for(int k=0; k<tam; k++){
			indice = indice << 1;
			if( numero[i+k] == '1' )
				indice += 1;
		}

		if( !visitados[indice] ){
			partes++;
			visitados[indice] = true;
		}
	} 
	return partes;
}



int main(){
	int n;
	string numero;
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> numero;

		//cerr << "Numero: " << numero << endl;
		LLI totalPartes = 1;
		int t=1;
		for( ; t<numero.size(); t++ ){
			totalPartes = totalPartes << 1;
			LLI partes = solver( numero , t );
			//cerr << "t: " << t << " => " << partes << " partes" << endl;
			if( partes < totalPartes )
				break;
		}
		cout << t << endl;
	}
	
	return 0;
}

