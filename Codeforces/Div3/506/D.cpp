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
  int n; ll k; cin >> n >> k;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<vector<ll>> rem(n, vector<ll>(11));
  rep(i, n) {
    rem[i][0] = A[i] % k;
    rep(j, 11) {
      if(j) rem[i][j] = rem[i][j-1] * 10 % k;
    }
  }
  // cout << rem << endk;
  vector<map<ll, int>> cnt(11);
  rep(i, n) {
    rep(j, 11) {
      cnt[j][rem[i][j]]++;
    }
  }
  // cout << cnt << endk;
  ll ans = 0;
  rep(i, n) {
    int d = (int)log10(A[i])+1;
    ans += cnt[d][(k-rem[i][0])%k] - (rem[i][d] == (k-rem[i][0])%k);
  }
  cout << ans << endk;
  return 0;
}
