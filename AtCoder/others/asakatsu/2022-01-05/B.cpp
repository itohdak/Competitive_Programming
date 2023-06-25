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
  vector<string> ans(h);
  rep(i, h) {
    rep(j, w) {
      if(S[i][j] == '#') {
        ans[i] += '#';
        continue;
      }
      int cnt = 0;
      for(int di=-1; di<=1; di++) {
        for(int dj=-1; dj<=1; dj++) {
          if(di == 0 && dj == 0) continue;
          int ni = i+di, nj = j+dj;
          if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
          if(S[ni][nj] == '#') cnt++;
        }
      }
      ans[i] += char('0'+cnt);
    }
  }
  rep(i, h) cout << ans[i] << endk;
  return 0;
}
