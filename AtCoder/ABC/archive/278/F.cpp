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
  vector<string> S(n); rep(i, n) cin >> S[i];

  int m = (1<<n)*n;
  vector<vector<int>> G(m);
  vector<vector<int>> par(m);
  rep(k, n) {
    par[0].push_back((1<<k)*n+k);
    G[(1<<k)*n+k].push_back(0);
  }
  rep(i, 1<<n) {
    rep(j, n) {
      if(!((i>>j)&1)) continue;
      rep(k, n) {
        if((i>>k)&1) continue;
        if(S[j].back() == S[k].front()) {
          G[(i^(1<<k))*n+k].push_back(i*n+j);
          par[i*n+j].push_back((i^(1<<k))*n+k);
          // cout << bitset<6>((i^(1<<k))) << ", " << k << " -> " << bitset<6>(i) << ", " << j << endk;
        }
      }
    }
  }

  vector<int> tpl;
  vector<bool> vis(m);
  auto dfs = [&](auto dfs, int cur) {
    if(vis[cur]) return;
    vis[cur] = true;
    for(int ne: G[cur]) dfs(dfs, ne);
    tpl.push_back(cur);
  };
  rep(i, m) dfs(dfs, i);
  reverse(all(tpl));

  vector<bool> win(m);
  rep(i, m) if(par[i].empty()) win[i] = false;
  for(int cur: tpl) {
    for(int ne: G[cur]) {
      if(!win[cur]) win[ne] = true;
    }
  }

  cout << (win[0] ? "First" : "Second") << endk;

  return 0;
}
