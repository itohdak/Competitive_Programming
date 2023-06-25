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
  vector<string> S(n); rep(i, n) cin >> S[i];
  rep(i, n) rep(j, n) {
    // tate
    if(i+6 <= n) {
      int cnt = 0;
      rep(k, 6) if(S[i+k][j] == '.') cnt++;
      if(cnt <= 2) {
        cout << "Yes" << endk;
        return 0;
      }
    }
    // yoko
    if(j+6 <= n) {
      int cnt = 0;
      rep(k, 6) if(S[i][j+k] == '.') cnt++;
      if(cnt <= 2) {
        cout << "Yes" << endk;
        return 0;
      }
    }
    // naname
    if(i+6 <= n && j+6 <= n) {
      int cnt = 0;
      rep(k, 6) if(S[i+k][j+k] == '.') cnt++;
      if(cnt <= 2) {
        cout << "Yes" << endk;
        return 0;
      }
    }
    if(i-5 >= 0 && j+6 <= n) {
      int cnt = 0;
      rep(k, 6) if(S[i-k][j+k] == '.') cnt++;
      if(cnt <= 2) {
        cout << "Yes" << endk;
        return 0;
      }
    }
  }
  cout << "No" << endk;
  return 0;
}
