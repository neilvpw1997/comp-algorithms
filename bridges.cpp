#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<vector<int> > G;
vector<ll> disc;
vector<ll> low;
vector<ll> parent;
vector<bool> visited;
vector<pair<ll, ll> > edge_list;
ll t, n, m, x, y, tme;

void dfs(ll x){
	disc[x] = tme;
	low[x] = tme;
	tme++;
	visited[x] = true;
	for (auto y: G[x]){
		if (!visited[y]){
			parent[y] = x;
			dfs(y);
			low[x] = min(low[x], low[y]);
			if (low[y] > disc[x]){
				edge_list.push_back({x, y});	
			}
		}
		else {
			if (parent[x] != y){
				low[x] = min(low[x], disc[y]);
			}
		}
	}
}


int main(){
	cin>>n>>m;
	G.clear(); G.resize(n+1);
	edge_list.clear();
	disc.assign(n+1, 0);
	low.assign(n+1, INT_MAX);
	parent.assign(n+1, -1);
	visited.assign(n+1, false);
	for (ll i = 0; i < m; i++){
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1);
	for (auto x: edge_list){
		cout<<x.first<<" "<<x.second<<endl;
	}
	return 0;
}
