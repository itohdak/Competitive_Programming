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
  vector<int> S(n); rep(i, n) cin >> S[i];
  vector<int> T(m); rep(i, m) cin >> T[i];
  vector<bool> cntS(2);
  rep(i, n) cntS[S[i]] = true;
  bool first = true;
  int ans = 0;
  rep(i, m) {
    if((i ? T[i-1] : S[0]) == T[i]) ans++;
    else if(first) {
      int mn = n;
      rep(j, n-1) {
        if(S[j] != S[j+1]) {
          chmin(mn, j+1);
          break;
        }
        if(S[(n-j)%n] != S[(n-1-j)%n]) {
          chmin(mn, j+1);
          break;
        }
      }
      if(mn == n) {
        cout << -1 << endk;
        return 0;
      }
      ans += mn+1 ;
      first = false;
    } else {
      ans += 2;
    }
  }
  cout << ans << endk;
  return 0;
}
