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
  vector<int> G(n);
  vector<int> cnt(1<<n);
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u] |= 1<<v;
    G[v] |= 1<<u;
    // rep(j, 1<<n) {
    //   if(((j>>u)&1)&&((j>>v)&1)) cnt[j]++;
    // }
  }
  rep(i, 1<<n) {
    rep(j, n) {
      if((i>>j)&1) continue;
      cnt[i|(1<<j)] = cnt[i] + __builtin_popcount(i&G[j]);
    }
  }
  vector<int> dp(1<<n, inf);
  rep(i, 1<<n) {
    int pop = __builtin_popcount(i);
    // cout << i << ' ' << cnt[i] << ' ' << pop << endk;
    if(cnt[i] == pop*(pop-1)/2) {
      dp[i] = 0;
    }
  }
  // rep(i, 1<<n) cout << i << ' ' << cnt[i] << ' ' << dp[i] << endk;
  vector<int> par(1<<n, -1);
  vector<int> v(1<<n, -1);
  rep(i, 1<<n) {
    rep(j, n) {
      if((i>>j)&1) {
        if(dp[i|G[j]] > dp[i]+1) {
          par[i|G[j]] = i;
          v[i|G[j]] = j;
          chmin(dp[i|G[j]], dp[i]+1);
        }
      }
    }
  }
  cout << dp[(1<<n)-1] << endk;
  // cout << dp << endk;
  // cout << par << endk;
  int tmp = (1<<n)-1;
  while(par[tmp] != -1) {
    cout << v[tmp]+1 << ' ';
    tmp = par[tmp];
  }
  cout << endk;
  return 0;
}
