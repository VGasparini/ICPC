#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){

	int n, dx, dy, x, y;
	for(;;){
		cin >> n;
		if( n==0 ) break;
		cin >> dx >> dy;
		for(int i=0; i<n; i++){
			cin >> x >> y;
			if( x==dx || y==dy ) cout << "divisa" << endl;
			else{
				if( y > dy ) putchar('N');
				else putchar('S');
				if( x > dx ) putchar('E');
				else putchar('O');
				putchar('\n');
			}
		}

	}

	return 0;
}