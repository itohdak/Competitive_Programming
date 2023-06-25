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
  int n, k; cin >> n >> k;
  vector<vector<ll>> A(n, vector<ll>(n));
  rep(i, n) rep(j, n) cin >> A[i][j];
  auto bsearch = [&]() {
    auto test = [&](ll t) {
      vector<vector<int>> cnt(n+1, vector<int>(n+1));
      rep(i, n) rep(j, n) if(A[i][j] <= t) cnt[i+1][j+1]++;
      rep(i, n) rep(j, n+1) cnt[i+1][j] += cnt[i][j];
      rep(j, n) rep(i, n+1) cnt[i][j+1] += cnt[i][j];
      // cout << t << ' ' << cnt << endk;
      rep(i, n) rep(j, n) {
        if(i+k > n || j+k > n) continue;
        int c = cnt[i+k][j+k] + cnt[i][j] - cnt[i+k][j] - cnt[i][j+k];
        if(c >= (k*k+1)/2) return true;
      }
      return false;
    };
    ll ok = longinf, ng = -1;
    while(abs(ok-ng) > 1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch() << endk;
  return 0;
}
