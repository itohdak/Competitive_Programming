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
  int n; cin >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  auto solve1 = [&]() -> ld {
    auto test = [&](ld k) {
      vector<bool> ok(n);
      ld sum = 0;
      rep(i, n) {
        if(A[i] >= k) {
          ok[i] = true;
          sum += A[i]-k;
        }
      }
      vector<vector<ld>> dp(n+1, vector<ld>(2, 1e+15));
      dp[0][0] = dp[0][1] = 0;
      rep(i, n) {
        rep(j, 2) {
          if(ok[i]) {
            chmin(dp[i+1][0], dp[i][j]);
            chmin(dp[i+1][1], dp[i][j]);
          } else {
            if(j == 0) {
              chmin(dp[i+1][1], dp[i][j]+(k-A[i]));
            } else {
              chmin(dp[i+1][0], dp[i][j]);
              chmin(dp[i+1][1], dp[i][j]+(k-A[i]));
            }
          }
        }
      }
      return *min_element(all(dp[n])) <= sum;
    };
    ld ok = 1, ng = inf;
    rep(i, 60) {
      ld mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  auto solve2 = [&]() {
    auto test = [&](int k) {
      int cnt = 0;
      vector<bool> ok(n);
      rep(i, n) {
        if(A[i] >= k) {
          cnt++;
          ok[i] = true;
        }
      }
      int need = 0;
      int l = 0;
      while(l < n) {
        while(l < n && ok[l]) l++;
        int r = l;
        while(r < n && !ok[r]) r++;
        int d = r-l;
        need += d/2;
        l = r;
      }
      return need < cnt;
    };
    int ok = 1, ng = inf;
    while(abs(ok-ng)>1) {
      int mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << fixed << setprecision(10);
  cout << solve1() << endk;
  cout << solve2() << endk;
  return 0;
}
