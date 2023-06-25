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
const ll mod2 = 998244353;
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
  ll b, q, y; cin >> b >> q >> y;
  ll c, r, z; cin >> c >> r >> z;
  if(r%q || abs(c-b)%q || (c < b || b+q*(y-1) < c+r*(z-1))) {
    cout << 0 << endk;
    return;
  }
  if(c-r < b || c+r*(z-1)+r > b+q*(y-1)) {
    cout << -1 << endk;
    return;
  }
  auto count = [&](ll p) -> ll {
    return (r/p)*(r/p)%mod;
  };
  ll ans = 0;
  ll p0 = r/q;
  auto D = find_divisor(q);
  for(ll div: D) {
    ll p = p0 * div;
    if(p/__gcd(p, q)*q != r) continue;
    (ans += count(p)) %= mod;
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
