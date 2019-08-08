#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int n,s,j,d;

    while(cin >> n >> s >> j >> d ){

	    string partida; cin >> partida;

	    int da=0,ja=0,sa=0,db=0,jb=0,sb=0;

	    for(int i=0; i<partida.length(); i++){
	    	auto letra = partida[i];
	    	if (letra == 'A'){
	    		da++;
	    		if((da-db) >= d and da>=j){
	    			ja++;
	    			da=0;
	    			db=0;
	    			if(ja == s){
	    				break;
	    			}
	    		}
	    	}
	    	else{
	    		db++;
	    		if((db-da) >= d and db>=j){
	    			jb++;
	    			da=0;
	    			db=0;
	    			if(jb == s){
	    				break;
	    			}
	    		}
	    	}
	    	// cout << da << " " << ja << " " << sa << " | " << db << " " << jb << " " << sb << endl;
	    }
	    cout << ja << " " << jb << endl;
	}
}