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
  string s; cin >> s;
  vector<int> cnt(n+1);
  rep(i, n) {
    cnt[i+1] = cnt[i] + (s[i] == '1');
  }
  vector<ll> dpl(n+1), dpr(n+1);
  rep(i, n) {
    if(s[i] == '1') {
      dpl[i+1] = dpl[i];
    } else {
      dpl[i+1] = dpl[i] + cnt[i];
    }
  }
  rrep(i, n) {
    if(s[i] == '1') {
      dpr[i] = dpr[i+1];
    } else {
      dpr[i] = dpr[i+1] + (cnt[n]-cnt[i]);
    }
  }
  // cout << dpl << endk << dpr << endk;
  ll ans = longinf;
  rep(i, n) {
    chmin(ans, dpl[i]+dpr[i]);
  }
  cout << ans << endk;
  return 0;
}
