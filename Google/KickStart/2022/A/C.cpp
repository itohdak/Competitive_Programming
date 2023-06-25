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

bool check(int i, bool check6=true) {
  assert(i < (1<<6));
  auto get_bit = [](int i, int b) -> int {
    return (i>>b)&1;
  };
  bool ok5 = true, ok6 = true;
  ok5 = !((get_bit(i, 0) == get_bit(i, 4)) && (get_bit(i, 1) == get_bit(i, 3)));
  ok6 = !((get_bit(i, 0) == get_bit(i, 5)) && (get_bit(i, 1) == get_bit(i, 4)) && (get_bit(i, 2) == get_bit(i, 3)));
  return ok5 && (!check6 || ok6);
}
void solve() {
  int n; cin >> n;
  string s; cin >> s;
  if(n <= 4) {
    cout << "POSSIBLE" << endk;
  } else {
    vector<vector<bool>> dp(n+1, vector<bool>(1<<5));

    auto dfs = [&](auto dfs, int cur, int tmp) -> void {
      if(cur == 5) {
        if(check(tmp, false)) {
          dp[5][tmp] = 1;
        }
        return;
      }
      if(s[cur] == '0') {
        dfs(dfs, cur+1, tmp<<1);
      } else if(s[cur] == '1') {
        dfs(dfs, cur+1, (tmp<<1)+1);
      } else {
        dfs(dfs, cur+1, tmp<<1);
        dfs(dfs, cur+1, (tmp<<1)+1);
      }
    };
    dfs(dfs, 0, 0);

    REP(i, 5, n) {
      rep(j, 1<<5) {
        if(!dp[i][j]) {
          continue;
        }
        if(s[i] == '0' || s[i] == '?') {
          if(check((j<<1))) {
            dp[i+1][(j<<1)&((1<<5)-1)] = true;
          }
        }
        if(s[i] == '1' || s[i] == '?') {
          if(check((j<<1)+1)) {
            dp[i+1][((j<<1)+1)&((1<<5)-1)] = true;
          }
        }
      }
    }

    // rep(i, n+1) {
    //   cout << dp[i] << endk;
    // }
    rep(j, 1<<5) {
      if(dp[n][j]) {
        cout << "POSSIBLE" << endk;
        return;
      }
    }
    cout << "IMPOSSIBLE" << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  rep(i, t) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  return 0;
}
