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
  int t; cin >> t;
  while(t--) {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int ans = 0;
    rep(i, n) {
      if(s[i] == '0') continue;
      // if(i-k < 0 && i+k >= n) continue;
      int cnt = 0;
      if(i-k >= 0) cnt += (s[i-k] == '1');
      if(i+k < n) cnt += (s[i+k] == '1');
      // cout << i << ' ' << cnt << endk;
      if(cnt == 0) {
        ans++;
        if(i+k < n) s[i+k] = '1';
        else s[i] = '0';
      }
    }
    cout << ans << endk;
  }
  return 0;
}
