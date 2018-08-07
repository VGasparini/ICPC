#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int N = 0;

void printVet( int *v, int n ){
	for(int i=0; i<n; i++)
		cout << v[i] << " ";
	cout << endl;
}


int merge(int *v, int left, int middle, int right){
	int tam = right - left + 1;
	int vet[tam];
	int a = left, b = middle+1;
	int k = 0;
	int moves = 0;
	// cerr << ">> " << left << " " << middle << " " << right << endl;

	for(; a <= middle && b <= right; ){
		if( v[a] < v[b] ){
			vet[k++] = v[a++];
			moves += k-(a-left);
		}
		else{
			vet[k++] = v[b++];
		 	moves += b-k-left;	
		 }
	}

	for(; a <= middle; a++, k++){
		vet[k] = v[a];
		moves += k-(a-left);
	}
	for(; b <= right; b++, k++){
		vet[k] = v[b];
		moves += b-k-left;
	}

	//printVet( vet, tam );
	k = 0;
	while( left <= right ){
		v[left] = vet[k];
		left++;
		k++;
	}
	return moves/2;
}

int mergeSort(int *v, int left, int right){
	// cerr << "left: " << left << " / right: " << right << endl; getchar();
	if( left >= right ) return 0;
	int middle = (left + right) / 2;
	int moves = mergeSort( v, left, middle);
	moves += mergeSort( v, middle+1, right);
	moves += merge(v, left, middle, right);
	/*cerr << "left: " << left << " / right: " << right << endl;
	printVet( v, N );
	cerr << "left: " << left << " / right: " << right << " => " << moves << endl; getchar();*/
	return moves;
}


int main(){
	int n;
	for(;;){
		cin >> n;
		if( n==0 ) break;
		N = n;
		int v[n];
		for(int i=0; i<n; i++)
			cin >> v[i];

		int moves = mergeSort( v, 0, n-1 );
		//printVet( v, n );
		if( moves % 2 == 0 ) cout << "Carlos" << endl;
		else cout << "Marcelo" << endl;
		//cout << moves << endl;
	}

	return 0;
}