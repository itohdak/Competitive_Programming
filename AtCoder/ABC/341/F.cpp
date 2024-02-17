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
  int n, m; cin >> n >> m;
  vector<vector<int>> G(n);
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<ll> W(n); rep(i, n) cin >> W[i];
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<int> id(n);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    if(W[i] == W[j]) return i < j;
    return W[i] < W[j];
  });
  vector<ll> dp(n);
  for(int cur: id) {
    vector<vector<ll>> dp2(2, vector<ll>(W[cur]));
    int f = 0;
    for(int ne: G[cur]) {
      dp2[1-f] = vector<ll>(W[cur]);
      rep(i, W[cur]) {
        chmax(dp2[1-f][i], dp2[f][i]);
        if(i+W[ne] < W[cur]) chmax(dp2[1-f][i+W[ne]], dp2[f][i]+dp[ne]);
      }
      f = 1-f;
    }
    dp[cur] = *max_element(all(dp2[f])) + 1;
  }
  ll ans = 0;
  rep(i, n) ans += dp[i] * A[i];
  cout << ans << endk;
  return 0;
}
