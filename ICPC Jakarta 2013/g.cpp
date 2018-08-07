#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Paciente{
public:
	int t0, r, st0;

	Paciente(){ }
	Paciente(int t0, int st0, int r){
		this->t0 = t0;
		this->st0 = st0;
		this->r = r;
	}

	int getSeveridade(int t){
		return st0 + r*(t-t0);
	}
};

int main(){
	int t, n;
	
	cin >> t;
	for(int caso=1; caso<=t; caso++ ){
		cin >> n;

		vector<Paciente> pacientes;
		char situacao;
		int t0, st0, r;
		cout << "Case #" << caso << ":\n";

		for(int k=0; k<n; k++){
			//cerr << "k: " << k << " / " << n << endl;
			scanf( " %c", &situacao);
			//cerr << "situacao: " << situacao << endl;
			if( situacao == 'P' ){
				cin >> t0 >> st0 >> r;
				Paciente pac (t0, st0, r);
				pacientes.push_back( pac );
				//cerr << "Adicionou pac" << endl;
			}
			
			else if( situacao == 'A' ){
				//cerr << "Atendimento" << endl;
				cin >> t0;
				int maiorSeveridade = -1;
				int idMaiorSeveridade = 0;
				int maiorR;

				vector<Paciente>::iterator it = pacientes.begin();
				vector<Paciente>::iterator maiorIt = pacientes.end();
				for(int i=0; i<pacientes.size(); i++, ++it){
					int severidade = pacientes[i].getSeveridade( t0 );
					if( severidade > maiorSeveridade or (severidade == maiorSeveridade && pacientes[i].r > pacientes[idMaiorSeveridade].r) ){
						maiorSeveridade = severidade;
						idMaiorSeveridade = i;
						maiorIt = it;
						maiorR = pacientes[i].r;
					}
				}
				if( maiorIt != pacientes.end() ){
					cout << maiorSeveridade << " " << maiorR << endl;
					pacientes.erase( maiorIt );
				}
			}
		}
	}

	return 0;
}


