#include <bits/stdc++.h>
//#define D(x) cout << #x " = " << (x) << endl
//#define endl '\n'

using namespace std;

vector< vector<int> > adj(5, vector<int>());

vector< map<int, bool> > vaux(5, map<int, bool>());

bool dfs(int v, vector<bool> visited){
	bool ans = true;
	visited[v] = true;
	for(int i : adj[v]){
		if (visited[i]) return false;
		ans &= dfs(i, visited);

        for (int j=0; j<5; j++)
            if (visited[j])
                vaux[j][i] = true;
	}
	return ans;
}

int main() {
    //ios_base::sync_with_stdio(false);cin.tie(NULL);

    char a, b, c;
    for(int i=0; i<5; i++){
        cin >> a >> b >> c;
    	if (b == '<'){
    		char temp = c;
    		c = a;
    		a = temp;
    	}
		adj[a - 'A'].push_back(c - 'A');
    }

    vector<bool> visited(5, false);

    bool flag = true;

    for(int i=0; i<5; i++){
        flag &= dfs(i, visited);
    }

    if (flag){
        vector< pair<int, char> > ans;
        ans.push_back(make_pair(vaux[0].size(), 'A'));
        ans.push_back(make_pair(vaux[1].size(), 'B'));
        ans.push_back(make_pair(vaux[2].size(), 'C'));
        ans.push_back(make_pair(vaux[3].size(), 'D'));
        ans.push_back(make_pair(vaux[4].size(), 'E'));
        sort(ans.begin(), ans.end());
        for(int i=0; i<5; i++)
            cout << ans[i].second;
        cout << endl;
    }
    else
        cout << "impossible\n";
}