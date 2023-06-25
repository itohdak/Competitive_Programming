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
  int r, c; cin >> r >> c;
  r--; c--;
  int n; cin >> n;
  map<int, vector<int>> R, C;
  rep(i, n) {
    int r, c; cin >> r >> c;
    r--; c--;
    R[r].push_back(c);
    C[c].push_back(r);
  }
  for(auto& [_, v]: R) {
    v.push_back(-1);
    v.push_back(w);
    sort(all(v));
  }
  for(auto& [_, v]: C) {
    v.push_back(-1);
    v.push_back(h);
    sort(all(v));
  }
  int q; cin >> q;
  int x = r, y = c;
  rep(i, q) {
    char d; int l;
    cin >> d >> l;
    if(d == 'U') {
      if(C.count(y)) {
        x = max(x-l, *(--upper_bound(all(C[y]), x))+1);
      } else {
        x = max(x-l, 0);
      }
    } else if(d == 'D') {
      if(C.count(y)) {
        x = min(x+l, *(lower_bound(all(C[y]), x))-1);
      } else {
        x = min(x+l, h-1);
      }
    } else if(d == 'R') {
      if(R.count(x)) {
        y = min(y+l, *(lower_bound(all(R[x]), y))-1);
      } else {
        y = min(y+l, w-1);
      }
    } else {
      if(R.count(x)) {
        y = max(y-l, *(--upper_bound(all(R[x]), y))+1);
      } else {
        y = max(y-l, 0);
      }
    }
    cout << x+1 << ' ' << y+1 << endk;
  }
  return 0;
}
