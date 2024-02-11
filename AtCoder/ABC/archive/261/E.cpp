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
  int n, c; cin >> n >> c;
  vector<int> T(n), A(n);
  rep(i, n) cin >> T[i] >> A[i];
  vector<int> ans(n);
  int next[4][3][2] = {0};
  next[0][0][0] = 0;
  next[0][0][1] = 0;
  next[0][1][0] = 0;
  next[0][1][1] = 1;
  next[0][2][0] = 0;
  next[0][2][1] = 1;
  next[1][0][0] = 0;
  next[1][0][1] = 1;
  next[1][1][0] = 1;
  next[1][1][1] = 1;
  next[1][2][0] = 1;
  next[1][2][1] = 0;
  next[2][0][0] = 0;
  next[2][0][1] = 2;
  next[2][1][0] = 2;
  next[2][1][1] = 1;
  next[2][2][0] = 2;
  next[2][2][1] = 3;
  next[3][0][0] = 0;
  next[3][0][1] = 3;
  next[3][1][0] = 3;
  next[3][1][1] = 1;
  next[3][2][0] = 3;
  next[3][2][1] = 2;
  rep(j, 30) {
    int s = 2;
    int b = (c>>j)&1;
    rep(i, n) {
      int a = (A[i]>>j)&1;
      s = next[s][T[i]-1][a];
      if(s == 0) {
        b = 0;
      } else if(s == 1) {
        b = 1;
      } else if(s == 2) {
        b = b;
      } else {
        b = 1-b;
      }
      ans[i] += (b<<j);
    }
  }
  rep(i, n) cout << ans[i] << endk;
  return 0;
}
