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
  int n, m, q; cin >> n >> m >> q;
  vector<vector<int>> G(n);
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<int> X(q);
  rep(i, q) {
    cin >> X[i];
    X[i]--;
  }
  int b = sqrt(n);
  vector<vector<int>> big(n);
  rep(i, n) {
    if(G[i].size() > b) {
      for(int ne: G[i]) {
        big[ne].push_back(i);
      }
    }
  }
  vector<int> col1(n);
  iota(all(col1), 0);
  vector<int> col2(n);
  iota(all(col2), 0);
  vector<int> t1(n, -1);
  vector<int> t2(n, -1);
  auto collect = [&](int x) {
    for(int ne: big[x]) {
      if(t1[x] < t2[ne]) {
        t1[x] = t2[ne];
        col1[x] = col2[ne];
      }
    }
  };
  rep(i, q) {
    int x = X[i];
    collect(x);
    if(G[x].size() <= b) {
      t1[x] = i;
      for(int ne: G[x]) {
        col1[ne] = col1[x];
        t1[ne] = i;
      }
    } else {
      col2[x] = col1[x];
      t2[x] = i;
    }
    // cout << col << endk;
  }
  rep(i, n) collect(i);
  rep(i, n) cout << col1[i]+1 << ' ';
  cout << endk;
  return 0;
}
