#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
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
  ll P, F; cin >> P >> F;
  int CS, CW; cin >> CS >> CW;
  ll s, w; cin >> s >> w;
  if(s > w) {
    swap(s, w);
    swap(CS, CW);
  }
  ll ans = 0;
  for(int i=0; i<=CS; i++) {
    ll tmp = 0, a = 0;
    int cs = CS, cw = CW;
    int p = P, f = F;
    if(p < s*i) continue;
    // p
    tmp = i;
    a += tmp;
    p -= s*tmp;
    cs -= tmp;
    tmp = min(p/w, (ll)cw);
    a += tmp;
    p -= w*tmp;
    cw -= tmp;
    // f
    tmp = min(f/s, (ll)cs);
    a += tmp;
    f -= s*tmp;
    cs -= tmp;
    tmp = min(f/w, (ll)cw);
    a += tmp;
    f -= w*tmp;
    cw -= tmp;
    chmax(ans, a);
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
