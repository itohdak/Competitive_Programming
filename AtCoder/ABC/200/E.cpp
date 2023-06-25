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
  vector<ll> cnt(2*n+1); // 2つ
  for(int i=2; i<=2*n; i++) {
    if(i <= n+1) cnt[i] = i-2+1;
    else         cnt[i] = 2*n-i+1;
  }
  vector<ll> sum(2*n+2);
  rep(i, 2*n+1) sum[i+1] = sum[i] + cnt[i];
  vector<ll> cnt2(3*n+1);
  for(int i=3; i<=3*n; i++) {
    cnt2[i] = sum[min(2*n+1, i-1+1)] - sum[max(2, i-n)];
  }
  vector<ll> sum2(3*n+2);
  rep(i, 3*n+1) sum2[i+1] = sum2[i] + cnt2[i];
  auto s = lower_bound(all(sum2), k) - begin(sum2);
  ll rem = k - sum2[s-1];
  // cout << cnt << endk;
  // cout << sum << endk;
  // cout << cnt2 << endk;
  // cout << sum2 << endk;
  // cout << s-1 << ' ' << rem << endk;
  s--;
  for(int i=1; i<=n; i++) {
    if(s-i < 0 || s-i > 2*n) continue;
    if(rem - cnt[s-i] <= 0) {
      int t = s-i;
      // cout << t << endk;
      for(int j=1; j<=n; j++) {
        if(t-j < 0 || t-j > n) continue;
        if(rem == 1) {
          cout << i << ' ' << j << ' ' << t-j << endk;
          return 0;
        }
        rem--;
      }
    }
    rem -= cnt[s-i];
  }
  return 0;
}
