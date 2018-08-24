#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<ll> > G;
vector<bool> visited;
ll n, m;

void dfs(ll x){
	visited[x] = true;
	for(auto y: G[x]){
		if (!visited[y]){
			dfs(y);
		}
	}
}

int main(){
	cin>>n>>m;
	G.clear();
	G.resize(n+1);
	ll a, b;
	for (ll i = 0; i < m; i++){
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	visited.assign(n+1, false);
	for(ll i = 1; i <= n; i++){
		if (!visited[i]){
			dfs(i);
		}
	}
	return 0;
}
