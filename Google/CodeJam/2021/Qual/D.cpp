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

int n, q;
int query(int i, int j, int k) {
  cout << i+1 << ' ' << j+1 << ' ' << k+1 << endl;
  int ret; cin >> ret;
  if(ret == -1) exit(0);
  return ret-1;
};
void solve() {
  vector<int> order;
  {
    int ret = query(0, 1, 2);
    set<int> st = {0, 1, 2};
    st.erase(ret);
    order.push_back(*st.begin());
    order.push_back(ret);
    order.push_back(*st.rbegin());
  }
  auto bsearch = [&](int i) {
    auto test = [&](int mid) {
      int ret = query(order[mid], i, order[mid+1]);
      if(ret == i) {
        return make_pair(true, true);
      } else if(ret == order[mid]) {
        return make_pair(false, false);
      } else if(ret == order[mid+1]) {
        return make_pair(true, false);
      } else {
        assert(false);
      }
    };
    int sz = order.size();
    int ok = -1, ng = sz;
    while(abs(ok-ng)>1) {
      int mid = (ok+ng)/2;
      if(mid == sz-1) {
        ok = mid;
        break;
      }
      auto ret = test(mid);
      if(ret.second) {
        ok = mid;
        break;
      } else {
        (ret.first ? ok : ng) = mid;
      }
    }
    return ok;
  };
  for(int i=3; i<n; i++) {
    int ret = bsearch(i);
    vector<int> next;
    for(int j=0; j<=ret; j++) next.push_back(order[j]);
    next.push_back(i);
    for(int j=ret+1; j<order.size(); j++) next.push_back(order[j]);
    order = next;
    // cout << order << endk;
  }
  assert(order.size() == n);
  rep(i, n) cout << order[i]+1 << ' ';
  cout << endl;
  // vector<int> ans(n);
  // rep(i, n) ans[order[i]] = i+1;
  // rep(i, n) cout << ans[i] << ' ';
  // cout << endl;
  int ret; cin >> ret;
  if(ret == -1) exit(0);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t >> n >> q;
  while(t--) solve();
  return 0;
}
