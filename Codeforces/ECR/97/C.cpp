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
  vector<int> T(n);
  vector<int> cnt(n);
  rep(i, n) {
    cin >> T[i];
    T[i]--;
    cnt[T[i]]++;
  }
  vector<vector<int>> dp(n+1, vector<int>(2*n+5, inf));
  auto calc = [&](int l, int r, int x) { // [l, r)
    if(x <= l) {
      return ((l-x)+(r-1-x))*(r-l)/2;
    } else if(x <= r) {
      return (x-l)*(x-l+1)/2 + (r-1-x)*(r-x)/2;
    } else {
      return ((x-l)+(x-r+1))*(r-l)/2;
    }
  };
  rep(i, 2*n+5) dp[0][i] = 0;
  rep(i, n) {
    rep(j, 2*n+5) {
      REP(k, j, 2*n+5) {
        if(k+cnt[i] > 2*n+5) continue;
        chmin(dp[i+1][k+cnt[i]], dp[i][j]+calc(k, k+cnt[i], i));
      }
    }
  }
  cout << *min_element(all(dp[n])) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
