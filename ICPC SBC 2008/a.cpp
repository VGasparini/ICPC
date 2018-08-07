#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void computa( string numero, bool *removidos, int apagar ){
	int i=0;
	do{
		int maior = numero[i];
		int x=0;
		for( ; x<apagar; x++){
			maior = max( maior, numero[i+x] );
			if( numero[i+x]==9 ) break;
		}

		for(int aux=i+x; i<aux; i++){
			removidos[i] = true;
			apagar--;
		}

	} while( apagar > 0 );
}



int main(){
	string numero;

	for(;;){
		cin >> n >> apagar;
		if( n==0 && apagar==0 ) break;
		cin >> numero;
		bool removidos[numero.size()];
		for(int i=0; i<numero.size(); i++)
			removidos[i] = false;

		computa(numero, removidos, apagar);
		for(int i=0; i<numero.size(); i++)
			if( removidos[i] )
				putchar( numero[i] );
	}

	return 0;
}


