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

vector<vector<int>> G;
vector<int> Tpl;

/* topological sort */
vector<bool> vis;
void dfs(int cur) {
  if(vis[cur]) return;
  vis[cur] = true;
  for(int ne: G[cur]) dfs(ne);
  Tpl.push_back(cur);
}
void solve() {
  int n; cin >> n;
  vector<string> S(n); rep(i, n) cin >> S[i];
  auto is_substring = [](string s, string t) {
    rep(i, t.size()-s.size()+1) {
      if(t.substr(i, s.size()) == s) return true;
    }
    return false;
  };
  G = vector<vector<int>>(n);
  rep(i, n) rep(j, n) {
    if(i != j && is_substring(S[i], S[j])) {
      G[i].push_back(j);
    }
  }
  // cout << G << endk;
  vis = vector<bool>(n);
  rep(i, n) dfs(i);
  reverse(all(Tpl));
  // cout << Tpl << endk;
  vector<string> ans(n);
  rep(i, n) ans[i] = S[Tpl[i]];
  // cout << ans << endk;
  rep(i, n) {
    rep(j, i) {
      if(!is_substring(ans[j], ans[i])) {
        cout << "NO" << endk;
        return;
      }
    }
  }
  cout << "YES" << endk;
  rep(i, n) cout << ans[i] << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
