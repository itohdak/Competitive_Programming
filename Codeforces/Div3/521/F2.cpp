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

template<typename T>
vector<T> slide_max(const vector<T>& v, int k) {
  deque<int> deq;
  vector<T> ret;
  for(int i=0; i<v.size(); i++) {
    while(!deq.empty() && v[deq.back()] <= v[i]) deq.pop_back();
    deq.push_back(i);
    // if(i-k+1 >= 0) {
      ret.push_back(v[deq.front()]);
      if(deq.front() == i-k+1) deq.pop_front();
    // }
  }
  return ret;
}
void solve() {
  int n, k, x; cin >> n >> k >> x;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<vector<ll>> dp(2, vector<ll>(n+1, -longinf));
  dp[0][0] = 0;
  rep(i, x) {
    int cur = i%2, next = 1-cur;
    auto ret = slide_max(dp[cur], k);
    rep(j, n) dp[next][j+1] = ret[j] + A[j];
  }
  auto ret = slide_max(dp[x%2], k);
  ll ans = ret.back();
  cout << (ans<0 ? -1 : ans) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
