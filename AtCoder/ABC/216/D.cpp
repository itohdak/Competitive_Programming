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

vector<vector<int>> G;
vector<int> Tpl;
vector<bool> vis;
vector<bool> seen, finished;
bool dfs2(int cur, int par) {
  if(seen[cur] && !finished[cur]) return true;
  if(seen[cur] || finished[cur]) return false;
  seen[cur] = true;
  bool ret = false;
  for(int ne: G[cur]) {
    // if(ne == par) continue;
    ret |= dfs2(ne, cur);
  }
  finished[cur] = true;
  Tpl.push_back(cur);
  return ret;
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  G.assign(n, vector<int>());
  vis.assign(n, false);
  seen.assign(n, false);
  finished.assign(n, false);
  set<pair<int, int>> st;
  rep(i, m) {
    int k; cin >> k;
    int prev = -1;
    rep(j, k) {
      int a; cin >> a;
      a--;
      if(j && !st.count({prev, a})) G[prev].push_back(a);
      st.insert({prev, a});
      prev = a;
    }
  }
  // cout << G << endk;
  bool ret = false;
  rep(i, n) ret |= dfs2(i, -1);
  cout << (ret ? "No" : "Yes") << endk;
  return 0;
}
