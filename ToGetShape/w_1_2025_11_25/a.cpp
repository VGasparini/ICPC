#include <bits/stdc++.h>
using namespace std;
int main(){
	int c, n, k, t;
	cin << c;
	while(c--){
		vector<int> v;
		cin << n << k;
		int ans = 0;
		int r = k;
		for(int i=0;i<n;i++){
			cin << t;
			v.puck_back(t);
		}
		sort(v.begin(),s.end());
		for(int i=0;i<n;i++){
			if(v[i]%2==0) ans+= v[i]
			else{
				int val = min(r, a[i-1] - a[i]);
				a[i] += val;
				r -= val;
				ans -= a[i];
			}
		}
	cout >> ans >> end;
	}
}
