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
  int n, m, q; cin >> n >> m >> q;
  vector<int> W(n), V(n);
  vector<int> X(m);
  rep(i, n) cin >> W[i] >> V[i];
  rep(i, m) cin >> X[i];
  vector<int> id(n);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    return V[i] > V[j];
  });
  // cout << id << endk;
  while(q--) {
    int l, r; cin >> l >> r;
    l--;
    multiset<int> st;
    rep(i, m) if(i < l || r <= i) st.insert(X[i]);
    ll ans = 0;
    rep(i, n) {
      auto itr = st.lower_bound(W[id[i]]);
      if(itr != st.end()) {
        ans += V[id[i]];
        st.erase(itr);
      }
    }
    cout << ans << endk;
  }
  return 0;
}
