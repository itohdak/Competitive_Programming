#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  dsu uf(n);
  map<int, int> mpE, mpV;
  rep(i, n) {
    mpE[i] = 0;
    mpV[i] = 1;
  }
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    if(!uf.same(u, v)) {
      int e1 = mpE[uf.leader(u)];
      int e2 = mpE[uf.leader(v)];
      int v1 = mpV[uf.leader(u)];
      int v2 = mpV[uf.leader(v)];
      mpE.erase(uf.leader(u));
      mpE.erase(uf.leader(v));
      mpV.erase(uf.leader(u));
      mpV.erase(uf.leader(v));
      uf.merge(u, v);
      mpE[uf.leader(u)] = e1 + e2 + 1;
      mpV[uf.leader(u)] = v1 + v2;
    } else {
      mpE[uf.leader(u)]++;
    }
  }
  bool ok = true;
  for(auto [k, v]: mpE) {
    if(v != mpV[k]) ok = false;
  }
  cout << (ok ? "Yes" : "No") << endk;
  return 0;
}
