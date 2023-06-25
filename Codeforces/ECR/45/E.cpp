#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int n, m, k;
  cin >> n >> m >> k;
  vector<ll> cost(n, 1e10);
  vector<bool> blocked(n, false);
  for(int i=0; i<m; i++){
    int in;
    cin >> in;
    blocked[in] = true;
  }
  vector<int> lamp(k);
  for(int i=0; i<k; i++)
    cin >> lamp[i];
  for(int i=0; i<n; i++){
    for(int j=0; j<k; j++){
      cost[i+j] = min(cost[i+j], cost[i]+lamp[j]);
    }
  }

  return 0;
}

