#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long int LLI;

const int TAM = 1000001;
int ordem[TAM];
vector<int> primes;

void crivo(vector<bool> &primos){
	for(int i=2; i<TAM; i++){
		if( !primos[i] ){
			continue;
		}
		primes.push_back(i);
		for( int k=i*2; k<TAM; k+=i )
			primos[k] = false;
	}

	/*for(int i=2; i<100; i++)
		if( primos[i] )
			cerr << i << " ";
	*/
}

int fatorarSoma( int valor ){
	set<int> divisores;
	for(int k=0; k<primes.size(); k++){
		int i = primes[k];
		if( valor % i == 0 ){
			valor = valor / i;
			//cerr << "divisor: " << i << endl;
			divisores.insert(i);
			k--;
		}
	}


	int somaDivisores = 0;
	set<int>::iterator it;
	for(it=divisores.begin(); it!=divisores.end(); ++it)
		somaDivisores += *it;
	return somaDivisores;
}


void solver(int n){
	if( ordem[n] != -1 ) return;
	int fator = fatorarSoma(n);
	//if( fator == 0 ) ordem[n] = 1;
	if( fator==n ){
		ordem[n] = 1;
		return;
	}
	solver( fator );
	ordem[n] = ordem[fator] + 1;
}



int main(){
	vector<bool> primos(TAM, true);
	crivo( primos );

	for(int i=1; i<TAM; i++)
		ordem[i] = -1;

	for(int i=1; i<TAM; i++){
		solver( i );
		cout << ordem[i] << ",";
		//cerr << i << " -> " << ordem[i] << endl;
	}
	
	return 0;
}

