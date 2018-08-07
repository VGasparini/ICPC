#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(){
	int n;
	
	cin >> n;
	double total = 0;
	vector<int> votos(n);
	for(int i=0; i<n; i++){
		cin >> votos[ i ];
		total += votos[i];
	}

	sort( votos.begin(), votos.end() );

	int maior = votos[n-1];
	int segundo = votos[ n-2 ];
	double porcentagemPrimeiro = maior *100  / total;
	double porcentagemSegundo = segundo *100 / total;
	//cerr << "Total: " << total << endl;
	//cerr << "1o: " << porcentagemPrimeiro << endl;
	//cerr << "2o: " << porcentagemSegundo << endl;

	if( porcentagemPrimeiro >= 45 || (porcentagemPrimeiro>=40 && porcentagemPrimeiro-porcentagemSegundo>=10) )
		cout << "1" << endl;
	else
		cout << "2" << endl;
	return 0;
}

