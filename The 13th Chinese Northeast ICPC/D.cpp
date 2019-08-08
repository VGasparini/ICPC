/* Codigo copiado, minha solucao estoura memoria */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 9;
struct UnionfindSet : vector<int>
{
	UnionfindSet(int n) : vector<int>(n)
	{
		for (int i = 0; i < n; ++i)
			at(i) = i;
	}
	int merge(int u, int w)
	{
		if (w = ask(w), u = ask(u), w != u)
			return at(w) = u, 1;
		return 0;
	}
	int ask(int u) { return at(u) != u ? at(u) = ask(at(u)) : u; }
};
struct Edge
{
	int u, v;
	ll w;
	bool operator<(const Edge &ed) const { return w < ed.w; }
} e[N];
int t, n, m;
int main()
{
	for (scanf("%d", &t); t--;)
	{
		scanf("%d", &n);
		for (int i = 0, u, v, w; i + 1 < n; ++i)
		{
			scanf("%d%d%d", &u, &v, &w);
			e[i] = {u - 1, v - 1, w};
		}
		sort(e, e + n - 1);
		vector<vector<int>> v(n);
		for (int i = 0; i + 1 < n; ++i)
			v[e[i].u].push_back(i), v[e[i].v].push_back(i);
		ll ans = 0;
		vector<int> flag(n, 0);
		UnionfindSet ufs(n - 1);
		for (int i = 0; i + 1 < n; ++i)
			for (auto u : {e[i].u, e[i].v})
				if (!flag[u])
				{
					flag[u] = 1;
					for (auto it : v[u])
						if (ufs.merge(i, it))
							ans += e[i].w + e[it].w;
				}
		cout << ans << '\n';
	}
}

/*
#include<bits/stdc++.h>

#define D(x)cout<<#x"="<<(x)<<endl
#define endl '\n'
#define ii pair<int,int>
typedef int ll ;

using namespace std;

class UnionFind {
	private : vector<int>parent, rank;
	public :
		UnionFind (int N) {
			rank.assign(N+1, 0);
			parent.assign(N+1,0);
			for(int i=0;i<=N;i++)parent[i]=i;
		}

		int find (int i) {
			while (i != parent[i]) i=parent[i];
		return i;
		}

		bool isSameSet(int i,int j){
		return find(i) == find(j);
		}

		void unionSet(int i,int j){
			if(isSameSet(i,j)) return;
			int x=find(i) , y=find(j);
			if(rank[x]>rank[y]) parent[y]=x;
			else{
				parent[x]=y;
				if(rank[x]==rank[y]) rank[y]++;
			}
		}
};


int N,M;
vector<pair<ll, ii>> edgeList; // ( weight , two vertices ) of the edge

ll kruskal () {
	ll cost = 0;
	UnionFind UF(N) ;
	pair <int , ii> edge ;
	sort (edgeList.begin(), edgeList.end());
	for(int i=0;i<M;i++){
		edge = edgeList[i];
		if(!UF.isSameSet(edge.second.first, edge.second.second)) {
		cost += edge.first;
		UF.unionSet(edge.second.first,edge.second.second);
		}
	}
	return cost;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int cases; cin >> cases;
	for(int caso=0; caso<cases; caso++){

		//           id, para, peso
		cin >> N;
		int orig = N-1;
		vector<tuple<ll, ll>> adj[N];


		int n_vertice = 0;
		int cont = 0;

		//     de, para, peso
		

		for(int i=0; i<N-1; i++){
			int de,para;ll peso;
			cin >> de >> para >> peso;
			de--;para--;

			for(auto j : adj[de]){
				//    peso, de, para
				pair<ll, ii> novaresta (peso + get<1>(j), make_pair(n_vertice, get<0>(j)));
				edgeList.push_back(novaresta);
				cont++;

			}

			adj[de].push_back(make_tuple(n_vertice, peso));
			adj[para].push_back(make_tuple(n_vertice, peso));
			n_vertice++;
		}

		N = n_vertice;
		M = cont;

		cout << kruskal() << endl;
		edgeList.erase(edgeList.begin(), edgeList.end());
	}
}

 */