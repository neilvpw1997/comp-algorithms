/*
Prints the topological sort in lexicograhically sorted order using dfs. Cycle detection is done using inStack. inStack contains the 
nodes which are in the current dfs stack. If any of them is visited then the graph contains a cycle
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<set<ll, greater<ll> > > G;
vector<bool> visited;
vector<bool> inStack;
stack<ll> topsort;
ll n, m, x, y;
bool cycle_present;


void dfs(ll x){
	visited[x] = true;
	inStack[x] = true;
	for (auto y: G[x]){
		if (visited[y] && inStack[y]){
			cycle_present = true;
		}
		else if (!visited[y]){
			dfs(y);
		}
	}
	inStack[x] = false;
	topsort.push(x);
}

int main(){
	cin>>n>>m;
	G.resize(n+1);
	visited.assign(n+1, false);
	inStack.assign(n+1, false);
	cycle_present = false;
	for(ll i = 0; i < m; i++){
		cin>>x>>y;
		if (x > n || y > n){
			continue;
		}
		G[x].insert(y);
	}
	for (ll i = n; i >= 1; i--){
		if (!visited[i]){
			dfs(i);
		}
	}
	if (cycle_present){
		cout<<"Cycle present\n";
		return 0;
	}
	while(!topsort.empty()){
		x = topsort.top();
		topsort.pop();
		cout<<x<<" ";
	}
	return 0;
}
