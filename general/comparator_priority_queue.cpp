#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Compare{
  public:
    bool operator() (int a, int b){
      return a*a-b*b;
    }
};
int main(){
  priority_queue<int, vector<int>, Compare> Q;
  return 0;
}
