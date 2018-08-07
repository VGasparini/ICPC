#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){

	int n, dx, dy, x, y;
	for(;;){
		cin >> n;
		if( n==0 ) break;
		
		int picos = 0;
		int pontos[n+1];
		for(int i=0; i<n; i++)
			cin >> pontos[i];
		pontos[n] = pontos[0];

		for(int i=1; i<n; i++){
			if( pontos[i] > pontos[i-1] && pontos[i] > pontos[i+1] )
				picos++;
			else if( pontos[i] < pontos[i-1] && pontos[i] < pontos[i+1] )
				picos++;
		}

		if( pontos[0] > pontos[n-1] && pontos[0] > pontos[1] )
			picos++;
		else if( pontos[0] < pontos[n-1] && pontos[0] < pontos[1] )
			picos++;

		cout << picos << endl;
	}

	return 0;
}