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
  int b, w; cin >> b >> w;
  int mn = min(b, w);
  int diff = abs(b-w);
  if(diff > mn*2+1) cout << "NO" << endk;
  else {
    cout << "YES" << endk;
    rep(i, 2*mn) cout << 2 << ' ' << 2+i << endk;
    if(b == w) return;
    else if(b < w) {
      cout << 2 << ' ' << 2+2*mn << endk;
      diff--;
      int tmp = 3;
      while(diff) {
        cout << 1 << ' ' << tmp << endk;
        diff--;
        if(diff == 0) break;
        cout << 3 << ' ' << tmp << endk;
        diff--;
        tmp += 2;
      }
    } else {
      cout << 2 << ' ' << 1 << endk;
      diff--;
      int tmp = 2;
      while(diff) {
        cout << 1 << ' ' << tmp << endk;
        diff--;
        if(diff == 0) break;
        cout << 3 << ' ' << tmp << endk;
        diff--;
        tmp += 2;
      }
    }
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
