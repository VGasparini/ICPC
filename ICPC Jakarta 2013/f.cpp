#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool compara(string& s, int i, int j, int t){
	for(; t > 0; t--, i++){
		if(s[i] != s[j-t]){
			return false;
		}
	}
	return true;
}

int process(string& s, int i, int j){
	int maior = 0;
	if(i == j){
		return 1;
	}
	if (i > j){
		return 0;
	}
	bool flag = false;
	int dif = j-i;
	for(int t=1; t <= dif; t++){
		if(compara(s, i, j, t)){
			flag = true;
			int aux = process(s, i+t, j-t) + 2;
			if (aux > maior){
				maior = aux;
			}
			break;
		}
	}
	if (!flag)	return 1;
	return maior;
}

int main(){
	int t, n;
	
	cin >> t;
	for(int caso=1; caso<=t; caso++ ){
		string s;
		cin >> s;

		int melhor = process(s, 0, s.size());

		cout << "Case #" << caso << ": " << melhor - 1 << endl;
	}

	return 0;
}


