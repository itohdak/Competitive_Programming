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
  int n; cin >> n;
  vector<string> S(n); rep(i, n) cin >> S[i];
  int len = S[0].size();
  auto rotate = [](string s, int b) {
    return s.substr(b) + s.substr(0, b);
  };
  int ans = inf;
  rep(p, len) {
    int tmp = p;
    rep(i, n) {
      if(i) {
        bool ok = false;
        rep(q, len) {
          if(rotate(S[0], p) == rotate(S[i], q)) {
            tmp += q;
            ok = true;
            break;
          }
        }
        if(!ok) {
          tmp = inf;
          break;
        }
      }
    }
    chmin(ans, tmp);
    // cout << p << ' ' << ans << endk;
  }
  cout << (ans == inf ? -1 : ans) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
