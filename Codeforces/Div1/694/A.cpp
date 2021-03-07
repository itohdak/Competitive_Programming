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
  int n, m; cin >> n >> m;
  vector<ll> K(n);
  vector<ll> C(m);
  rep(i, n) {
    cin >> K[i];
    K[i]--;
  }
  rep(i, m) cin >> C[i];
  vector<ll> cost(n);
  int mx = -1;
  rep(i, n) {
    cost[i] = C[K[i]];
    chmax(mx, K[i]);
  }
  sort(all(cost));
  vector<ll> sum(n+1);
  rep(i, n) sum[i+1] = sum[i] + cost[i];
  vector<ll> sumC(m+1);
  rep(i, m) sumC[i+1] = sumC[i] + C[i];
  ll ans = longinf;
  for(int i=0; i<=min(n, mx); i++) {
    chmin(ans, sumC[i]+sum[n-i]);
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
