/*compare function is used to order the edges. This implementation sorts the edges in increasing order by weight. When weights are same
  edges are sorted in increasing order on their u + v + w values */

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<int> link;
vector<int> size;
vector<tuple<int, int, int> > E;
int n, m;

int find(int a){
	while(link[a] != a){
		a = link[a];
	}
	return a;
}

bool same(int a, int b){
	return find(a) == find(b);
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	if (size[a] < size[b]){
		swap(a, b);
	}
	size[a] += size[b];
	link[b] = a;
}


bool compare(tuple<int, int, int> A, tuple<int, int, int> B){
	int ua, va, wa, ub, vb, wb;
	tie(ua, va, wa) = A;
	tie(ub, vb, wb) = B;
	if (wa == wb){
		return ua + va + wa < ub + vb + wb;
	}
	else {
		return wa < wb;
	}
}


int main(){
	cin>>n>>m;
	link.resize(n+1, 0);
	size.resize(n+1, 1);
	for (int i = 1; i <= n; i++){
		link[i] = i;
	}
	int a, b, w;
	for (int i = 0; i < m; i++){
		cin>>a>>b>>w;
		E.push_back(make_tuple(a, b, w));
	}
	sort(E.begin(), E.end(), compare);
	int cost = 0;
	for (int i = 0; i < m; i++){
		int u, v, w;
		tie(u, v, w) = E[i];
		if (!same(u, v)){
			unite(u, v);
			cost += w;
		}
	}
	cout<<cost;
	return 0;
}

