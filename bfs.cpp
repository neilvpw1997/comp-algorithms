#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<ll> > G;
vector<bool> visited;
ll n, m;

void bfs(ll x){
	queue<ll> Q;
	Q.push(x);
	visited[x] = true;
	while(!Q.empty()){
		ll a = Q.front();
		Q.pop();
		for (auto b: G[a]){
			if (!visited[b]){
				Q.push(b);
				visited[b] = true;
			}
		}
	}
}

int main(){
	cin>>n>>m;
	G.resize(n+1);
	visited.resize(n+1,false);
	ll a, b;
	for(ll i = 0; i < m; i++){
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (ll i = 0; i < n; i++){
		if (!visited[i]){
			bfs(i);
		}
	}
	return 0;
}
