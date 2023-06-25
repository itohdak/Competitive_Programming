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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n; cin >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> id(n);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    return A[i] < A[j];
  });
  int ans = (A[id[0]]+1)/2 + (A[id[1]]+1)/2;
  auto need = [&](int a, int b, int k) {
    return k + max({0, (a-2*k), (b-k+1)/2});
  };
  auto bsearch = [&](int a, int b) {
    int r = (a+1)/2+(b+1)/2, l = -1;
    while(r-l>2) {
      int c1 = l+(r-l)/3;
      int c2 = r-(r-l)/3;
      if(need(a, b, c1) < need(a, b, c2)) {
        r = c2;
      } else {
        l = c1;
      }
    }
    int ans = inf;
    for(int i=l; i<=r; i++) {
      chmin(ans, need(a, b, i));
    }
    return ans;
  };
  rep(i, n-1) {
    chmin(ans, bsearch(A[i], A[i+1]));
  }
  REP(i, 1, n-1) {
    chmin(ans, max(A[i-1], A[i+1]));
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
