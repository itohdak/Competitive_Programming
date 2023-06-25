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
  vector<pair<int, int>> E(m);
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
    E[i] = {u, v};
  }
  vector<vector<vector<bool>>> dp(n*4+1, vector<vector<bool>>(n, vector<bool>(1<<n)));
  ll ans = 0;
  set<int> st;
  rep(i, 1<<n) {
    if(i == 0) continue;
    st.insert(i);
  }
  rep(i, n) {
    dp[0][i][1<<i] = true;
    st.erase(1<<i);
    ans += 1;
  }
  rep(i, n*4) {
    rep(j, n) rep(k, 1<<n) {
      dp[i+1][j][k] = dp[i][j][k];
    }
    rep(j, n) rep(k, 1<<n) {
      if(!dp[i][j][k]) continue;
      for(int ne: G[j]) {
        int b = k^(1<<ne);
        if(!dp[i+1][ne][b]) {
          if(st.count(b)) {
            st.erase(b);
            ans += i+2;
          }
          dp[i+1][ne][b] = true;
        }
      }
    }
    if(st.empty()) break;
  }
  cout << ans << endk;
  return 0;
}
