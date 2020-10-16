#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

struct vec{
  ll x;
  ll y;
};

bool comp(vec v1, vec v2){
  return v1.x * v1.x + v1.y * v1.y > v2.x * v2.x + v2.y * v2.y;
}

ll inner(vec v1, vec v2){
  return v1.x * v2.x + v1.y * v2.y;
}

int main(){
  int n;
  cin >> n;
  vector<vec> V(n);
  for(int i=0; i<n; i++){
    ll x, y;
    cin >> x >> y;
    vec v = {x, y};
    V[i] = v;
  }
  sort(V.begin(), V.end(), comp);
  ll p = 0;
  vector< vector<ll> > I(n, vector<ll>(n));
  vector<ll> I2(n, 0LL);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      I[i][j] = inner(V[i], V[j]);
      if(i != j)
	I2[i] += I[i][j];
    }
  }
  return 0;
}

