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
  int n, q; cin >> n >> q;
  vector<ll> L(n-1), R(n-1);
  vector<pair<ll, pair<int, int>>> A;
  rep(i, n-1) {
    cin >> L[i] >> R[i];
    R[i]++;
    A.push_back({L[i], {i, 1}});
    A.push_back({R[i], {i, -1}});
  }
  sort(all(A));
  vector<pair<ll, int>> Q(q);
  for(auto& [a, b]: Q) cin >> a >> b;
  vector<int> id(q);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    return Q[i] < Q[j];
  });
  set<pair<int, int>> st;
  rep(i, n) st.insert({i, i+1});
  int i = 0;
  // cout << A << endk;
  vector<int> ans(q);
  for(int cur: id) {
    auto [a, b] = Q[cur];
    while(i < A.size() && A[i].first <= a) {
      int id = A[i].second.first+1;
      auto itr = prev(st.upper_bound({id, 0}));
      // cout << st << endk;
      // cout << *itr << endk;
      assert(itr->first <= id && id <= itr->second);
      if(A[i].second.second == 1) {
        auto next = itr;
        next++;
        int l = itr->first;
        int r = next->second;
        st.erase(itr);
        st.erase(next);
        st.insert({l, r});
      } else {
        auto [l, r] = *itr;
        st.erase(itr);
        st.insert({l, id});
        st.insert({id, r});
      }
      i++;
    }
    auto itr = prev(st.upper_bound({b, 0}));
    ans[cur] = itr->second - itr->first;
  }
  rep(i, q) cout << ans[i] << endk;
  return 0;
}
