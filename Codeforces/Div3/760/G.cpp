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

void solve() {
  int n, m, q; cin >> n >> m >> q;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> B(m); rep(i, m) cin >> B[i];
  vector<pair<int, int>> C(n+m);
  rep(i, n) C[i] = {A[i], 1};
  rep(i, m) C[i+n] = {B[i], 0};
  sort(all(C));
  vector<ll> cum(n+m+1);
  rep(i, n+m) cum[i+1] = cum[i] + C[i].first;
  vector<int> K(q);
  rep(i, q) cin >> K[i];
  vector<int> id(q);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    return K[i] < K[j];
  });
  vector<ll> ans(q);
  vector<pair<ll, int>> Q;
  rep(i, n+m-1) Q.push_back({C[i+1].first-C[i].first, i});
  sort(all(Q));
  int l = 0;
  map<int, pair<int, int>> mp;
  rep(i, n+m) mp[i+1] = {1, C[i].second};
  ll val = accumulate(all(A), 0LL);
  for(int i: id) {
    while(l < n+m-1 && Q[l].first <= K[i]) {
      int tmp = Q[l].second+1;
      assert(mp.count(tmp));
      auto [a, b] = *mp.lower_bound(tmp);
      val -= cum[a]-cum[a-b.second];
      mp.erase(tmp);
      auto [c, d] = *mp.lower_bound(tmp);
      val -= cum[c]-cum[c-d.second];
      mp.erase(c);
      mp[c] = {d.first+b.first, d.second+b.second};
      val += cum[c]-cum[c-(d.second+b.second)];
      l++;
    }
    ans[i] = val;
  }
  rep(i, q) cout << ans[i] << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
