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

ll comb(int n, int k) {
  ll ret = 1;
  rep(i, k) ret *= (n-i);
  rep(i, k) ret /= i+1;
  return ret;
}
void solve() {
  int n, m, k; cin >> n;
  m = 3, k = 2;
  vector<int> A(n);
  vector<int> cnt(n);
  rep(i, n) {
    cin >> A[i];
    A[i]--;
    cnt[A[i]]++;
  }
  rep(i, n) if(i) cnt[i] += cnt[i-1];
  ll ans = 0;
  // cout << cnt << endk;
  rep(i, n) {
    // cout << i << ' ' << cnt[min(i+k, n-1)]-(i ? cnt[i-1] : 0) << ' ' << cnt[min(i+k, n-1)]-cnt[i] << endk;
    ans += comb(cnt[min(i+k, n-1)]-(i ? cnt[i-1] : 0), m) - comb(cnt[min(i+k, n-1)]-cnt[i], m);
  }
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
