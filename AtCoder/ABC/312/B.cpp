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
  rep(i, n) cin >> S[i];
  rep(i, n-8) rep(j, m-8) {
    bool ok = true;
    rep(i2, 4) rep(j2, 4) {
      if(i2 == 3 || j2 == 3) {
	if(S[i+i2][j+j2] != '.') ok = false;
	if(S[i+8-i2][j+8-j2] != '.') ok = false;
      } else {
	if(S[i+i2][j+j2] != '#') ok = false;
	if(S[i+8-i2][j+8-j2] != '#') ok = false;
      }
    }
    if(ok) cout << i+1 << ' ' << j+1 << endk;
  }
  return 0;
}
