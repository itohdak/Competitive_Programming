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
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int q; cin >> q;
  vector<int> V(q), D(q), C(q);
  vector<vector<int>> dp(n, vector<int>(11, -1));
  rep(i, q) {
    cin >> V[i] >> D[i] >> C[i];
    V[i]--;
    dp[V[i]][D[i]] = i;
  }
  for(int level=10; level>=1; level--) {
    rep(i, n) {
      chmax(dp[i][level-1], dp[i][level]);
      for(int ne: G[i]) chmax(dp[ne][level-1], dp[i][level]);
    }
  }
  rep(i, n) {
    cout << (dp[i][0]==-1 ? 0 : C[dp[i][0]]) << endk;
  }
  return 0;
}
