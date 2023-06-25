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
  vector<ll> R(n); rep(i, n) cin >> R[i];
  int m; cin >> m;
  vector<ll> B(m); rep(i, m) cin >> B[i];
  vector<ll> sumR(n+1);
  rep(i, n) sumR[i+1] = sumR[i] + R[i];
  vector<ll> sumB(m+1);
  rep(i, m) sumB[i+1] = sumB[i] + B[i];
  ll ans = 0;
  rep(i, n+1) rep(j, m+1) chmax(ans, sumR[i]+sumB[j]);
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
