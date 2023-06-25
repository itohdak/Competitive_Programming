#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n, a, b; cin >> n >> a >> b;
  if(a + b > n-2) cout << -1 << endk;
  else if(abs(a - b) > 1) cout << -1 << endk;
  else {
    vector<int> ans(n);
    if(a == b) {
      int tmp = 1;
      rep(i, b+1) ans[i*2] = tmp++;
      rep(i, a+1) ans[i*2+1] = tmp++;
      rep(i, n-a-b-2) ans[i+(a+1)*2] = tmp++;
    } else {
      int tmp = 1;
      rep(i, n-a-b-1) ans[n-1-i] = tmp++;
      rep(i, min(a, b)+1) ans[i*2] = tmp++;
      rep(i, max(a, b)) ans[i*2+1] = tmp++;
      if(a < b) rep(i, n) ans[i] = n+1-ans[i];
    }
    int ca = 0, cb = 0;
    REP(i, 1, n-1) {
      if(ans[i-1] < ans[i] && ans[i] > ans[i+1]) ca++;
      if(ans[i-1] > ans[i] && ans[i] < ans[i+1]) cb++;
    }
    assert(a == ca && b == cb);
    rep(i, n) cout << ans[i] << ' '; cout << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
