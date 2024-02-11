#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
  int n; cin >> n;
  vector<ll> X(n), Y(n), P(n);
  rep(i, n) {
    cin >> X[i] >> Y[i] >> P[i];
  }
  auto bsearch = [&]() {
    auto test = [&](ll m) -> bool {
      bool ok = false;
      rep(i, n) {
        vector<bool> vis(n);
        vis[i] = true;
        auto dfs = [&](auto dfs, int cur) -> void {
          vis[cur] = true;
          rep(ne, n) {
            if(P[cur] * m >= abs(X[cur]-X[ne]) + abs(Y[cur]-Y[ne])) {
              if(!vis[ne]) dfs(dfs, ne);
            }
          }
        };
        dfs(dfs, i);
        if(accumulate(all(vis), 0) == n) ok = true;
      }
      return ok;
    };
    ll ok = 5000000000, ng = 0;
    while(ok-ng>1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch() << endk;
  return 0;
}
