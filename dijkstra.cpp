/*Priority Queue implementation
Calculates shortest path from start to all nodes and stores them in D vector. Unreachable nodes have a distance of -1*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<vector<pair<ll, ll> > > G;
vector<bool> processed;
vector<ll> D;
ll n, m;

void djikstra(ll x){
	D[x] = 0;
	priority_queue<pair<ll, ll> > Q;
	Q.push({0, x});
	while(!Q.empty()){
		ll a = Q.top().second;
		Q.pop();
		if (!processed[a]){
			processed[a] = true;
			for (auto z: G[a]){
				ll b = z.first, w = z.second;
				if (D[a] == INT_MAX){
					continue;
				}
				if (D[a] + w < D[b]){
					D[b] = D[a] + w;
					Q.push({-D[b], b});
				}
			}
		}
	}
}

int main(){
	cin>>n>>m;
	G.clear();
	G.resize(n+1);
	processed.assign(n+1, false);
	D.assign(n+1, INT_MAX);
	ll a, b, w;
	for (ll i = 0; i < m; i++){
		cin>>a>>b>>w;
		G[a].push_back({b, w});
		G[b].push_back({a, w});
	}
	ll start;
	cin>>start;
	djikstra(start);
	for (ll i = 1; i <= n; i++){
		if (i == start){
			continue;
		}
		if (D[i] == INT_MAX){
			cout<<-1<<" ";
		}
		else cout<<D[i]<<" ";
	}
	cout<<endl;	
}
