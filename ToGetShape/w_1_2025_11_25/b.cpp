#include<bits/stdc++.h>
using namespace std;
 
char museum[1003][1003]={};
int vis[1003][1003]={};
int memo[100005]={};
int n,m,k,ans;

bool bound(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}
void dfs(int x,int y,int i){
	if(!bound(x,y)) return;
	if(museum[x][y]=='*') {ans++; return;}
	if(vis[x][y]) return;

	vis[x][y]=i;
	dfs(x+1,y,i);
	dfs(x-1,y,i);
	dfs(x,y+1,i);
	dfs(x,y-1,i);
	return;
}

int main(){
    int x,y;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin >> museum[i][j];
	}
	for(int i=1;i<=k;i++){
		cin >> x >> y;
		ans=0;
		if(!vis[x][y]){
		    dfs(x,y,i);
		}else{
		    ans=memo[vis[x][y]];
		}
		memo[i]=ans;
		cout << ans << endl;
	}
	return 0;
}
