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
  vector<string> S(n); rep(i, n) cin >> S[i];
  vector<string> T(n, string(m, '.'));
  REP(i, 1, n-1) {
    REP(j, 1, m-1) {
      int cnt = 0;
      for(int k=-1; k<=1; k++) {
        for(int l=-1; l<=1; l++) {
          if(k==0 && l==0) continue;
          cnt += S[i+k][j+l] == '#';
        }
      }
      if(cnt == 8) {
        for(int k=-1; k<=1; k++) {
          for(int l=-1; l<=1; l++) {
            if(k==0 && l==0) continue;
            T[i+k][j+l] = '#';
          }
        }
      }
    }
  }
  rep(i, n) if(S[i] != T[i]) {
    cout << "NO" << endk;
    return 0;
  }
  cout << "YES" << endk;
  return 0;
}
