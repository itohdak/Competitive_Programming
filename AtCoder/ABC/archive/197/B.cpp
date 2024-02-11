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
  int h, w, x, y; cin >> h >> w >> x >> y;
  x--; y--;
  vector<string> S(h); rep(i, h) cin >> S[i];
  int ans = 1;
  for(int i=x+1; i<h; i++) {
    if(S[i][y] == '#') break;
    ans++;
  }
  for(int i=x-1; i>=0; i--) {
    if(S[i][y] == '#') break;
    ans++;
  }
  for(int j=y+1; j<w; j++) {
    if(S[x][j] == '#') break;
    ans++;
  }
  for(int j=y-1; j>=0; j--) {
    if(S[x][j] == '#') break;
    ans++;
  }
  cout << ans << endk;
  return 0;
}
