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
  vector<string> s(n);
  vector<vector<int>> G(n);
  vector<int> val(n, -1);
  rep(i, n) {
    cin >> s[i];
    if(s[i] == "IN") cin >> val[i];
    else if(s[i] == "NOT") {
      int j; cin >> j;
      j--;
      G[i].push_back(j);
    }
    else {
      int j, k; cin >> j >> k;
      j--; k--;
      G[i].push_back(j);
      G[i].push_back(k);
    }
  }
  auto dfs = [&](auto dfs, int cur) -> void {
    if(s[cur] == "IN") return;
    else if(s[cur] == "NOT") {
      dfs(dfs, G[cur][0]);
      val[cur] = !val[G[cur][0]];
    }
    else if(s[cur] == "XOR") {
      dfs(dfs, G[cur][0]);
      dfs(dfs, G[cur][1]);
      val[cur] = val[G[cur][0]]^val[G[cur][1]];
    }
    else if(s[cur] == "AND") {
      dfs(dfs, G[cur][0]);
      dfs(dfs, G[cur][1]);
      val[cur] = val[G[cur][0]]&val[G[cur][1]];
    }
    else if(s[cur] == "OR") {
      dfs(dfs, G[cur][0]);
      dfs(dfs, G[cur][1]);
      val[cur] = val[G[cur][0]]|val[G[cur][1]];
    }
    else assert(false);
  };
  dfs(dfs, 0);
  vector<bool> needChange(n);
  auto dfs2 = [&](auto dfs2, int cur, bool change) -> void {
    if(s[cur] == "IN") {
      needChange[cur] = change;
      return;
    }
    else if(s[cur] == "NOT") {
      dfs2(dfs2, G[cur][0], change);
    }
    else if(s[cur] == "XOR") {
      dfs2(dfs2, G[cur][0], change);
      dfs2(dfs2, G[cur][1], change);
    }
    else if(s[cur] == "AND") {
      if(val[cur] == 1) {
        dfs2(dfs2, G[cur][0], change);
        dfs2(dfs2, G[cur][1], change);
      } else if(val[G[cur][0]]) {
        dfs2(dfs2, G[cur][0], false);
        dfs2(dfs2, G[cur][1], change);
      } else if(val[G[cur][1]]) {
        dfs2(dfs2, G[cur][0], change);
        dfs2(dfs2, G[cur][1], false);
      } else {
        dfs2(dfs2, G[cur][0], false);
        dfs2(dfs2, G[cur][1], false);
      }
    }
    else if(s[cur] == "OR") {
      if(val[G[cur][0]] && val[G[cur][1]]) {
        dfs2(dfs2, G[cur][0], false);
        dfs2(dfs2, G[cur][1], false);
      } else if(val[G[cur][0]]) {
        dfs2(dfs2, G[cur][0], change);
        dfs2(dfs2, G[cur][1], false);
      } else if(val[G[cur][1]]) {
        dfs2(dfs2, G[cur][0], false);
        dfs2(dfs2, G[cur][1], change);
      } else {
        dfs2(dfs2, G[cur][0], change);
        dfs2(dfs2, G[cur][1], change);
      }
    }
    else assert(false);
  };
  dfs2(dfs2, 0, true);
  rep(i, n) if(s[i] == "IN") cout << (val[0]^needChange[i]);
  cout << endk;
  return 0;
}
