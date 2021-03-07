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
  int n; ll l; cin >> n >> l;
  vector<ll> X(n), D(n), T(n), P(n);
  vector<tuple<ll, ll, ll, int>> V;
  rep(i, n) {
    cin >> X[i] >> D[i] >> T[i] >> P[i];
    V.push_back({X[i]-P[i], X[i]+D[i], T[i]+P[i], i});
  }
  sort(all(V));
  vector<ll> dp(n+1, longinf);
  rep(i, n) dp[i] = get<0>(V[i]);
  // cout << dp << endk;
  vector<int> par(n+1, -1);
  rep(i, n) {
    auto [begin, end, t, idx] = V[i];
    if(begin < 0) continue;
    if(dp[i+1] > dp[i]+(i+1==n ? l : get<0>(V[i+1]))-begin) {
      chmin(dp[i+1], dp[i]+(i+1==n ? l : get<0>(V[i+1]))-begin); // do nothing
      par[i+1] = i;
    }
    int j = lower_bound(all(V), make_tuple(end, end, end, 0)) - V.begin();
    if(dp[j] > dp[i]+t+(j==n ? l : get<0>(V[j]))-end) {
      chmin(dp[j], dp[i]+t+(j==n ? l : get<0>(V[j]))-end);
      par[j] = i;
    }
  }
  // rep(i, n) {
  //   auto [begin, end, t, idx] = V[i];
  //   cout << begin << ' ' << end << ' ' << t << endk;
  // }
  // cout << dp << endk;
  cout << dp[n] << endk;
  {
    int tmp = n;
    vector<int> ans;
    do {
      if(tmp != n) ans.push_back(get<3>(V[tmp]));
      tmp = par[tmp];
    } while(tmp != -1);
    reverse(all(ans));
    cout << ans.size() << endk;
    for(int a: ans) cout << a+1 << ' ';
    cout << endk;
  }
  return 0;
}
