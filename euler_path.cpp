#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<vector<ll> > G;
vector<int> edge_count;
stack<int> curr_path;
vector<int> circuit;
int n, m, x, y, curr_vertex, nxt;

int main(){
	int n, m;
	cin>>n>>m;
	G.resize(n+1);
	edge_count.assign(n+1, 0);
	for(int i = 0; i < m; i++){
		cin>>x>>y;
		G[x].push_back(y);
		edge_count[x]++;
	}
	curr_path.push(0);
	while(!curr_path.empty()){
		curr_vertex = curr_path.top();
		if (edge_count[curr_vertex] != 0){
			nxt = G[curr_vertex].back();
			G[curr_vertex].pop_back();
			curr_path.push(nxt);
			edge_count[curr_vertex]--;
		}
		else {
			circuit.push_back(curr_vertex);
			curr_path.pop();
		}
	}
	while(!circuit.empty()){
		cout<<circuit.back()<<"->";
		circuit.pop_back();
	}
	return 0;
}
