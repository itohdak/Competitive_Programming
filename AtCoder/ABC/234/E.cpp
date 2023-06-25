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
  ll x; cin >> x;
  vector<int> D;
  ll xtmp = x;
  while(xtmp) {
    D.push_back(xtmp%10);
    xtmp /= 10;
  }
  reverse(all(D));
  int n = D.size();
  ll ans = LONG_LONG_MAX;
  rep(i, 10) rep(j, 10) {
    if(i == 0) continue;
    int d = j-i;
    ll y = 0;
    bool ok = true;
    int tmp = i;
    rep(i, n) {
      if(tmp < 0 || tmp >= 10) {
        ok = false;
        break;
      }
      y *= 10;
      y += tmp;
      tmp += d;
    }
    if(!ok) continue;
    if(y >= x) {
      chmin(ans, y);
    }
    if(tmp < 0 || tmp >= 10) continue;
    y *= 10;
    y += tmp;
    if(y >= x) {
      chmin(ans, y);
    }
  }
  cout << ans << endk;
  return 0;
}
