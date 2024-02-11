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
  vector<vector<int>> A(2*n, vector<int>(2*n));
  rep(i, 2*n) {
    REP(j, i+1, 2*n) {
      int a; cin >> a;
      A[i][j] = A[j][i] = a;
    }
  }
  int ans = 0;
  vector<bool> used(2*n);
  auto dfs = [&](auto dfs, int cur, int cnt) {
    if(cnt == 2*n) {
      chmax(ans, cur);
      return;
    }
    int l = 0;
    rep(i, 2*n) {
      if(!used[i]) {
        l = i;
        break;
      }
    }
    used[l] = true;
    rep(i, 2*n) {
      if(!used[i]) {
        used[i] = true;
        dfs(dfs, cur^A[l][i], cnt+2);
        used[i] = false;
      }
    }
    used[l] = false;
  };
  dfs(dfs, 0, 0);
  cout << ans << endk;
  return 0;
}
