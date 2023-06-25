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
  vector<ll> B(n); rep(i, n) cin >> B[i];
  vector<ll> G(m); rep(i, m) cin >> G[i];
  ll bmax = *max_element(all(B));
  ll gmin = *min_element(all(G));
  if(bmax > gmin) {
    cout << -1 << endk;
    return 0;
  }
  multiset<ll> st;
  rep(i, m) st.insert(G[i]);
  vector<int> id(n);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    return B[i] > B[j];
  });
  ll ans = 0;
  for(int i: id) {
    ans += B[i];
    if(st.count(B[i])) {
      st.erase(st.find(B[i]));
    }
    int cnt = m-1;
    rep(j, m-1) {
      if(st.empty()) break;
      if(*st.rbegin() < B[i]) break;
      ans += *st.rbegin();
      st.erase(--st.end());
      cnt--;
    }
    ans += B[i] * cnt;
  }
  cout << ans << endk;
  return 0;
}
