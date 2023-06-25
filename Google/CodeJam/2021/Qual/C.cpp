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

void solve() {
  int n, c; cin >> n >> c;
  vector<int> L(n);
  iota(all(L), 1);
  if(c < n-1) {
    cout << "IMPOSSIBLE" << endk;
    return;
  }
  c -= n-1;
  rrep(i, n-1) {
    int avail = n-1-i;
    if(avail >= c) {
      reverse(begin(L)+i, begin(L)+i+c+1);
      c = 0;
      break;
    } else {
      reverse(begin(L)+i, end(L));
      c -= avail;
    }
  }
  if(c) cout << "IMPOSSIBLE" << endk;
  else {
    rep(i, n) cout << L[i] << ' ';
    cout << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  rep(i, t) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  return 0;
}
