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
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int m; cin >> m;
  vector<ll> P(m); rep(i, m) cin >> P[i];
  sort(all(P), greater<ll>());
  vector<ll> A;
  auto dfs = [&](auto dfs, int cur, int par) -> int {
    int cnt = 0;
    for(int ne: G[cur]) {
      if(ne != par) {
        int child = dfs(dfs, ne, cur);
        // cout << cur << ' ' << ne << ' ' << child << endk;
        A.push_back(1LL * child * (n - child));
        cnt += child;
      }
    }
    return cnt+1;
  };
  dfs(dfs, 0, -1);
  sort(all(A), greater<ll>());
  // cout << A << endk;
  assert((int)A.size() == n-1);
  if(n-1 >= m) {
    ll ans = 0;
    rep(i, n-1) {
      if(i < m) (ans += A[i] * P[i]) %= mod;
      else (ans += A[i]) %= mod;
    }
    cout << ans << endk;
  } else {
    ll ans = 0;
    reverse(all(P));
    reverse(all(A));
    ll mx = 0;
    rep(i, n-1) {
      chmax(mx, A[i]*P[i]);
      (ans += A[i] * P[i]) %= mod;
    }
    ll prod = 1;
    REP(i, n-1, m) {
      (prod *= P[i]) %= mod;
    }
    (prod += mod - 1) %= mod;
    mx %= mod;
    (ans += mx * prod) %= mod;
    cout << ans << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
