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
  int n, l, r; cin >> n >> l >> r;
  vector<int> Cl(l), Cr(r);
  rep(i, l) cin >> Cl[i];
  rep(i, r) cin >> Cr[i];
  map<int, int> cntl, cntr;
  rep(i, l) cntl[Cl[i]]++;
  rep(i, r) cntr[Cr[i]]++;
  ll ans = 0;
  for(auto& [col, num]: cntl) {
    if(cntr.count(col)) {
      int mn = min(num, cntr[col]);
      num -= mn;
      cntr[col] -= mn;
      l -= mn;
      r -= mn;
    }
  }
  if(l < r) {
    for(auto& [col, num]: cntr) {
      int tmp = min(num/2, (r-l)/2);
      ans += tmp;
      num -= tmp*2;
      r -= tmp*2;
    }
  } else if(l > r) {
    for(auto& [col, num]: cntl) {
      int tmp = min(num/2, (l-r)/2);
      ans += tmp;
      num -= tmp*2;
      l -= tmp*2;
    }
  }
  ans += max(l, r);
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
