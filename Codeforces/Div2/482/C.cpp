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
  int n, x, y; cin >> n >> x >> y;
  x--; y--;
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> nChild(n, 1);
  vector<int> P(n);
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    P[cur] = par;
    for(int ne: G[cur]) {
      if(ne != par) {
        dfs(dfs, ne, cur);
        nChild[cur] += nChild[ne];
      }
    }
  };
  dfs(dfs, x, -1);
  int tmp = y;
  while(P[tmp] != x) {
    tmp = P[tmp];
  }
  cout << 1LL * n * (n-1) - 1LL * (n-nChild[tmp]) * nChild[y] << endk;
  return 0;
}
