/*
/*Solution for russian dolls problem
/*The given solution is when l1 <= l2 and w1 <= w2
/*For sorting the second paremter we use ascending order and find the largest decreasing sequence
/*For l1 < l2 and w1 < w2 --> sort the second parameter in descending order and find the largest non increasing sequence
/*For l1 <= l2 and w1 < w2 sort the second paremeter in ascending order and find the largest non decreasing sequence
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
ll t, m, h, w;
vector<pair<int, int> > D;
vector<int> A;
vector<int> dp;
 
int last_bigger(int x, int start, int end){
	int b = start;
	for (int i = end - start; i >= 1; i/=2){
		while(b + i <= end && dp[b+i] >= x){
			b += i;
		}
	}
	return b;
}
 
bool ordering(pair<int, int> a, pair<int, int> b){
	if (a.first < b.first){
		return true;
	}
	else if (a.first == b.first){
		return a.second > b.second;
	}
	else {
		return false;
	}
}
 
int main(){
	cin>>t;
	while(t--){
		cin>>m;
		D.clear();
		D.resize(m);
		dp.clear();
		dp.assign(m, -1);
		A.clear();
		for (int i = 0; i < m;  i++){
			cin>>w>>h;
			D[i] = {w, h};
		}
		sort(D.begin(), D.end(), ordering);	
		for (auto x: D){
			A.push_back(x.second);
		}
		int len = 1;
		for (int i = 0; i < m; i++){
			if (A[i] > dp[0]){
				dp[0] = A[i];
			}
			else if (A[i] <= dp[len-1]){
				dp[len] = A[i];
				len++; 
			}
			else {
				dp[last_bigger(A[i], 0, len-1) + 1] = A[i];
			}
		}
		cout<<len<<endl;
	}
	return 0;
}
