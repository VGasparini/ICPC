#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
    long n,m;
    scanf("%ld %ld",&n, &m);
    long a[n+5];
    long b[m+5];
    for(long i=0; i<n; i++){
        scanf("%ld",&a[i]);
    }
    for(long i=0; i<m; i++){
        scanf("%ld",&b[i]);
    }
    long gcdzao;
    if (m == 1){
        gcdzao = b[0];
    } else {
        gcdzao = __gcd(b[0],b[1]);
        for(long i=2; i<m; i++){
            gcdzao = __gcd(gcdzao,b[i]);
        }
    }

    for(long i=1; i<n; i++){
        if(abs(a[0]-a[i])%gcdzao){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}