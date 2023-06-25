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
  int h, w, a, b; cin >> h >> w >> a >> b;
  ll ans = 0;
  vector<vector<bool>> tatami(h, vector<bool>(w));
  auto dfs = [&](auto dfs, int cur, int cnt) -> void {
    if(cur == h*w) {
      if(cnt == a) ans++;
      return;
    }
    int hh = cur/w, ww = cur%w;
    dfs(dfs, cur+1, cnt); // do nothing
    if(hh+1 < h && !tatami[hh][ww] && !tatami[hh+1][ww]) {
      tatami[hh][ww] = true;
      tatami[hh+1][ww] = true;
      dfs(dfs, cur+1, cnt+1);
      tatami[hh][ww] = false;
      tatami[hh+1][ww] = false;
    }
    if(ww+1 < w && !tatami[hh][ww] && !tatami[hh][ww+1]) {
      tatami[hh][ww] = true;
      tatami[hh][ww+1] = true;
      dfs(dfs, cur+1, cnt+1);
      tatami[hh][ww] = false;
      tatami[hh][ww+1] = false;
    }
  };
  dfs(dfs, 0, 0);
  cout << ans << endk;
  return 0;
}
