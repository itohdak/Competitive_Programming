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
  int n, q; cin >> n >> q;
  vector<vector<bool>> on(2, vector<bool>(n));
  vector<vector<bool>> locked(2, vector<bool>(n));
  int cnt = 0;
  auto check = [&](int r, int c) {
    bool ok = true;
    for(int i=-1; i<=1; i++) {
      if(c+i>=0 && c+i<n) {
        ok &= !(on[1-r][c+i] && on[r][c]);
      }
    }
    return ok;
  };
  rep(_, q) {
    int r, c; cin >> r >> c;
    r--; c--;
    if(on[r][c]) { // on -> off
      on[r][c] = false;
      if(locked[r][c] && check(r, c)) {
        cnt--;
        locked[r][c] = false;
      }
      for(int i=-1; i<=1; i++) {
        if(c+i>=0 && c+i<n) {
          if(locked[1-r][c+i] && check(1-r, c+i)) {
            cnt--;
            locked[1-r][c+i] = false;
          }
        }
      }
    } else {
      on[r][c] = true;
      if(!locked[r][c] && !check(r, c)) {
        cnt++;
        locked[r][c] = true;
      }
      for(int i=-1; i<=1; i++) {
        if(c+i>=0 && c+i<n) {
          if(!locked[1-r][c+i] && !check(1-r, c+i)) {
            cnt++;
            locked[1-r][c+i] = true;
          }
        }
      }
    }
    cout << (cnt ? "NO" : "YES") << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
