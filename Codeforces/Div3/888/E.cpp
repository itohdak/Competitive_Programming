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
  int n, k; cin >> n >> k;
  vector<ll> C(n);
  rep(i, n) cin >> C[i];
  vector<int> P(k);
  rep(i, k) {
    cin >> P[i];
    P[i]--;
  }
  vector<vector<int>> E(n);
  rep(i, n) {
    int m; cin >> m;
    E[i] = vector<int>(m);
    rep(j, m) {
      cin >> E[i][j];
      E[i][j]--;
    }
  }
  vector<bool> done(n);
  vector<ll> cost(n, longinf);
  rep(i, k) cost[P[i]] = 0;
  auto dfs = [&](auto dfs, int cur) -> ll {
    if(done[cur]) {
      return cost[cur];
    }
    chmin(cost[cur], C[cur]);
    if(E[cur].size()) {
      ll tmp = 0;
      for(int ne: E[cur]) {
	tmp += dfs(dfs, ne);
      }
      chmin(cost[cur], tmp);
    }
    done[cur] = true;
    return cost[cur];
  };
  rep(i, n) dfs(dfs, i);
  rep(i, n) cout << cost[i] << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
