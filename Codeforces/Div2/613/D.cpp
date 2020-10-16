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
  vector<ll> A(n); rep(i, n) cin >> A[i];
  sort(all(A));
  ll ans = longinf;
  int cnt = 0;
  auto dfs = [&](auto dfs, int b, int l, int r, ll val) -> void {
    // cout << l << ' ' << r << endk;
    if(b == -1) {
      chmin(ans, val);
      return;
    }
    int nr = l;
    for(int i=l; i<r; i++) {
      if(!((A[i]>>b)&1)) nr = i+1;
      cnt++;
    }
    if(nr != l && nr != r) {
      val += (1LL<<b);
      dfs(dfs, b-1, l, nr, val);
      dfs(dfs, b-1, nr, r, val);
    } else {
      dfs(dfs, b-1, l, r, val);
    }
  };
  dfs(dfs, 30, 0, n, 0);
  cout << ans << endk;
  assert(cnt == 31*n);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
