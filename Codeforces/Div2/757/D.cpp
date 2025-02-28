#include <bits/stdc++.h>
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

vector<ll> find_divisor(ll N) {
  vector<ll> divisor;
  for(int i=1; i<=sqrt(N); i++) {
    if(N % i == 0)
      divisor.push_back(i);
  }
  int n = divisor.size();
  for(int i=n-1; i>=0; i--) {
    if(N != (ll)pow(divisor[i], 2))
      divisor.push_back(N / divisor[i]);
  }
  return divisor;
}
void solve() {
  int n; cin >> n;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  int MAX = 20000001;
  vector<int> cnt(MAX);
  rep(i, n) {
    auto div = find_divisor(A[i]);
    for(auto d: div) cnt[d]++;
  }
  vector<ll> dp(MAX);
  REP(i, 1, MAX) {
    if(cnt[i]) {
      for(int j=i+i; j<MAX; j+=i) {
        if(cnt[j]) {
          chmax(dp[j], dp[i]+1LL*(cnt[i]-cnt[j])*i);
        }
      }
    }
  }
  ll ans = 0;
  REP(i, 1, MAX) {
    if(cnt[i]) {
      chmax(ans, dp[i]+1LL*cnt[i]*i);
    }
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
