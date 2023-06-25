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
  vector<int> N(n, -1);
  vector<int> S(m), C(m);
  rep(i, m) cin >> S[i] >> C[i];
  rep(i, m) {
    S[i]--;
    if(N[S[i]] == -1) {
      N[S[i]] = C[i];
    } else if(N[S[i]] != C[i]) {
      cout << -1 << endk;
      return 0;
    }
  }
  // cout << N << endk;
  if(n == 1) {
    cout << (N[0] == -1 ? 0 : N[0]) << endk;
  } else {
    if(N[0] == 0) {
      cout << -1 << endk;
      return 0;
    }
    int ans = 0;
    rep(i, n) {
      ans *= 10;
      ans += (N[i] == -1 ? (i == 0 ? 1 : 0) : N[i]);
    }
    cout << ans << endk;
  }
  return 0;
}
