/*
Prints the topological sort in lexicographically sorted order. Same output format as the implementation of topological_sort_dfs.cpp.
Priority_queue is used to sort the nodes with in_degree = 0 in ascending order
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<set<ll> > G;
vector<ll> in_degree;
ll n, m, x, y, visited;
queue<ll> topsort;

int main(){
	cin>>n>>m;
	G.resize(n+1);
	visited = 0;
	in_degree.assign(n+1,0);
	for(ll i = 0; i < m; i++){
		cin>>x>>y;
		if (x > n || y > n){
			continue;
		}
		G[x].insert(y);
		in_degree[y]++;
	}
	priority_queue<pair<ll, ll> > q;
	for (ll i = 1; i <= n; i++){
		if (in_degree[i] == 0){
			q.push({-i, i});
		}
	}
	while(!q.empty()){
		x = q.top().second;
		q.pop();
		topsort.push(x);
		visited++;
		for (auto y: G[x]){
			in_degree[y]--;
			if (in_degree[y] == 0){
				q.push({-y, y});
			}
		}
	}
	if (visited != n){
		cout<<"Cycle present\n";
		return 0;
	}
	while(!topsort.empty()){
		cout<<topsort.front()<<" ";
		topsort.pop();
	}
	return 0;
}
