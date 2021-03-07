#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n; cin >> n;
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int p; cin >> p;
    p--;
    G[p].push_back(i+1);
  }
  vector<ll> A(n); rep(i, n) cin >> A[i];
  auto bsearch = [&]() {
    auto test = [&](ll mid) {
      bool ok = true;
      auto dfs = [&](auto dfs, int cur) -> ll {
        if(!ok) return 0;
        ll cap = (G[cur].size() == 0 ? mid : 0);
        for(int ne: G[cur]) {
          cap += dfs(dfs, ne);
          if(!ok) return 0;
        }
        if(A[cur] > cap) ok = false;
        return cap - A[cur];
      };
      dfs(dfs, 0);
      return ok;
    };
    ll ok = longinf, ng = -1;
    while(ok - ng > 1) {
      ll mid = (ok + ng) / 2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch() << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
