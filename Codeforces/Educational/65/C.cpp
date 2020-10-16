#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

#define MAX_N 500005

int par[MAX_N];
int depth[MAX_N];
int nGroup[MAX_N];

void init(int n){
  for(int i=0; i<n; i++){
    par[i] = i;
    depth[i] = 0;
    nGroup[i] = 1;
  }
}

int root(int x){
  if(par[x] == x){
    return x;
  } else {
    return par[x] = root(par[x]);
  }
}

bool same(int x, int y){
  return root(x) == root(y);
}

void unite(int x, int y){
  x = root(x);
  y = root(y);
  if(x == y) return;

  if(depth[x] < depth[y]){
    par[x] = y;
    nGroup[y] += nGroup[x];
  } else {
    par[y] = x;
    nGroup[x] += nGroup[y];
    if(depth[x] == depth[y])
      depth[x]++;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  init(n);
  for(int i=0; i<m; i++) {
    int k;
    cin >> k;
    int prev = -1;
    for(int j=0; j<k; j++) {
      int in;
      cin >> in;
      in--;
      if(j != 0) unite(prev, in);
      prev = in;
    }
  }
  for(int i=0; i<n; i++)
    cout << nGroup[root(i)] << ' ';
  cout << endl;
  return 0;
}

