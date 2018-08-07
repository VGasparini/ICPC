#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > create_adj(vector<vector<int> > adj, char type, int y, int x, int z){
	if (type == 'F'){
		adj[y-1][x-1] = 1;
		adj[y-1][z-1] = 1;
	}else{
		adj[z-1][x-1] = 1;
		adj[z-1][y-1] = 1;
	}

	return adj;
}

int main(){

	int t;
	cin >> t;

	for (int i = 0; i < t; i++){
		int linhas, FJ;
		cin >> linhas >> FJ;
		vector<vector<int> > adj;

		for (int j = 0; j < linhas; j++){
			vector<int> row(linhas);
			for (int k = 0; k < linhas; k++){
				row[j] = 0;
			}
			adj.push_back(row);
		}
		for (int j = 0; j < FJ; j++){
			int y, x, z;
			char type;
			cin >> type >> y >> x >> z;
			adj = create_adj(adj, type, y, x, z);
		}

		for (int j = 0; j < linhas; j++){
			for (int k = 0; k < linhas; k++){
				cout << adj[j][k] << " ";
			}
			cout << endl;
		}

	}

	return 0;
}