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
  vector<int> A(m); rep(i, m) cin >> A[i];
  vector<int> B(m); rep(i, m) cin >> B[i];
  vector<vector<int>> G(n);
  rep(i, m) {
    A[i]--; B[i]--;
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }
  vector<int> C(n, -1);
  bool ok = true;
  auto dfs = [&](auto dfs, int cur) -> void {
    for(int ne: G[cur]) {
      if(C[ne] != -1) {
        if(C[ne] == C[cur]) {
          ok = false;
          return;
        }
      } else {
        C[ne] = 1 - C[cur];
        dfs(dfs, ne);
        if(!ok) return;
      }
    }
  };
  rep(i, n) {
    if(C[i] == -1) {
      C[i] = 0;
      dfs(dfs, i);
    }
  }
  cout << (ok ? "Yes" : "No") << endk;
  return 0;
}
