#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll gcd(ll a, ll b){
	if (b == 0){
		return a;
	}
	else return gcd(b, a%b);
}

void convert_irreducible(ll& a, ll& b){
	ll g = gcd(a, b);
	a/=g;
	b/=g;
}

int main(){
	ll a = 4, b = 2;
	convert_irreducible(a, b);
	cout<<a<<"/"<<b<<endl;
	return 0;
}
