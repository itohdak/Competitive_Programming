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

// 最長増加部分列の長さを求める
int LIS(const vector<ll> &a) {
    int N = (int)a.size();
    vector<ll> dp(N, longinf+5);
    for (int i = 0; i < N; ++i) {
        // dp[k] >= a[i] となる最小のイテレータを見つける
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);

        // そこを a[i] で書き換える
        *it = a[i];
    }

    // dp[k] < longinf+5 となる最大の k に対して k+1 が答え
    // それは dp[k] >= longinf+5 となる最小の k に一致する
    return lower_bound(dp.begin(), dp.end(), longinf+5) - dp.begin();
}
void solve() {
  int n, k; cin >> n >> k;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<int> B(k);
  rep(i, k) {
    cin >> B[i];
    B[i]--;
  }
  rep(i, k-1) {
    if(A[B[i]] >= A[B[i+1]]) {
      cout << -1 << endk;
      return;
    }
  }
  vector<vector<ll>> C(k+1);
  rep(i, k+1) {
    REP(j, (i==0 ? 0 : B[i-1]+1), (i == k ? n : B[i])) C[i].push_back(A[j]);
  }
  cout << C << endk;
  auto DP = [&](ll l, ll r, vector<ll>& v) {
    vector<ll> w;
    w.push_back(l);
    for(ll a: v) if(l < a && a < r) w.push_back(a);
    w.push_back(r);
    int ret = LIS(w);
    return v.size() + 2 - ret;
  };
  int ans = 0;
  rep(i, k+1) {
    ans += DP((i==0 ? -longinf : A[B[i-1]]),
              (i==k ? longinf : A[B[i]]),
              C[i]);
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
