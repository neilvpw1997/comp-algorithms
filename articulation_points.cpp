/* low[i] stores the node with the minimum discovery time that can be reached from the subtree rooted at i. If in the dfs tree any child
of a node u, say node v, has low[v] >= disc[u], this implies that the subtree rooted at v has no back edge and on  removing node u the 
subtree rooted at v will become disconnected. When we are finding the value of low[v] if there is an edge vw which leads to a visited
node w, it can be a back edge or a forward edge in the dfs tree, which can cause a change in low[v] as seen in line no 40*/


#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<vector<ll> > G;
vector<ll> disc;
vector<ll> low;
vector<ll> parent;
vector<bool> visited;
vector<bool> AP;
ll n, m, x, y, tim;

void dfs(ll x){
	disc[x] = tim;
	low[x] = tim;
	tim++;
	visited[x] = true;
	ll child = 0;
	for (auto y: G[x]){
		if (!visited[y]){
			child++;
			parent[y] = x;
			dfs(y);
			low[x] = min(low[x], low[y]);
			if (parent[x] == -1 && child > 1){
				AP[x] = true;
			}
			else if (parent[x] != -1 && low[y] >= disc[x]){
				AP[x] = true;
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
	G.resize(n);
	disc.assign(n, -1);
	low.assign(n, INT_MAX);
	visited.assign(n,  false);
	AP.assign(n, false);
	parent.assign(n+1, -1);
	tim = 0;
	for (ll i = 0; i < m; i++){
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(0);
	ll num_ap = 0;
	for (ll i = 0; i < n; i++){
		if (AP[i]){
			num_ap++;
		}
	}
	cout<<"number of articulation points is "<<num_ap<<endl;
	return 0;
}
