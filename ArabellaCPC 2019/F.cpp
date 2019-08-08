#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    double ans = (double)(2*n +1)*(n+1)/6 - (double)(n+1)/2;
    printf("%.10lf\n", ans);
}