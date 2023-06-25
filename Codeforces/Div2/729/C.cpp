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

int MAX = 43;
vector<ll> prod(MAX);
void solve() {
  ll n; cin >> n;
  vector<ll> cnt(MAX);
  REP(i, 1, MAX) {
    cnt[i] = n / prod[i] - (i == MAX-1 ? 0 : n / prod[i+1]);
  }
  assert(accumulate(all(cnt), 0LL) == n);
  ll ans = 0;
  REP(i, 1, MAX) {
    (ans += cnt[i] % mod * (i+1)) %= mod;
  }
  // cout << cnt << endk;
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  prod[1] = 1;
  REP(i, 1, MAX-1) {
    ll g = __gcd(prod[i], (ll)(i+1));
    prod[i+1] = prod[i] * (i+1) / g;
  }
  // cout << prod << endk;
  while(T--) solve();
  return 0;
}
