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
  vector<string> S(n);
  rep(i, n) {
    cin >> S[i];
  }
  vector<int> dpl(n, inf), dpr(n, inf);
  dpl[0] = 0;
  rep(i, n) {
    REP(j, 1, m+1) {
      if(i+j < n && S[i][j-1] == '1') {
        chmin(dpl[i+j], dpl[i]+1);
      }
    }
  }
  dpr[n-1] = 0;
  rrep(i, n) {
    REP(j, 1, m+1) {
      if(i-j >= 0 && S[i-j][j-1] == '1') {
        chmin(dpr[i-j], dpr[i]+1);
      }
    }
  }
  REP(i, 1, n-1) {
    int ans = inf;
    REP(j, 1, m+1) {
      REP(k, 1, m+1) {
        if(i-j >= 0 && i-j+k > i && S[i-j][k-1] == '1') {
          chmin(ans, dpl[i-j]+dpr[i-j+k]+1);
        }
      }
    }
    cout << (ans==inf ? -1 : ans) << ' ';
  }
  cout << endk;
  return 0;
}
