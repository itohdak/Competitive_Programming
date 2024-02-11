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
  int h, w; cin >> h >> w;
  vector<string> S(h); rep(i, h) cin >> S[i];
  int xmn = h, xmx = 0, ymn = w, ymx = 0;
  rep(i, h) rep(j, w) {
    if(S[i][j] == '#') {
      chmin(xmn, i);
      chmax(xmx, i);
      chmin(ymn, j);
      chmax(ymx, j);
    }
  }
  for(int i=xmn; i<=xmx; i++) {
    for(int j=ymn; j<=ymx; j++) {
      if(S[i][j] != '#') {
	cout << i+1 << ' ' << j+1 << endk;
	return 0;
      }
    }
  }
  return 0;
}
