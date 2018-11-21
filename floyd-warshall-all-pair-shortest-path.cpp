#include<bits/stdc++.h>
#define ll long long int
#define MX 1e18
using namespace std;

ll n, m, x, y, w;
vector<vector<ll> > G;
vector<vector<ll> > D;

int main(){
	cin>>n>>m;
	G.assign(n+1, vector<ll>(n+1, -1));
	D.assign(n+1, vector<ll>(n+1, MX));
	for (ll i = 0; i < m; i++){
		cin>>x>>y>>w;
		G[x][y] = w;
		D[x][y] = w;
	}
	for (ll i = 1; i <= n; i++){
		D[i][i] = 0;
	}
	for (ll k = 1; k <= n; k++){
		for (ll i = 1; i <= n; i++){
			for (ll j = 1; j <= n; j++){
				if (D[i][k] != MX && D[k][j] != MX){
					D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
				}
			}
		}
	}
	return 0;
}
