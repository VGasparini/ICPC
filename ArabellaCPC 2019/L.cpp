#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string s; cin >> s;
    int rec[123];
    memset(rec,0,sizeof(rec));
    for(int i=0; i<s.length(); i++){
    	int letra = (int)s[i];
    	rec[letra]++;
    }
    for(int i=0; i<122; i++){
    	int qt = rec[i]; 
    	rec[i+1] += qt/2;
    	rec[i] %= 2;
    }
    
    for(int i=122; i>0; i--){
    	for(int j=0; j<rec[i]; j++)
    		cout << (char) i;
    } cout << endl;
}