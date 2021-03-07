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
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> C(n); rep(i, n) cin >> C[i];
  priority_queue<pair<int, int>> q;
  rep(i, n) q.push({-C[i], i});
  rep(_, m) {
    int t; ll d; cin >> t >> d;
    t--;
    ll ans = 0;
    {
      ll cnt = min(d, A[t]);
      ans += C[t] * cnt;
      A[t] -= cnt;
      d -= cnt;
    }
    while(d && q.size()) {
      auto [cost, i] = q.top(); q.pop();
      cost = -cost;
      ll cnt = min(d, A[i]);
      ans += C[i] * cnt;
      A[i] -= cnt;
      d -= cnt;
      if(A[i]) q.push({-C[i], i});
    }
    if(d) cout << 0 << endk;
    else cout << ans << endk;
  }
  return 0;
}
