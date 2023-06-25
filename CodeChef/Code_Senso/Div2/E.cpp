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
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<vector<int>> dp(n, vector<int>(2, -inf));
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    if(par != -1 && G[cur].size() == 1) { // leaf
      dp[cur][A[cur]>0] = (abs(A[cur])==2);
    }
    vector<vector<int>> tmp(2);
    for(int ne: G[cur]) {
      if(ne != par) {
        dfs(dfs, ne, cur);
        rep(j, 2) {
          tmp[j].push_back(dp[ne][j]);
        }
      }
    }
    
  };
  dfs(dfs, 0, -1);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
