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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n, m; cin >> n >> m;
  vector<int> A(m), B(m);
  vector<ll> D(m);
  vector<vector<pair<int, ll>>> G(n);
  rep(i, m) {
    cin >> A[i] >> B[i] >> D[i];
    A[i]--; B[i]--;
    G[A[i]].push_back({B[i], D[i]});
    G[B[i]].push_back({A[i], -D[i]});
  }
  vector<bool> vis(n);
  vector<ll> P(n);
  bool ok = true;
  auto dfs = [&](auto dfs, int cur, ll tmp) -> void {
    if(vis[cur]) {
      ok &= (P[cur] == tmp);
      return;
    }
    vis[cur] = true;
    P[cur] = tmp;
    for(auto [ne, d]: G[cur]) {
      dfs(dfs, ne, P[cur]+d);
    }
  };
  rep(i, n) {
    if(vis[i]) continue;
    dfs(dfs, i, 0);
  }
  cout << (ok ? "YES" : "NO") << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}