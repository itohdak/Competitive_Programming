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
  int n, m; cin >> n >> m;
  vector<int> A(m), C(m);
  rep(i, m) cin >> A[i] >> C[i];
  int g = n;
  rep(i, m) g = __gcd(A[i], g);
  if(g > 1) {
    cout << -1 << endk;
    return 0;
  }
  priority_queue<pair<int, int>> q;
  rep(i, m) q.push({-C[i], -A[i]});
  g = n;
  ll ans = 0;
  rep(i, m) {
    auto [c, a] = q.top(); q.pop();
    c = -c, a = -a;
    int _g = g;
    g = __gcd(a, g);
    ans += 1LL * (_g - g) * c;
  }
  cout << ans << endk;
  return 0;
}
