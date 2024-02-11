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
  vector<int> A(n);
  rep(i, n-1) cin >> A[i+1];
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<int> D(n);
  auto dfs = [&](auto dfs, int cur, int par, int dep) -> void {
    D[cur] = dep;
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur, dep+1);
    }
  };
  dfs(dfs, 0, -1, 0);
  auto bsearch = [&]() {
    auto test = [&](int t) {
      vector<pair<int, int>> V;
      rep(i, n) {
        if(A[i] > t) V.push_back({D[i], A[i]});
      }
      sort(all(V));
      int l = 0, r = 0;
      int cnt = 0;
      while(l < n) {
        r = l;
        while(r < n && V[l].first == V[r].first) {
          r++;
          cnt++;
        }
      }
    };
    int ok = 0, ng = inf;
    while(abs(ok-ng)>1) {
      int mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch() << endk;
  return 0;
}
