#include <bits/stdc++.h>

using namespace std;

double form2(int x){
	return ceil((-1+sqrt(8*x+1))/2.0);
}

int main(){
	int k; cin >> k;
    for(int casos=1; casos<=k; casos++){
    	int n; cin >> n;
    	vector<tuple<double,int,int,double>>stats;
    	for(int i=0; i<n; i++){
    		int hp, atk;
    		cin >> hp >> atk;
    		double aux = form2(hp);
    		stats.push_back(make_tuple(atk / aux,atk,hp,aux));
    	}
    	sort(stats.begin(), stats.end());
    	long long ans = 0, ataques = 0;
    	for(int i=n-1; i>=0; i--){
    		ataques += get<3>(stats[i]);
    		ans += ataques*get<1>(stats[i]);
    	}
    	printf("Case #%d: %lld\n", casos, ans);
    }
    return 0;
}