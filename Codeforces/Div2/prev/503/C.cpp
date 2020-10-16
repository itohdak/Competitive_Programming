#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

bool comp(vector<ll> v1, vector<ll> v2){
  return v1.size() > v2.size();
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> P(n);
  vector<ll> C(n);
  vector< vector<ll> > C2(n-1, vector<ll>());
  int sum = 0;
  for(int i=0; i<n; i++){
    cin >> P[i] >> C[i];
    if(P[i] == 1)
      sum++;
    else
      C2[P[i]-2].push_back(C[i]);
  }
  for(int i=0; i<n-1; i++)
    sort(C2[i].begin(), C2[i].end(), greater<ll>());

  sort(C2.begin(), C2.end(), comp);

  ll ans = 0;
  int target = 0;
  vector<int> num(n-1, 0);
  int max = C2[0].size();
  while(max > sum){
    ans += C2[target][num[target]];
    num[target]++;
    sum++;
  }

  return 0;
}

