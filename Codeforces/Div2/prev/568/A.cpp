#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  vector<ll> v(3);
  ll d;
  cin >> v[0] >> v[1] >> v[2] >> d;
  sort(v.begin(), v.end());
  cout << max(d-(v[1]-v[2]), 0LL) + max(d-(v[1]-v[2]), 0LL) << endl;
  return 0;
}

