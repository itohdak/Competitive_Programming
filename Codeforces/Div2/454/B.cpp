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
  vector<string> S(9);
  rep(i, 9) {
    rep(j, 3) {
      string s;
      cin >> s;
      S[i] += s;
    }
  }
  int x, y; cin >> x >> y; x--; y--;
  bool ok = false;
  for(int i=x%3*3; i<x%3*3+3; i++) {
    for(int j=y%3*3; j<y%3*3+3; j++) {
      if(S[i][j] == '.') {
        S[i][j] = '!';
        ok = true;
      }
    }
  }
  if(!ok) {
    rep(i, 9) rep(j, 9) if(S[i][j] == '.') S[i][j] = '!';
  }
  rep(i, 9) {
    cout << S[i].substr(0, 3) + ' ' +  S[i].substr(3, 3) + ' ' + S[i].substr(6, 3) << endk;
    if(i%3==2) cout << endk;
  }
  return 0;
}
